/*******************************************************************
@brief: This demo code serial prints characters over Tx pins and also
toggles pin P1.1 (LED)
@uController : AT89C51RD2
@compiler : SSDC 3.9

@author: Rajat Chaple
 ******************************************************************/

 /********DEFINES********/
#define DEBUG 1

/******INCLUDES********/
#include <mcs51/8051.h>
#include <mcs51/at89c51ed2.h>
#include "uart.h"
#include "stdio.h"
#include "string.h"
#include "irq.h"
#include "stdlib.h"
#include "queue.h"
#include "debug.h"



/******VARIABLES********/
extern char __sdcc_heap[];
extern const unsigned int __sdcc_heap_size;

/********************************************************************
This is an application entry point
*********************************************************************/
_sdcc_external_startup()
{
    AUXR |= 0x0C; // 0000 1100

    return 0;
}

/********************************************************************
This is an application entry point
*********************************************************************/
void main(void)
{
    char received_char = '`';
    volatile int i = 0;
    command_t cmd = NO_CMD;
    bool command_processed_status = false;
    long total_characters_received = 0;
    long total_characters_received_since_last_query = 0;


    buffer_t buffers[MAX_NUM_OF_BUFFERS];

    // allocating heap size of 5000
    // printf_tiny("printf_tiny &heap 0x%x  ", (__xdata char *) __sdcc_heap);
    // printf_tiny("  &heap end 0x%x\r\n", (__xdata char *) (__sdcc_heap + __sdcc_heap_size-1));

    uart_init();

    memset(buffers, 0, sizeof(buffers));

    putstr("Specify buffer size (48 bytes to 4800 bytes in multiples of 16): ");
    buffers[0].buf_size = accept_number_from_user();
    buffers[1].buf_size = buffers[0].buf_size;

    while ((buffers[0].buf_size % 16 != 0) || (buffers[0].buf_size < 48) || (buffers[0].buf_size > 4800))
    {
        putstr("============================================================================\r\n");
        putstr("Invalid size entered\r\n");
        putstr("Specify buffer size (48 bytes to 4800 bytes in multiples of 16): ");
        buffers[0].buf_size = accept_number_from_user();
        buffers[1].buf_size = buffers[0].buf_size;
    }

    // allocating dynamic memory for buffer 0
    buffers[0].buffer_pointer = (uint8_t *)malloc(buffers[0].buf_size);
    if (buffers[0].buffer_pointer != NULL)
    {
        putstr("Success: malloc for buffer0 successful\r\n");
        buffers[0].buf_id = 0;
    }
    else
    {
        putstr("Error: malloc for buffer0 failed\r\n");
        // free(buffer0);
        return;
    }

    // allocating dynamic memory for buffer 1
    buffers[1].buffer_pointer = (uint8_t *)malloc(buffers[1].buf_size);
    if (buffers[1].buffer_pointer != NULL)
    {
        putstr("Success: malloc for buffer1 successful\r\n");
        buffers[1].buf_id = 1;
    }
    else
    {
        putstr("Error: malloc for buffer1 failed, clearing buffers\r\n");
        free(buffers[0].buffer_pointer);
        // free(buffer1);
        return;
    }

    putstr("\r\n----------------------------------------------------------------------\r\n\r\n");
    putstr("Enter command (+, -, ?, =, @) or input: ");

    while (1)
    {

        received_char = getchar();
        DEBUGPORT(received_char);

        //code to represent entered characters in readable form
        if (((received_char >= 'a') && (received_char <= 'z')))
            {
                if(buffers[0].buf_index % 40 == 0)
                putstr("\r\n\t\t");
            }

        echo(received_char); // echoing characters back
        total_characters_received++;
        total_characters_received_since_last_query++;
        // storing storage characters in buffer0
        if ((received_char >= 'a') && (received_char <= 'z'))
            buffers[0].buffer_pointer[buffers[0].buf_index++] = received_char;

        if (received_char == '?')
        {
            printf("\r\n\tTotal Characters received: %ld\r\n", total_characters_received);
            printf("\tTotal Characters received since last query: %ld\r\n", total_characters_received_since_last_query);
            total_characters_received_since_last_query = 0;
        }
        // processing the command
        command(received_char, buffers);
    }
}
