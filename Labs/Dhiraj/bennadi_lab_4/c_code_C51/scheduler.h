/*************************************************
 * @filename : scheduler.h
 * @author   : Dhiraj Bennadi
 * @compiler : arm
 * @IDE      : Code Blocks
 *
 * Identification of any leveraged code : Code Referenced
 * from the example given by Prof. Linden Mcclure
 * Applicable Links: None
 */

#ifndef __SCHEDULER_H
#define __SCHEDULER_H

#include <stdbool.h>
#include <stdint.h>
void tickScheduler(void);
void Task100ms(void);

extern bool tickIntTriggered;
extern uint16_t tickCounter;

#endif
