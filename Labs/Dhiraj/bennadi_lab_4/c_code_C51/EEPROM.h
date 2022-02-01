/*************************************************
 * @filename : EEPROM.h
 * @author   : Dhiraj Bennadi
 * @compiler : arm
 * @IDE      : Code Blocks
 *
 * Identification of any leveraged code : Code Referenced
 * from the example given by Prof. Linden Mcclure
 * Applicable Links: None
 */


#include <stdbool.h>
#include <stdint.h>

int blockValueFromAddress(int hexValue);
void hexdumpAddress(unsigned int address1, unsigned int address2);
bool checkAddress(unsigned int address);
void resetSequence(void);