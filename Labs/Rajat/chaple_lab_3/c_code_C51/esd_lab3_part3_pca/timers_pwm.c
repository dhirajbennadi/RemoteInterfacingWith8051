/***************************************************************************************
 * @file timers_pwm.c :
 * @brief : This file contains UART initialization and functions for UART handling
 *
 * @author : Rajat Chaple (rajat.chaple@colorado.edu)
 ****************************************************************************************/

/*---Includes---*/
#include <mcs51/at89c51ed2.h>
#include <mcs51/8051.h>
#include <stdint.h>
#include "uart.h"
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "queue.h"
/*---Defines---*/

/*---Variables---*/

/*----------------------------------------------------------------------------
 * Initializing PWM
 ----------------------------------------------------------------------------*/
void pwm_init()
{
    CMOD = 0x02;    //setting up PCA timer  FLK Periph / 2
    CL = 0x00;
    CH = 0x00;
    CCAP1L = 0x66;  //initial time is on time   40% of 255
    CCAP1H = 0x66;  //60% duty cycle
    CCAPM1 = 0x42;    //enabling PWM on pin p1.3
}
