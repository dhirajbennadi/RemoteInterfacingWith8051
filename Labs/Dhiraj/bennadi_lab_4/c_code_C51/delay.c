/*************************************************
 * @filename : delay.h
 * @author   : Dhiraj Bennadi
 * @compiler : arm
 * @IDE      : Code Blocks
 *
 * Identification of any leveraged code : Code Referenced
 * from the example given by Prof. Linden Mcclure
 * Applicable Links: None
 */

#include <stdint.h>
#include "delay.h"

#define DELAY_UNITS     1275

 /*
*@Function : msdelay
*@Brief    : Software Delay
*Parameters: None
*Returns   : None
*/
void msdelay(unsigned int time)
{
  unsigned i, j;
  for(i = 0; i < time; i++)
    for(j = 0; j < DELAY_UNITS; j++)
      ;
}
