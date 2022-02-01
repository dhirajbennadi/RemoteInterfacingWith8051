/***************************************************************************************
 * @file main.c :
 * @brief : application entry point
 *
 * @author :Rajat Chaple
 ****************************************************************************************/

/**************Includes************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "cbfifo.h"
#include "msp.h"
#include "uart.h"
#include "cmd_processor.h"
#include "msp.h"
#include "gpio.h"
#include "spi.h"
#include "esp32.h"
#include "timers.h"
#include "lcd.h"

/*************Variables************/
extern cbfifo_t cbfifo_transmit_uart0;
extern cbfifo_t cbfifo_receive_uart0;
extern bool temp_ready_status;
extern bool generate_sine_wave_form;



/**=================================================================================
 * Application entry point
 ==================================================================================*/
void main(void)
    {

    bool is_hex_file_received;
    int8_t c;


    WDT_A->CTL = WDT_A_CTL_PW |             // Stop watchdog timer
            WDT_A_CTL_HOLD;

    //initiating system clock
    CS->KEY = CS_KEY_VAL;                   // Unlock CS module for register access
    CS->CTL0 = 0;                           // Reset tuning parameters
    CS->CTL0 = CS_CTL0_DCORSEL_3;           // Set DCO to 12MHz (nominal, center of 8-16MHz range)
    CS->CTL1 = CS_CTL1_SELA_2 |             // Select ACLK = REFO
            CS_CTL1_SELS_3 |                // SMCLK = DCO
            CS_CTL1_SELM_3;                 // MCLK = DCO
    CS->KEY = 0;                            // Lock CS module from unintended accesses


    init_gpio();
    uart_init();
    init_lcd();


    // Enable global interrupt
    __enable_irq();


    putstr("\r\n--------------------------------------------------------------------------------\r\n");
    putstr("Remote Interfacing with 8051...\r\n");

    lcd_print_str("8051 : Remote", "Interfacing");
    delay(4000000);

    lcd_print_str("Connecting to", "WIFI");
    esp_32_command(wifi_connect);
    lcd_print_str("WIFI Connected", "Starting server");
    esp_32_command(start_server);

    lcd_print_str("Server started","");
    putstr("Entering main while loop: Ready for receiving HEX file\r\n");
    while (1) {

        c = getchar();  //receive character from uart
        echo_uart2(c);  //send character to uart2 (esp32)
        c = getchar_uart2();
        echo(c);    //display character over uart0 console
        is_hex_file_received = receive_hex_file(c);
        if(is_hex_file_received == true)
        {
            send_hex_file_to_8051();
        }

    }


}
