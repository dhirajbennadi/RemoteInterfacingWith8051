/*****************************************************************************************
 * @file debug.c :
 * @brief : This file contains debug function to write data at particular function
 *
 * @author : Rajat Chaple (rajat.chaple@colorado.edu)
 * @date : Oct 13 2021
 *
 ******************************************************************************************/

#include "debug.h"
/** ------------------------------------------------------------------------------
 *  @brief  Stores debug byte at particular location

 * @param 	:	none
 * @return number of bytes
 ---------------------------------------------------------------------------------**/
void dataout(uint16_t* address, uint8_t data)
{
    *address = data;
}


