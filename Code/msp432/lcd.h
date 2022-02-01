/*****************************************************************************************
 * @file lcd.h :
 * @brief : This file contains header files for
 *
 * @author : Dhiraj Bennadi
 * @date : Dec 6, 2021
 * @source: msp432 example code
******************************************************************************************/

#ifndef LCD_H_
#define LCD_H_


#include "msp432.h"

#define RS 1     /* P4.0 mask */
#define RW 2     /* P4.1 mask */
#define EN 4     /* P4.2 mask */

void delayMs(int n);
void LCD_nibble_write(unsigned char data, unsigned char control);
void LCD_command(unsigned char command);
void LCD_data(unsigned char data);
void init_lcd(void);
void lcd_print_str(char *str1, char *str2);
void updateCursorPointer(void);


#endif /* LCD_H_ */
