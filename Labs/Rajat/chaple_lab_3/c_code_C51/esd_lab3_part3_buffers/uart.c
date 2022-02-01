/***************************************************************************************
 * @file uart.c :
 * @brief : This file contains UART initialization and functions for UART handling
 *
 * @author : Rajat Chaple (rajat.chaple@colorado.edu)
 ****************************************************************************************/

/*---Includes---*/
#include <mcs51/8051.h>
#include <stdint.h>
#include "uart.h"
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "queue.h"
/*---Defines---*/
#define BACKSPACE '\b'
#define XON 0x11
#define XOFF 0x13

/*---Variables---*/

int buf_number = 0;
int total_malloced_data = 0;
extern const unsigned int __sdcc_heap_size;

/*----------------------------------------------------------------------------
 * Initializing UART
 * (refer uart.h for additional details)
 *  Registers used:
    SCON    : SM0 SM1 SM2  REN TB8 RB8 TI  RI
            :  0   1   0   1   0   0   0   0

    TMOD    :      TIMER1    /   TIMER2
            :  G   C/t M1  M0  G   C/t M1  M0      //t = !T
            :  0   0   1   0   0   0   0   0

    TH1     :   FD  -   9600
            :   FA  -   4800
            :   F4  -   2400
            :   E8  -   1200

 ----------------------------------------------------------------------------*/
void uart_init()
{
    SCON = 0x50; // setting up serial configuration 8bit uart, Receive enabled
    TMOD = 0x20; // timer1 in mode2, auto-reload
    // TH1 = 0xFD;     //baud rate = 9600
    // TR1 = 1;        //start timer
    // ES = 1;         //serial interrupt enabled
    // EA = 1;         //global interrupt enabled
    TI = 1;
    P1_1 = false;
}

/*----------------------------------------------------------------------------
 * This function echoes back characters to serial output
 * (refer uart.h for additional details)
 ----------------------------------------------------------------------------*/
void echo(char c)
{

    // putchar(c);
    switch ((int8_t)c)
    {
    case -1:
        break;

    case BACKSPACE: // user presses backspace
        putchar(BACKSPACE);
        putchar(' ');
        putchar(BACKSPACE);
        break;

    case '\r': // user presses enter
        putchar('\r');
        putchar('\n');
        break;

    default:
        putchar(c); // echoing received chars
        break;
    }
}

/*----------------------------------------------------------------------------
 * This function forms a line of command as characters are entered over serial
 * (refer uart.h for additional details)
 ----------------------------------------------------------------------------*/
