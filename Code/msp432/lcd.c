/*****************************************************************************************
 * @file lcd.c :
 * @brief : This file contains lcd routines
 *
 * @author : Dhiraj Bennadi
 * @date : Dec 6, 2021
 * @source: msp432 example code
******************************************************************************************/


#include "lcd.h"
#include "timers.h"

static int cursorPointer = 0x80;

void init_lcd(void) {
    P4->DIR = 0xFF;     /* make P4 pins output for data and controls */
    delayMs(30);                /* initialization sequence */
    LCD_nibble_write(0x30, 0);
    delayMs(10);
    LCD_nibble_write(0x30, 0);
    delayMs(1);
    LCD_nibble_write(0x30, 0);
    delayMs(1);
    LCD_nibble_write(0x20, 0);  /* use 4-bit data mode */
    delayMs(1);

    LCD_command(0x28);      /* set 4-bit data, 2-line, 5x7 font */
    LCD_command(0x06);      /* move cursor right after each char */
    LCD_command(0x01);      /* clear screen, move cursor to home */
    LCD_command(0x0F);      /* turn on display, cursor blinking */

    LCD_command(1);
    LCD_command(0x80);
}

/* With 4-bit mode, each command or data is sent twice with upper
 * nibble first then lower nibble.
 */
void LCD_nibble_write(unsigned char data, unsigned char control) {
    data &= 0xF0;           /* clear lower nibble for control */
    control &= 0x0F;        /* clear upper nibble for data */
    P4->OUT = data | control;       /* RS = 0, R/W = 0 */
    P4->OUT = data | control | EN;  /* pulse E */
    delayMs(0);
    P4->OUT = data;                 /* clear E */
    P4->OUT = 0;
}

void LCD_command(unsigned char command) {
    LCD_nibble_write(command & 0xF0, 0);    /* upper nibble first */
    LCD_nibble_write(command << 4, 0);      /* then lower nibble */

    if (command < 4)
        delayMs(4);         /* commands 1 and 2 need up to 1.64ms */
    else
        delayMs(1);         /* all others 40 us */
}

void LCD_data(unsigned char data) {

    LCD_nibble_write(data & 0xF0, RS);    /* upper nibble first */
    LCD_nibble_write(data << 4, RS);      /* then lower nibble  */
    updateCursorPointer();

    delayMs(1);
}

/* delay milliseconds when system clock is at 3 MHz */
void delayMs(int n) {
    int i, j;

    for (j = 0; j < n; j++)
        for (i = 750; i > 0; i--);      /* Delay */
}


void lcd_print_str(char *str1, char *str2)
{
    LCD_command(1);
    LCD_command(0x80);
    cursorPointer = 0x80;
    while(*str1 != '\0')
    {
        LCD_data(*str1++);
    }

    LCD_command(0xC0);
    cursorPointer = 0xC0;
    while(*str2 != '\0')
    {
        LCD_data(*str2++);
    }

    delay(100000);
}

void updateCursorPointer(void)
{
    int update = 0;

    if(cursorPointer == 0x8F)
    {
        cursorPointer = 0xC0;
        LCD_command(cursorPointer);
        update = 1;
    }
    if(cursorPointer == 0xCF)
    {
        cursorPointer = 0x80;
        LCD_command(cursorPointer);
        //LCD_command(1);
        update = 1;
    }
    if(update == 0)
    {
        cursorPointer++;
    }


}


