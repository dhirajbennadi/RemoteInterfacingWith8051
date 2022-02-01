/*************************************************
 * @filename : displayclock.h
 * @author   : Dhiraj Bennadi
 * @compiler : arm
 * @IDE      : Code Blocks
 *
 * Identification of any leveraged code : Code Referenced
 * from the example given by Prof. Linden Mcclure
 * Applicable Links: None
 */

#ifndef __DISPLAY_CLOCK_H
#define __DISPLAY_CLOCK_H

#include <stdint.h>
#include <stdbool.h>
void updateClock(void);
void displayClock(void);
void resetDisplayClock(void);
void stopDisplayClock(void);
void startDisplayClock(void);

extern bool displayStatus;

#endif // __DISPLAY_CLOCK_H
