/*************************************************
 * @filename : lcd.c
 * @author   : Dhiraj Bennadi
 * @compiler : arm
 * @IDE      : Code Blocks
 *
 * Identification of any leveraged code : Code Referenced
 * from the example given by Prof. Linden Mcclure
 * Applicable Links: None
 */

#include "lcd.h"
#include "delay.h"
#include <stdint.h>
#include <stdbool.h>
#include <at89c51ed2.h>
#include <mcs51reg.h>
#include <stdio.h>

#define RS P1_6
#define RW P1_7

#define ROW_0_ADDR 0x00
#define ROW_1_ADDR 0x40
#define ROW_2_ADDR 0x10
#define ROW_3_ADDR 0x50

#define PERIPHERAL_ADDR 0xF000

uint8_t currentCursorPointer = 0U;

__xdata uint16_t* PeripheralAddr = PERIPHERAL_ADDR;

/*
*@Function : lcdBusyWait
*@Brief    : This functions waits until the LCD Data Pin 7 is busy
*Parameters: None
*Returns   : None
*/
void lcdBusyWait()
{
  RS = 0;
  RW = 1;
  while(*PeripheralAddr & 0x80)
    ;
}


/*
*@Function : lcd_cmd
*@Brief    : Sends a command to the LCD
*Parameters: unsigned char
*Returns   : None
*/
void lcd_cmd(unsigned char command)
{
  RS = 0;
  RW = 0;
  *PeripheralAddr = command;
}

/*
*@Function : lcdgotoxy
*@Brief    : The cursor moves to the specified row and column
*Parameters: unsigned char, unsigned char
*Returns   : None
*/
void lcdgotoxy(unsigned char row, unsigned char column)
{
  uint8_t addr = 0;
  if(row == 0) {
    addr = ROW_0_ADDR + column;
  }
  if(row == 1) {
    addr = ROW_1_ADDR + column;
  }
  if(row == 2) {
    addr = ROW_2_ADDR + column;
  }
  if(row == 3) {
    addr = ROW_3_ADDR + column;
  }

  lcdgotoaddr(addr);
  setCursorPointer(addr);
}


/*
*@Function : lcdgotoaddr
*@Brief    : The cursor moves to the specified address
*Parameters: unsigned char, unsigned char
*Returns   : None
*/
void lcdgotoaddr(unsigned char addr)
{
  lcdBusyWait();
  lcd_cmd(addr | 0x80);
}


/*
*@Function : lcdputch
*@Brief    : Sends a character to the LCD
*Parameters: unsigned char
*Returns   : None
*/
void lcdputch(unsigned char disp_data)
{
  lcdBusyWait();
  RS = 1;
  RW = 0;
  *PeripheralAddr = disp_data;
  updateCursorPointer();
  lcdgotoaddr(currentCursorPointer);
}

/*
*@Function : delayNOP
*@Brief    : Software Delay function
*Parameters: int
*Returns   : None
*/
void delayNOP(int time)
{

    while(time--)
        __asm nop __endasm;
}


/*
*@Function : lcd_init
*@Brief    : Initialization of LCD Module
*Parameters: int
*Returns   : None
*/
void lcd_init()
{
  delayNOP(4000);
  lcd_cmd(0x30);
  delayNOP(2000);
  lcd_cmd(0x30);
  delayNOP(2000);
  lcd_cmd(0x30);
  delayNOP(1000);
  // for using 2 lines and 5X7 matrix of LCD
  lcd_cmd(0x38); 
  delayNOP(1);
  // turn display ON, cursor blinking
  lcd_cmd(0x0F); 
  delayNOP(1);
  lcd_cmd(0x01); // clear screen
  delayNOP(1);
  lcd_cmd(0x06); // bring cursor to position 1 of line 1
  delayNOP(1);
  lcdBusyWait();
}


/*
*@Function : lcdclear
*@Brief    : Clears the LCD Screen
*Parameters: int
*Returns   : None
*/
void lcdclear()
{
  lcd_cmd(0x01);
  setCursorPointer(0x00);
}


/*
*@Function : lcdputstr
*@Brief    : Sends a string to the LCD Module
*Parameters: char *
*Returns   : None
*/
int lcdputstr(char* ptr)
{
  uint8_t counter = 0;
  while(*ptr != '\r') {

    lcdputch(*ptr);
    ptr++;
    counter++;
  }

  return counter;
}


