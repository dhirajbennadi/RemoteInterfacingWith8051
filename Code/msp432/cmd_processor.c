/***************************************************************************************
 * @file cmd_processor.c :
 * @brief : This file contains functions to perform lexical analysis to extract commands
 * 			over serial input and run respective handlers
 *
 * @author: Rajat Chaple
 ****************************************************************************************/

/*----------------Includes---------------*/
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "uart.h"
#include "cmd_processor.h"
#include "gpio.h"
#include "msp.h"
#include "spi.h"
#include "stdint.h"
#include "timers.h"
#include <string.h>
#include "lcd.h"


/*----------------Defines and variables----------*/
typedef enum command_hex_file_dump_e{
STATE_WAITING_FOR_START_FRAME,
STATE_HEX_FILE_DATA,
STATE_END_OF_FRAME
}command_hex_file_dump_t;

typedef enum programming_state_e{
    ENTER_BOOTLOADER,
    TRANSMIT_HEX_FILE,
    RESET_8051,
}programming_state_t;

command_hex_file_dump_t hex_file_dump_to_msp32_state = STATE_WAITING_FOR_START_FRAME;

char hex_file[50000];   //stores 50KB of hex file
static uint16_t hex_file_dump_index;


/*--------------------------------------------------------------------------------
* Receive hex file over UART2 usign ESP32
* SOF for each frame: $$$
* EOF: ###
--------------------------------------------------------------------------------*/
bool receive_hex_file(int c)
{
    static uint8_t SOF_count = 0;   //$$$
    static uint8_t EOF_count = 0;   //###
    bool hex_file_received_status = false;

    if(c == -1)
        return false;

    switch(hex_file_dump_to_msp32_state)
    {
    case STATE_WAITING_FOR_START_FRAME:

        if(c == '$')
        {
            SOF_count++;
            if(SOF_count == 3)  //$$$
            {
                hex_file_dump_to_msp32_state = STATE_HEX_FILE_DATA;
                SOF_count = 0;
                lcd_print_str("Receiving", "hex file");
            }
        }
        else
        {
            SOF_count = 0;
        }
        break;

    case STATE_HEX_FILE_DATA:
        if(c == '#')
        {
            EOF_count++;
            hex_file[hex_file_dump_index++] = '\0';
            hex_file_dump_to_msp32_state = STATE_END_OF_FRAME;

            break;
        }
        else if(c == '$')
        {
            SOF_count++;
            hex_file_dump_to_msp32_state = STATE_WAITING_FOR_START_FRAME;
            break;
        }
        else if(c == '+')
        {
            hex_file_dump_to_msp32_state = STATE_WAITING_FOR_START_FRAME;
            break;
        }
        else if(c == '\r' || c== '\n')
        {
            break;
        }
        hex_file[hex_file_dump_index++] = c;
        break;

    case STATE_END_OF_FRAME:
        if(c == '#')
        {
            EOF_count++;
            if(EOF_count == 2)
            {
                EOF_count = 0;
                hex_file_dump_index = 0;
                hex_file_received_status = true;
                putstr("\r\n\r\nReceived hex file: \r\n");
                lcd_print_str("Hex file", "Received");
                putstr(hex_file);
            }
        }
        else
        {
            EOF_count = 0;
        }
        break;
    }

    return hex_file_received_status;
}


/*--------------------------------------------------------------------------------
* Sending hex file to 8051
--------------------------------------------------------------------------------*/
void send_hex_file_to_8051()
{
    bool is_8051_programmed = false;
    programming_state_t programming_state = ENTER_BOOTLOADER;
    char* token;
    while(1)
    {
        switch(programming_state)
        {
        case ENTER_BOOTLOADER:
            putstr("\r\nEntering Bootloader...\r\n");
            lcd_print_str("8051: Entering", "Bootloader");
            enter_8051_into_bootloader();
            delay(100000);
            programming_state = TRANSMIT_HEX_FILE;
            break;

        case TRANSMIT_HEX_FILE:
            lcd_print_str("transferring", "HEX file");
            putstr("\r\nSending Hex file...\r\n");
            send_to_8051("U\0");
            delay(100000);
            /* get the first token */
            token = strtok(hex_file, ":");

            /* walk through other tokens */
            while( token != NULL ) {
               send_to_8051(":\0");
               send_to_8051(token);
               delay(200000);
               token = strtok(NULL, ":");
            }

             programming_state = RESET_8051;
            break;

        case RESET_8051:
            lcd_print_str("8051: Exiting", "Bootloader");
            putstr("\r\nResetting 8051...\r\n");
            reset_8051();
            is_8051_programmed = true;
            break;

        default:
            break;
        }

        if(is_8051_programmed == true)
        {
            putstr("\r\nDone programming\r\n");
            break;
        }
    }

    putstr("\r\n8051 programmed successfully\r\n");
    lcd_print_str("8051: Firmware", "flashed");

}

