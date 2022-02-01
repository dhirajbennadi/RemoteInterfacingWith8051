/*****************************************************************************************
 * @file irq.c :
 * @brief : This file contains interrupt handlers for peripherals
 *
 * @author : Rajat Chaple (rajat.chaple@colorado.edu)
 * @date : Oct 14, 2021
 *
 ******************************************************************************************/
#include <mcs51/8051.h>
#include "uart.h"

char received_char;
/** ------------------------------------------------------------------------------
 * @brief UART0 IRQ handler for tranmit and receive
 * @param none
 * @return none
 ---------------------------------------------------------------------------------**/
void serial_isr(void) //__interrupt (4)

{

    if (RI == 1) // character received
    {
        received_char = SBUF;
        RI = 0;
    }
    else if (TI == 1) // character transmitted
    {
        TI = 0;
    }

    P1_1 = !P1_1; // Show the data has been updated
}