void command(char received_char, buffer_t *buffers)
{
    uint16_t new_buff_size;
    uint16_t buffer_to_be_deleted;
    uint16_t new_buff_id = 0;

    if ((received_char >= 'a') && (received_char <= 'z')) // since small letter characters are storage characters and not command characters
        return;

    switch (received_char)
    {

        // command character for adding buffer
    case '+':
        total_malloced_data = 0;
        for(int iBuffer = 0; iBuffer < MAX_NUM_OF_BUFFERS; iBuffer++)
        {
            total_malloced_data += buffers[iBuffer].buf_size;
        }
        putstr("\r\n\r\n\t *** Command for adding a buffer ***\r\n");
        putstr("\r\n\t\b> Specify buffer size to be allocated (30 bytes to 300 bytes): ");
        new_buff_size = accept_number_from_user();
        total_malloced_data += new_buff_size;




        if ((new_buff_size < 30) || (new_buff_size > 300))
        {
            putstr("\t Error: Invalid size");
            putstr("\r\n\t - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -");
            command('+', buffers); // accepting size again
        }
        else if(total_malloced_data > __sdcc_heap_size)
        {
            putstr("\t Error: Out of memory, free some buffers to continue");
            break;
        }
        else
        {
            // allocating new buffer
            for (int i = 2; i < MAX_NUM_OF_BUFFERS; i++)
            {
                if (buffers[i].buffer_pointer == 0)
                {
                    new_buff_id = i;
                    break;
                }
                if (i == MAX_NUM_OF_BUFFERS - 1)
                {
                    putstr("\tError: buffer could not be added\r\n");
                    break;
                }
            }

            buffers[new_buff_id].buffer_pointer = (char *)malloc(sizeof(char) * new_buff_size);
            if (buffers[new_buff_id].buffer_pointer == NULL)
            {
                putstr("\tError: Failed allocating memory\r\n");
                break;
            }
            else
            {
                putstr("\tNew buffer has been created\r\n");
            }

            buffers[new_buff_id].buf_id = new_buff_id;
            buffers[new_buff_id].buf_size = new_buff_size;
            buffers[new_buff_id].buf_index = 0;

            // for(int i = 0; i < MAX_NUM_OF_BUFFERS; i++)
            {
                printf_tiny("\r\n\r\n\t\t-------------------------");
                printf_tiny("\r\n\t\t|buffer id|\tsize\t|");
                printf_tiny("\r\n\t\t-------------------------");
                for (int i = 0; i < MAX_NUM_OF_BUFFERS; i++)
                {
                    if ((buffers[i].buffer_pointer != 0) || (i == 0) || (i == 1))
                    {
                        printf_tiny("\r\n\t\t|    %d    |\t%d\t|", buffers[i].buf_id, buffers[i].buf_size);
                        if (buffers[i].buf_id == new_buff_id)
                            putstr(" <----- Newly added");
                    }
                }
                printf_tiny("\r\n\t\t-------------------------\r\n");
            }
        }

        break;

        // command character for removing buffer
    case '-':
        putstr("\r\n\r\n\t *** Command for removing a buffer ***\r\n");
        print_buffers(buffers);
        putstr("\r\n\t\b> Specify buffer to be delated (select id from the list): ");
        buffer_to_be_deleted = accept_number_from_user();
        for (int i = 2; i < MAX_NUM_OF_BUFFERS; i++)
        {
            if (buffer_to_be_deleted == buffers[i].buf_id)
            {
                free(buffers[i].buffer_pointer);
                buffers[i].buffer_pointer = 0;
                buffers[i].buf_id = -1;
                buffers[i].buf_index = 0;
                buffers[i].buf_size = 0;
            }
        }
        print_buffers(buffers);
        break;

        // command character for query
    case '?':
        putstr("\r\n\r\n\t *** Command for a query ***\r\n");
        printf_tiny("\r\n\r\n\t\t-----------------------------------------------------------------");
        putstr("\r\n\t\t| Buffer id | start-addr | end-addr | nStorageChar | free-space |\t\r\n");
        for (int i = 0; i < MAX_NUM_OF_BUFFERS; i++)
        {
            /*printf("\tBuffer id:%d\tstart-addr:%p\tend-addr:%p\tnStorageChar:%d\tfree-space:%d bytes\r\n", \
                      socket_server_data_ptr->buf_id, &(socket_server_data_ptr->buffer_pointer[0]), &(socket_server_data_ptr->buffer_pointer[socket_server_data_ptr->buf_size - 1]), \
                      socket_server_data_ptr->buf_index, (socket_server_data_ptr->buf_size - socket_server_data_ptr->buf_index));*/
            if ((buffers[i].buffer_pointer != 0) || (i == 0) || (i == 1))
            {
                printf_tiny("\r\n\t\t-----------------------------------------------------------------");
                printf("\r\n\t\t|%10d |   %11p |%9p |%13d |%11d |",
                       buffers[i].buf_id, &(buffers[i].buffer_pointer[0]), &(buffers[i].buffer_pointer[buffers[i].buf_size - 1]),
                       buffers[i].buf_index, (buffers[i].buf_size - buffers[i].buf_index));
            }
        }
        printf_tiny("\r\n\t\t-----------------------------------------------------------------\r\n");

        printf("\r\n\r\n\tBuffer 0 contents: \r\n\r\n");
        for (int iBuffer0 = 0; iBuffer0 < buffers[0].buf_index; iBuffer0++)
        {
            if (iBuffer0 % 64 == 0)
                printf("\r\n\t\t");
            printf("%c", buffers[0].buffer_pointer[iBuffer0]);
        }
        // memset(&buffers[0], 0, buffers[0].buf_index);
        buffers[0].buffer_pointer[0] = '\0';
        buffers[0].buf_index = 0;
        break;

        // command character for query
    case '=':
        putstr("\r\n\r\n\t *** Command for a hexdump ***\r\n");
        hexdump(buffers[0].buffer_pointer, buffers[0].buf_index);
        break;

    case '@':
        // freeing memory
        putstr("\r\n\r\n\t *** Command for freeing memory ***\r\n");
        for (int iBuffer = 0; iBuffer < MAX_NUM_OF_BUFFERS; iBuffer++)
        {
            if (buffers[iBuffer].buffer_pointer != 0)
                free(buffers[iBuffer].buffer_pointer);
        }
        printf("\r\n\r\n\t\tMemory has been freed\r\n\r\n");
        putstr("\r\n----------------------------------------------------------------------\r\n\r\n");
        putstr("\r\n----------------------------------------------------------------------\r\n\r\n");
        main();
        break;

        // append characters to command line string
    default:
        printf("\r\n\r\n\t Error: Received invalid command '%c'\r\n", received_char);
        // putstr("-----------------------------------------------------\r\n");
        // putstr("\r\nEnter command again (+, -, ?, =): ");
        break;
    }

    putstr("\r\n----------------------------------------------------------------------\r\n\r\n");
                putstr("Enter command (+, -, ?, =, @) or input: ");

}

