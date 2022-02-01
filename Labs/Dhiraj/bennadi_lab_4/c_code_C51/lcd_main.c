/*************************************************
 * @filename : main.c
 * @author   : Dhiraj Bennadi
 * @compiler : arm
 * @IDE      : Code Blocks
 *
 * Identification of any leveraged code : Code Referenced
 * from the example given by Prof. Linden Mcclure
 * Applicable Links: None
 */

#include <stdbool.h>
#include "supportFunctions.h"
#include <at89c51ed2.h>
#include <mcs51reg.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "lcd.h"
#include "scheduler.h"
#include "displayclock.h"
#include "delay.h"

#define PINTOGGLE P1_2

static void lcdStateMachine(void);


/*
*@Function : initTimerInterrupt
*@Brief    : Initialization of Interrupt
*Parameters: None
*Returns   : None
*/
void initTimerInterrupt(void)
{
  TMOD |= 0x01;
  IE |= 0x82;
  TL0 |= 0x00;
  TH0 |= 0xDC;
}


/*
*@Function : delayTimer0ISR
*@Brief    : ISR Routine
*Parameters: None
*Returns   : None
*/
void delayTimer0ISR(void) __interrupt(TF0_VECTOR)
{
  TL0 |= 0x00;
  TH0 |= 0xDC;
  tickIntTriggered = true;
  tickCounter++;
  TR0 = 1;
  PINTOGGLE ^= 1;
  tickScheduler();
}


/*
*@Function : main
*@Brief    : Entry Point to the program
*Parameters: None
*Returns   : None
*/
void main()
{
  lcd_init();


  while(1) {
    lcdStateMachine();
  }
}


/*
*@Function : lcdStateMachine
*@Brief    : State Machine to Handle LCD Operations
*Parameters: None
*Returns   : None
*/
static void lcdStateMachine(void)
{
  char string_value[10];
  char addr_value[10];
  uint8_t addrValue;
  char optionString[5];
  uint8_t optionVal;
  char currentCursorVal;
  char row_value[5];
  char col_value[5];
  uint8_t row;
  uint8_t column;
  uint8_t stringLength = 0;

  printf_tiny("Enter the option to select LCD commands\n\r");
  printf_tiny("1. Enter the data at the current cursor\n\r");
  printf_tiny("2. Enter the option to go to address\n\r");
  printf_tiny("3. Enter the option to go to x , y location\n\r");
  printf_tiny("4. Enter the option to input string\n\r");
  printf_tiny("5. Enter the option to clear LCD screen\n\r");
  printf_tiny("****************\n\r");
  printf_tiny("Enter the option to select display Clock commands\n\r");
  printf_tiny("6. Enter the option to reset the display clock\n\r");
  printf_tiny("7. Enter the option to stop the display clock\n\r");
  printf_tiny("8. Enter the option to start the display clock\n\r");
  printf_tiny("9. DDRAM Dump\n\r");
  printf_tiny("10. CGRAM Dump\n\r");
  printf_tiny("11. Custom Characters\n\r");
  printf_tiny("12. LOGO\n\r");
  printf_tiny("13. User Input\n\r");
  printf_tiny("****************\n\r");

  getstr(optionString);
  optionVal = atoi(optionString);
  putchar('\n');
  putchar('\r');

  switch(optionVal) {
  case 1:
    printf("Option entered to enter data\n\r");
    currentCursorVal = getchar();
    putchar(currentCursorVal);
    lcdputch(currentCursorVal);
    printf("User Entered = %c\n\r", currentCursorVal);

    break;

  case 2:
    printf("Enter the Address\n\r");
    getstr(addr_value);
    addrValue = (int)strtol(addr_value, NULL, 16);
    printf("Value Entered = %x\n\r", addrValue);
    if(checkaddressValue(addrValue))
    {
        lcdgotoaddr(addrValue);
        setCursorPointer(addrValue);
    }
    else
    {
       printf("Invalid address entered by the user\n\r");
    }

    break;

  case 3:
    printf("Option entered to go to user specified address\n\r");
    printf("Enter the value of x\n\r");
    getstr(row_value);
    row = atoi(row_value);
    printf("Enter the value of y\n\r");
    getstr(col_value);
    column = atoi(col_value);

    if((row == 3) && ((column > 3) && (column < 11))) {
      printf("Location used by Clock\n\r");
    }
    else{
      lcdgotoxy(row, column);
    }

    break;

  case 4:
    printf("Enter the String\n\r");
    getstr(string_value);
    stringLength = lcdputstr(string_value);
    printf("The user entered:\n\r");
    putstr(string_value);
    printf("\n\r");
    break;

  case 5:
    printf("Option entered to clear LCD screen\n\r");
    lcdclear();
    break;

  case 6:
      printf("Option entered to clear reset display Clock\n\r");
      resetDisplayClock();
    break;

  case 7:
    printf("Option Entered to stop the display clock\n\r");
    stopDisplayClock();
    break;

      case 8:
    printf("Option Entered to stop the display clock\n\r");
    startDisplayClock();
    break;

  case 9:
    printf("DDRAM Dump\n\r");
    hexdump_DDRAM();
  break;

  case 10:
    printf("CGRAM Dump\n\r");
    hexdump_CGRAM();
  break;

  case 11:
    printf("Printing Custom Character\n\r");
    createCustomCharacter();
  break;

  case 12:
    printf("Printing LOGO\n\r");
    createLogo();
  break;

  case 13:
    printf("Accepting User Input\n\r");
    userInput();
  break;

  }
}


