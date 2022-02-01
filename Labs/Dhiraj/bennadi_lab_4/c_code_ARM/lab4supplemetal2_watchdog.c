
/*Title: Embedded System Design ECEN 5613*/
/*Submitted by: Dhiraj Bennadi*/

/*Program to Toggle the on board RED LED at 300ms using Timer A Interrupt*/
#include "msp.h"
#include <stdbool.h>
/*Global Variables Section*/
/*Counter to generate a delay of 300ms*/
volatile int DelayCounter = 0;

volatile bool intTriggered = false;

/*
*@Function : main
*@Brief    : Entry Point to the Program
*Parameters: None
*Returns   : None
*/
int main(void) {
    // Configure the watchdog timer to timeout every ~175ms
    WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_IS_3;

    /*Configure Port 1 Pin 0 as Output Pin*/
    /*This pin is internally connected to the RED LED*/
    P1->DIR |= BIT0;
    P1->OUT ^= BIT0;

    /*To measure the frequency of the pin toggling on Oscilloscope*/
    /*Configure Port 2 Pin 5 as Output Pin*/
    P2->DIR |= BIT2;
    P2->OUT &= ~BIT2;

    TIMER_A0->CCTL[0] = TIMER_A_CCTLN_CCIE; // TACCR0 interrupt enabled

    /*Count Value for a Delay of 10ms*/
    TIMER_A0->CCR[0] = 0x1E78;
    TIMER_A0->CTL = TIMER_A_CTL_SSEL__SMCLK | // SMCLK, continuous mode
            TIMER_A_CTL_MC__CONTINUOUS | TIMER_A_CTL_ID_2;


    SCB->SCR |= SCB_SCR_SLEEPONEXIT_Msk;    // Enable sleep on exit from ISR

    // Ensures SLEEPONEXIT takes effect immediately
    __DSB();

    // Enable global interrupt
    __enable_irq();

    NVIC->ISER[0] = 1 << ((TA0_0_IRQn) & 31);

    while (1)
    {
        __sleep();
        __no_operation();
    }
}

/*
*@Function : TA0_0_IRQHandler
*@Brief    : Timer A ISR Routine
*Parameters: None
*Returns   : None
*/
void TA0_0_IRQHandler(void) {

    TIMER_A0->CCTL[0] &= ~TIMER_A_CCTLN_CCIFG;

    /*Check if a delay of 300ms is generated*/
    if(DelayCounter == 15)
    {
        /*Reinitialize the counter to 0*/
        DelayCounter = 0;

        /*Toggle Port 2 Bit 5 to measure on oscilloscope*/
        P2->OUT ^= BIT2;

        /*Servicing the Watchdog Timer*/
        WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_CNTCL;
    }
    /*Incrementing the Counter every 10ms*/
    DelayCounter++;

    /*Reload the value with a 10ms delay in the Compare Register*/
    TIMER_A0->CCR[0] += 0x1E78;
}


