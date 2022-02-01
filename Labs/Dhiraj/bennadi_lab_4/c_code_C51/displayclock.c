/*************************************************
 * @filename : displayclock.c
 * @author   : Dhiraj Bennadi
 * @compiler : arm
 * @IDE      : Code Blocks
 *
 * Identification of any leveraged code : Code Referenced
 * from the example given by Prof. Linden Mcclure
 * Applicable Links: None
 */

#include <stdint.h>
#include <stdbool.h>
#include "displayclock.h"
#include "delay.h"
#include "lcd.h"

uint8_t minuteCounter = 0;
uint8_t secondsCounter = 0;
uint8_t secondsby10Counter = 0;
bool displayStatus = true;

/*
*@Function : updateClock
*@Brief    : Update Clock Counts
*Parameters: None
*Returns   : None
*/
void updateClock(void)
{
  secondsby10Counter++;

  if(secondsby10Counter == 10) {
    secondsby10Counter = 0;
    secondsCounter++;
  }

  if(secondsCounter == 60) {
    secondsCounter = 0;
    minuteCounter++;
  }

  if(minuteCounter == 60) {
    minuteCounter = 0;
    secondsCounter = 0;
    secondsby10Counter = 0;
  }
}


/*
*@Function : displayClock
*@Brief    : Display Clock Status
*Parameters: None
*Returns   : None
*/
void displayClock(void)
{
  uint8_t lusseconds = 0;
  uint8_t lussecondsHigherNibble = 0;
  uint8_t lussecondslowerNibble = 0;
  uint8_t lusminsHigherNibble = 0;
  uint8_t lusminslowerNibble = 0;

  lcdgotoxy(3, 15);
  lcdputch('0' + secondsby10Counter);
  lcdgotoxy(3, 14);
  lcdputch('.');

  if(secondsCounter <= 9) {
    lcdgotoxy(3, 13);
    lcdputch('0' + secondsCounter);
    lcdgotoxy(3, 12);
    lcdputch('0');
  } else {
    lcdgotoxy(3, 13);
    lussecondslowerNibble = secondsCounter % 10;
    lcdputch(lussecondslowerNibble + '0');
    lussecondsHigherNibble = secondsCounter / 10;
    lcdgotoxy(3, 12);
    lcdputch(lussecondsHigherNibble + '0');
  }

  lcdgotoxy(3, 11);
  lcdputch(':');

  if(minuteCounter <= 9) {
    lcdgotoxy(3, 10);
    lcdputch('0' + minuteCounter);
    lcdgotoxy(3, 9);
    lcdputch('0');
  } else {
    lcdgotoxy(3, 10);
    lusminslowerNibble = minuteCounter % 10;
    lcdputch(lusminslowerNibble + '0');
    lusminsHigherNibble = minuteCounter / 10;
    lcdgotoxy(3, 9);
    lcdputch(lusminsHigherNibble + '0');
  }

}


/*
*@Function : resetDisplayClock
*@Brief    : Resets Clock Status
*Parameters: None
*Returns   : None
*/
void resetDisplayClock(void)
{
    minuteCounter = 0;
    secondsby10Counter = 0;
    secondsCounter = 0;
}


/*
*@Function : stopDisplayClock
*@Brief    : Stop Display of the Clock Status
*Parameters: None
*Returns   : None
*/
void stopDisplayClock(void)
{
    displayStatus = false;
}


/*
*@Function : startDisplayClock
*@Brief    : Starts Display of the Clock Status
*Parameters: None
*Returns   : None
*/
void startDisplayClock(void)
{
   displayStatus = true;
}