/********************************************************************
This function prints characters out over serial
*********************************************************************/
int putchar(int c)
{
    while (!TI)
        ; // waiting for Transmit to be ready
    TI = 0;
    SBUF = c; // adding character to Serial buffer
    return c;
}

/********************************************************************
This function gets characters in from serial
*********************************************************************/
/*char getchar()
{
    return received_char;
}*/
int getchar() // Function to receive serial data
{
    P1_1 = false;
    while (!RI)
        ;
    // while((SCON & 0x01) == 0);
    RI = 0;

    P1_1 = true;
    return SBUF;
}

/********************************************************************
// putstr takes a string (char array) and prints till it finds a NULL.
// Returns length of printed string with null char
*********************************************************************/
int putstr(char *str)
{
    int index = 0;
    while (*str)
    { // output characters until NULL found
        putchar(*str++);
        index++;
    }
    return index + 1;
}

/********************************************************************
// receive a number from user input
// Returns length of printed string with null char
*********************************************************************/
int accept_number_from_user()
{
    char received_char = '`';
    char number_in_char[25] = "\0";
    bool valid_number_status = false;
    int number = 0;
    int i = 0;
    while (valid_number_status == false)
    {
        received_char = getchar();
        i++;
        echo(received_char);
        // if(received_char is in range of allowable values) //sanity check for alphabetical chars
        if (!(received_char >= '0' && received_char <= '9') && (received_char != '\r'))
        {
            valid_number_status == false;
            memset(number_in_char, 0, sizeof(number_in_char));
            putstr("\r\n\t\t Error: Re-enter the number: ");
            i = 0;

        }
        //     proceed
        else if (received_char == '\r')
        {
            strcat(number_in_char, '\0');
            number = atoi(number_in_char);
            valid_number_status = true;
            //return number;
        }
        strncat(number_in_char, &received_char, 1);

        if (i >= 24)
        {
            putstr("\r\n\t\t Error: Reading a number failed, Reached maximum length supported");
            putstr("\r\n\t\t Error: Re-enter the number: ");
            valid_number_status == false;
            memset(number_in_char, 0, sizeof(number_in_char));
            i = 0;
        }
    }
    return number;
}