/*
*@Function : getCursorPointer
*@Brief    : Returns the current cursor pointer
*Parameters: char *
*Returns   : None
*/
uint8_t getCursorPointer(void)
{
  return currentCursorPointer;
}


/*
*@Function : setCursorPointer
*@Brief    : Sets the current cursor pointer
*Parameters: uint8_t
*Returns   : None
*/
void setCursorPointer(uint8_t cursorPointer)
{
  currentCursorPointer = cursorPointer;
  lcdgotoaddr(currentCursorPointer);
}


/*
*@Function : updateCursorPointer
*@Brief    : Updates the current cursor pointer
*Parameters: None
*Returns   : None
*/
void updateCursorPointer(void)
{
  bool updated = false;

  if(currentCursorPointer == 0x0F) {
    currentCursorPointer = 0x40;
    updated = true;
  }
  if(currentCursorPointer == 0x4F) {
    currentCursorPointer = 0x10;
    updated = true;
  }
  if(currentCursorPointer == 0x1F) {
    currentCursorPointer = 0x50;
    updated = true;
  }
  if(currentCursorPointer == 0x5F) {
    currentCursorPointer = 0x0;
    updated = true;
  }

  if(updated == false) {
    currentCursorPointer++;
  }

}


/*
*@Function : checkaddressValue
*@Brief    : Updates the current cursor pointer
*Parameters: unsigned char
*Returns   : None
*/
bool checkaddressValue(unsigned char addr)
{
    bool retVal = true;;
    #if 0
    int result;

    result = binarySearch(addressArray , 0 , 63, addr);

    if(result == -1)
    {
        retVal = false;
    }
    #endif

    return retVal;

}


/*
*@Function : read_DDRAMaddress
*@Brief    : Reads the value at the specified DDRAM Address
*Parameters: None
*Returns   : None
*/
int read_DDRAMaddress(void)
{
    lcdBusyWait();
    RS = 1;
    RW = 1;


    return (*PeripheralAddr & 0x7F); //0111 1111


}


/*
*@Function : hexdump_DDRAM
*@Brief    : Prints the Dump of DDRAM
*Parameters: None
*Returns   : None
*/
void hexdump_DDRAM()
{

    lcdBusyWait();


    int start_addr = 0x00;
    int end_addr = 0x5F;


    printf("\n\n\rDDRAM DUMP");
    printf("\n\r**************************************************************************\n");


    for(int i = start_addr;i<=end_addr;i++)
    {

        if(i == start_addr)
        {

            printf("\n\r%03x ",i);
        }
        else if( i %16 == 0)
        {
            printf("\n\r%03x ", i);
        }
        lcdBusyWait();
        RS = 0;

        RW = 0;

        *PeripheralAddr = i | 0x80;

        printf("\t%x",read_DDRAMaddress());
    }

    printf("\n\r");



}


/*
*@Function : read_CGRAMaddress
*@Brief    : Reads the value at the specified CGRAM Address
*Parameters: None
*Returns   : None
*/
int read_CGRAMaddress(void)
{
    lcdBusyWait();
    RS = 1;
    RW = 1;


    return (*PeripheralAddr & 0x3F); //0111 1111


}

/*
*@Function : hexdump_CGRAM
*@Brief    : Prints the Dump of CGRAM
*Parameters: None
*Returns   : None
*/
void hexdump_CGRAM(void)
{

    lcdBusyWait();

    int start_addr = 0x40;
    int end_addr = 0x7F;


    printf("\n\n\r CGRAM DUMP");
    printf("\n\r**************************************************************************\n");


    for(int i = start_addr;i<=end_addr;i++)
    {

        if(i == start_addr)
        {

            printf("\n\r%03x ",i);
        }
        else if( i %16 == 0)
        {
            printf("\n\r%03x ", i);
        }
        lcdBusyWait();
        RS = 0;

        RW = 0;

        *PeripheralAddr = i | 0x40;

        printf("\t%x",read_CGRAMaddress());
    }

    printf("\n\r");


}


/*
*@Function : lcd_cmdCGRAM
*@Brief    : Sends a command to the LCD Module
*Parameters: None
*Returns   : None
*/
void lcd_cmdCGRAM(unsigned char command)
{
  lcdBusyWait();
  RS = 0;
  RW = 0;
  uint8_t temp = command | 0x40;
  *PeripheralAddr = temp;
}


