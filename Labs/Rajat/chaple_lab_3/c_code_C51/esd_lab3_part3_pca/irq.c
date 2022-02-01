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

/** ------------------------------------------------------------------------------
 * @brief External interrupt
 * @param none
 * @return none
 ---------------------------------------------------------------------------------**/
void EXT_INT0_ISR (void) __interrupt 0
{
   PCON &= ~0x01;
}
