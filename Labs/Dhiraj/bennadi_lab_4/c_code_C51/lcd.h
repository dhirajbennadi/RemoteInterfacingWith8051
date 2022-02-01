/*************************************************
 * @filename : lcd.h
 * @author   : Dhiraj Bennadi
 * @compiler : arm
 * @IDE      : Code Blocks
 *
 * Identification of any leveraged code : Code Referenced
 * from the example given by Prof. Linden Mcclure
 * Applicable Links: None
 */

#ifndef __LCD_H
#define __LCD_H

 #include <stdint.h>
 #include <stdbool.h>

void lcdgotoaddr(unsigned char addr);
void lcdgotoxy(unsigned char row, unsigned char column);
void lcdputch(unsigned char disp_data);
void setCursorPointer(uint8_t cursorPointer);
uint8_t getCursorPointer(void);
void updateCursorPointer(void);
void lcd_init(void);
void lcdclear(void);
int lcdputstr(char* ptr);
bool checkaddressValue(unsigned char addr);

void hexdump_DDRAM(void);

int read_CGRAMaddress(void);

void hexdump_CGRAM(void);

void createCustomCharacter(void);
void lcdCGRAMData(unsigned char disp_data);
void lcd_cmdCGRAM(unsigned char command);

void createLogo(void);

void userInput(void);
#define FIRST_LOCATION 0x00


#endif
