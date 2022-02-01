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
#include "timers_pwm.h"



/******VARIABLES********/
extern char __sdcc_heap[];
extern const unsigned int __sdcc_heap_size;


/********************************************************************
This is an application entry point
*********************************************************************/
void main(void)
{
    char received_char = '`';
    volatile int i = 0;
    command_t cmd = NO_CMD;
    bool command_processed_status = false;


    // allocating heap size of 5000
    // printf_tiny("printf_tiny &heap 0x%x  ", (__xdata char *) __sdcc_heap);
    // printf_tiny("  &heap end 0x%x\r\n", (__xdata char *) (__sdcc_heap + __sdcc_heap_size-1));


    uart_init();
    pwm_init();

    //enabling external interrupt0
    IT0 = 1;
    EX0 = 1;
    EA = 1;



    putstr("\r\n----------------------------------------------------------------------\r\n\r\n");
    putstr("1. Run PWM\r\n2. Stop PWM\r\n3. Set FCLK PERIPH at the minimum frequency\r\n4. Set FCLK PERIPH at the maximum frequency\r\n5. Enter Idle mode \r\n6. Enter Power Down mode ");
    putstr("\r\n----------------------------------------------------------------------\r\n\r\n");
    putstr("Enter command: ");

    while (1)
    {

        received_char = getchar();
        DEBUGPORT(received_char);

        echo(received_char); // echoing characters back
        // processing the command
        command(received_char);
    }
}
