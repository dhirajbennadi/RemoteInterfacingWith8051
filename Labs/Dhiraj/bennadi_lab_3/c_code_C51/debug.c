/*************************************************
 * @filename : main.c
 * @author   : Dhiraj Bennadi
 * @compiler : arm
 * @IDE      : Code Blocks
 *
 * Identification of any leveraged code : None
 * Applicable Links: None
 */


 #include <stdint.h>
 #include "debug.h"


 void dataout(uint16_t address, uint8_t value)
 {

     __xdata uint8_t* ptr = (__xdata uint8_t*) address;

     *ptr = value;
 }
