/*****************************************************************************************
 * @file debug.h :
 * @brief : This file contains defines, includes, and function prototypes for debug.c
 *
 * @author : Rajat Chaple (rajat.chaple@colorado.edu)
 * @date : Oct 13 2021
 *
 ******************************************************************************************/

#ifndef DEBUG_H_
#define DEBUG_H_

#include "stdint.h"
//#define DEBUG
#ifdef DEBUG
#define DEBUGPORT(x) dataout(0xFFFF,x); // generates a MOVX 0FFFFh,x where x is an 8-bit value
#else
#define DEBUGPORT(x) // empty statement, nothing passed on from the preprocessor to the compiler
#endif

/** ------------------------------------------------------------------------------
 *  @brief  Stores debug byte at particular location

 * @param 	:	none
 * @return number of bytes
 ---------------------------------------------------------------------------------**/
void dataout(uint16_t* address, uint8_t data);


#endif /* DEBUG_H_ */
