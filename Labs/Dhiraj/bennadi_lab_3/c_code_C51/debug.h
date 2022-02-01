/*************************************************
 * @filename : debug.h
 * @author   : Dhiraj Bennadi
 * @compiler : arm
 * @IDE      : Code Blocks
 *
 * Identification of any leveraged code : None
 * Applicable Links: None
 */

 #ifndef DEBUG_H
 #define DEBUG_H

 #define DEBUG

 #ifdef DEBUG
 void dataout(uint16_t address, uint8_t value);

 #define DEBUGPORT(x,y)    dataout(x,y)
 #endif //DEBUG

 #endif // DEBUG_H