/*
*@Function : createCustomCharacter
*@Brief    : Creates a Custom Character
*Parameters: None
*Returns   : None
*/
void createCustomCharacter(void)
{
    uint8_t address[8] = {0x40,  0x48 , 0x50, 0x58, 0x60, 0x68, 0x70, 0x78};
    uint8_t data[8] = {0x11 , 0x11, 0x11, 0x11, 0x11, 0x11, 0x11 , 0x11};

    for(uint8_t i = 0; i < 8; i++)
    {

            lcd_cmdCGRAM(address[0] + i);
            lcdCGRAMData(data[i]);


    }
    lcdgotoaddr(0x00);
    lcdputch(0x00);



}


/*
*@Function : lcdCGRAMData
*@Brief    : Sends data to the CGRAM
*Parameters: unsigned char
*Returns   : None
*/
void lcdCGRAMData(unsigned char disp_data) // Function to send display data to LCD
{
  lcdBusyWait();
  RS = 1;
  RW = 0;
  *PeripheralAddr = disp_data;
}


/*
*@Function : createLogo
*@Brief    : Creates a LOGO of American Flag
*Parameters: None
*Returns   : None
*/
void createLogo(void)
{
    uint8_t display_addr = 0x00;
    uint8_t address[8] = {0x40,  0x48 , 0x50, 0x58, 0x60, 0x68, 0x70, 0x78};
    uint8_t stardata[8] = {0x15 , 0x0E, 0x1F, 0x0E, 0x15 , 0x00 , 0x00, 0x00};
    uint8_t stripesData[8] = {0x1F, 0x1F, 0x1F, 0x1F, 0x00 , 0x00, 0x00, 0x00 };

    for(uint8_t i = 0; i < 8; i++)
    {

        lcd_cmdCGRAM(address[0] + i);
        lcdCGRAMData(stardata[i]);

    }

    for(uint8_t i = 0; i < 5; i++)
    {
        lcdgotoaddr(i);
        lcdputch(0x00);

    }

    for(uint8_t i = 0; i < 5; i++)
    {
        lcdgotoaddr(0x40 + i);
        lcdputch(0x00);

    }

    for(uint8_t i = 0; i < 8; i++)
    {

        lcd_cmdCGRAM(address[1] + i);
        lcdCGRAMData(stripesData[i]);

    }

    for(uint8_t i = 5; i < 16; i++)
    {
        lcdgotoaddr(i);
        lcdputch(0x01);

    }

    for(uint8_t i = 5; i < 16; i++)
    {
        lcdgotoaddr(0x40 + i);
        lcdputch(0x01);

    }


    for(uint8_t i = 0; i < 16; i++)
    {
        lcdgotoaddr(0x10 + i);
        lcdputch(0x01);

    }

    for(uint8_t i = 0; i < 16; i++)
    {
        lcdgotoaddr(0x50 + i);
        lcdputch(0x01);

    }

    lcdgotoaddr(0x00);


}


/*
*@Function : userInput
*@Brief    : Accepts User Input to create a custom character
*Parameters: unsigned char
*Returns   : None
*/
void userInput(void)
{
    uint8_t address = 0x40;
    uint8_t userArray[8] = {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
    uint8_t userIp = 0;
    uint8_t finalValue = 0;
    uint8_t tempValue = 0;

    for(uint8_t i = 0; i < 8; i++)
    {
        for(uint8_t j = 0; j < 5; j++)
        {
            userIp = getchar();
            putchar(userIp);
            tempValue = ((userIp - 48)   << (4 - j)) & 0x1F;
            finalValue += tempValue;
            putchar('\t');
        }
        printf("Final = %d\n\r", finalValue);
        userArray[i] = finalValue;
        finalValue = 0;
        putchar('\n');
        putchar('\r');

    }

    for(uint8_t i = 0; i < 8; i++)
    {

        lcd_cmdCGRAM(address + i) ;
        printf("User Array = %d\n\r", userArray[i] & 0x1F);
        lcdCGRAMData(userArray[i]);

    }

    lcdgotoaddr(0x01);
    lcdputch(0x00);

    lcdgotoaddr(0x40);


}
