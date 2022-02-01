/*****************************************************************************************
 * @file irq.h :
 * @brief : This file contains defines, includes, and function prototypes for irq.c
 *
 * @author : Rajat Chaple (rajat.chaple@colorado.edu)
 * @date : Oct 13 2021
 *
 ******************************************************************************************/

#ifndef IRQ_H_
#define IRQ_H_

/** ------------------------------------------------------------------------------
 *  @brief      api for serial interrupt handler
 *
 * @param  none
 *
 * @return none
 ---------------------------------------------------------------------------------**/
void serial_isr(void);

#endif /* IRQ_H_ */
