/*************************************************
 * @filename : scheduler.c
 * @author   : Dhiraj Bennadi
 * @compiler : arm
 * @IDE      : Code Blocks
 *
 * Identification of any leveraged code : Code Referenced
 * from the example given by Prof. Linden Mcclure
 * Applicable Links: None
 */

 #include <stdint.h>
 #include "scheduler.h"
 #include "lcd.h"
 #include "displayclock.h"

bool Trigger100ms = false;
uint16_t tickCounter = 0;
bool tickIntTriggered = false;


/*
*@Function : tickScheduler
*@Brief    : Scheduler for update triggering 100ms task
*Parameters: None
*Returns   : None
*/
void tickScheduler(void)
{
  uint8_t isrCursorRestore = 0;

  isrCursorRestore = getCursorPointer();
  if(tickIntTriggered == true) {
    tickIntTriggered = false;
    if(tickCounter % 10 == 0) {
      Trigger100ms = true;
      Task100ms();
    }
  }

  setCursorPointer(isrCursorRestore);
}


/*
*@Function : Task100ms
*@Brief    : Task for 100ms 
*Parameters: None
*Returns   : None
*/
void Task100ms(void)
{
  if(Trigger100ms == true) {
    Trigger100ms = false;

    if(displayStatus)
    {
        updateClock();

    }
    displayClock();

  }
}