/********************************************************************
// print buffers
*********************************************************************/
void print_buffers(buffer_t *buffers)
{
    printf_tiny("\r\n\r\n\t\t-------------------------");
    printf_tiny("\r\n\t\t| buffer id |\tsize\t|");
    printf_tiny("\r\n\t\t-------------------------");
    for (int i = 0; i < MAX_NUM_OF_BUFFERS; i++)
    {
        if ((buffers[i].buffer_pointer != 0) || (i == 0) || (i == 1))
            printf_tiny("\r\n\t\t|    %d    |\t%d\t|", buffers[i].buf_id, buffers[i].buf_size);
    }
    printf_tiny("\r\n\t\t-------------------------\r\n");
}

/** -------------------------------------------------------------------------------------------
 * @brief returns memory data (HEX) of given size from mentioned starting location
 *-------------------------------------------------------------------------------------------- **/
void hexdump(const void *loc, long nbytes)
{
    const char *loc_pointer = loc;
    char hex_byte[5] = "FF";
    char address_bytes[7] = "0x0000";
    int num = *loc_pointer;
    int total_chars_in_output_string = 0;
    //(nbytes*3)    -> 2 chars representation + space
    //(nbytes/16 + ((nbytes % 16) > 0)) is to calculate number of lines in output
    total_chars_in_output_string = (nbytes * 3) + (nbytes / 16 + ((nbytes % 16) > 0)) * 7 + 1;

    if (nbytes == 0)
    {
        printf("\r\n\r\n\t\tNo stored characters in the buffer\r\n");
        return;
    }
    printf_tiny("\r\n\r\n\t\t|=======================================================");

    for (int i = 0; i < nbytes; i++)
    {
        if (i % 16 == 0) // 16 bytes per line
        {

            uint_to_hexstr(address_bytes, sizeof(address_bytes), (uint16_t)loc_pointer + i, 16); // Converting offset address to hec string
            printf("|\r\n\t\t| ");

            for (int j = 2; j < 6; j++) // Adding offset in bytes from loc
            {
                printf("%c", address_bytes[j]);
            }
            // str[counter++] = ' ';
            printf(": ");
        }
        num = *loc_pointer;
        uint_to_hexstr(hex_byte, sizeof(hex_byte), num, 8); // conveting each character to hex string
        printf("%c", hex_byte[2]);
        printf("%c", hex_byte[3]);
        printf(" ");
        loc_pointer++;
    }
    printf_tiny("\r\n\t\t|=======================================================|\r\n");
}

/** -------------------------------------------------------------------------------------------
 * @brief Converts unsigned integer to hexadecimal string
 *-------------------------------------------------------------------------------------------- **/
int uint_to_hexstr(char *str, long size, uint16_t num, uint8_t nbits)
{
    int rem = 0;
    int total_chars = 0;

    // nbits value shall be 4,8,16 or 32 to be represented in nibbles
    if ((nbits != 4) && (nbits != 8) && (nbits != 16) && (nbits != 32))
    {
        str[0] = '\0';
        return -1;
    }

    total_chars = nbits / 4 + 3; // Every nibble requires 4 chars for representation AND +2 for 0x and +1 for \0

    // Valid inputs check for enough str size and total_chars
    if (total_chars > size)
    {
        str[0] = '\0';
        return -1;
    }

    str[0] = '0';
    str[1] = 'x';
    str[total_chars] = '\0';

    // Converting each character into hex
    for (int i = total_chars - 2; i > 1; i--)
    {
        rem = num % 16;
        if (rem < 10)
        {
            str[i] = '0' + rem;
        }
        else
        {
            str[i] = 'A' + (rem % 10);
        }
        num = num / 16;
    }

    return total_chars - 1;
}
