/******************************************************************************
 * timers.c
 *  initializes timer routines
 *  Created on: Oct 1, 2021
 *      Author: Rajat
 *******************************************************************************/

#include "msp.h"


//refer spreadsheet for ticks calculation

#define PWM_PERIOD_FACTOR (12)
//Clock freq 3000000
//divider ID = 8, TAIDEX = 8
#define LED_TOGGLE_TIME_TICKS 14062                 //ticks equivalent for SMCLK /(8 * 8)
#define TIMER_A0_DEEBOUNCE_PERIOD_TICKS 936//234 //ticks equivalent for SMCLK /(8 * 8)
#define TIMER_A2_TEMPERATURE_READ_TICKS 9500//234 //ticks equivalent for SMCLK /(8 * 8)

static int pwm_duty_cycle = 55;

/*----------------------------------------------------------------------------
 * Initializes timers
 ----------------------------------------------------------------------------*/
void init_timer()
{

    //following timer is used for de-bounce logic. Ripples are being ignored.
    TIMER_A3->CCTL[0] = TIMER_A_CCTLN_CCIE; // TACCR0 Enable interrupt
    TIMER_A3->CCR[0] = TIMER_A0_DEEBOUNCE_PERIOD_TICKS;

    TIMER_A3->CTL = TIMER_A_CTL_SSEL__SMCLK | // SMCLK, up mode
    TIMER_A_CTL_MC__UP | TIMER_A_CTL_ID__8;

    TIMER_A3->EX0 = TIMER_A_EX0_TAIDEX_7;
    //enabling interrupt in NVIC
    NVIC->ISER[0] = 1 << ((TA3_0_IRQn) & 31);


    //following timer is used for Delays in temperature reads.
    TIMER_A2->CCTL[0] = TIMER_A_CCTLN_CCIE; // TACCR0 Enable interrupt
    TIMER_A2->CCR[0] = TIMER_A2_TEMPERATURE_READ_TICKS;

    TIMER_A2->CTL = TIMER_A_CTL_SSEL__SMCLK | // SMCLK, up mode
    TIMER_A_CTL_MC__UP | TIMER_A_CTL_ID__8;

    TIMER_A2->EX0 = TIMER_A_EX0_TAIDEX_7;
    //enabling interrupt in NVIC
    NVIC->ISER[0] = 1 << ((TA2_0_IRQn) & 31);


    //setting up pwm for RGB

    /* configure TimerA0.4 as PWM */
    TIMER_A0->CCR[0] = 50000-1;     /* PWM Period */

    TIMER_A0->CCR[2] = 500;         /* begin from 1% */
    TIMER_A0->CCTL[2] = 0xE0;//TIMER_A_CCTLN_OUTMOD_7;       /* CCR4 reset/set mode */

    TIMER_A0->CCR[3] = 500;         /* begin from 1% */
    TIMER_A0->CCTL[3] =TIMER_A_CCTLN_OUTMOD_7;       /* CCR4 reset/set mode */


    TIMER_A0->CCR[4] = 500;         /* begin from 1% */
    TIMER_A0->CCTL[4] =TIMER_A_CCTLN_OUTMOD_7;       /* CCR4 reset/set mode */

     TIMER_A0->CTL = TIMER_A_CTL_SSEL__SMCLK |  // SMCLK
            TIMER_A_CTL_MC__UP |              // Up-down mode
            TIMER_A_CTL_CLR;                // Clear TAR



    //setting up PWM on Pin P7.6
    TIMER_A1->CCR[0] = 1000 - 1;            // PWM Period
    TIMER_A1->CCTL[2] = TIMER_A_CCTLN_OUTMOD_7; // CCR2 reset/set
    TIMER_A1->CCR[2] = 550;                 // CCR2 PWM duty cycle
    TIMER_A1->CTL = TIMER_A_CTL_SSEL__SMCLK | // SMCLK
    TIMER_A_CTL_MC__UP |            // Up mode
    TIMER_A_CTL_CLR;                // Clear TAR

}

/*----------------------------------------------------------------------------
 * This function retrieves current PWM duty cycle on pin 7.6
 ----------------------------------------------------------------------------*/
int get_pwm_duty_cycle(void)
{
    return pwm_duty_cycle;
}

/*----------------------------------------------------------------------------
 * This function sts current PWM duty cycle on pin 7.6
 ----------------------------------------------------------------------------*/
void set_pwm_duty_cycle(int duty_cycle)
{
    pwm_duty_cycle = duty_cycle;
    TIMER_A1->CCR[2] = (pwm_duty_cycle * (TIMER_A1->CCR[0] + 1)) / 100;  //percentage to value
}


/*----------------------------------------------------------------------------
 * This function sets PWM period on pin 7.6
 ----------------------------------------------------------------------------*/
void set_pwm_period(int period)
{
    TIMER_A1->CCR[0] = period * PWM_PERIOD_FACTOR;
}

/*----------------------------------------------------------------------------
 * This function sets pwm on r g b pins
 ----------------------------------------------------------------------------*/
void led_pattern(int r, int g, int b)
{
    TIMER_A0->CCR[1] = r;
    TIMER_A0->CCR[2] = g;
    TIMER_A0->CCR[3] = b;

}

/*----------------------------------------------------------------------------
 * Simple loop delay
 ----------------------------------------------------------------------------*/
void delay()
{
    int i,j;
    for(i = 0; i< 1000; i++);

}
