/* --COPYRIGHT--,BSD_EX
 * Copyright (c) 2013, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 *******************************************************************************
 *
 *                       MSP432 CODE EXAMPLE DISCLAIMER
 *
 * MSP432 code examples are self-contained low-level programs that typically
 * demonstrate a single peripheral function or device feature in a highly
 * concise manner. For this the code may rely on the device's power-on default
 * register values and settings such as the clock configuration and care must
 * be taken when combining code from several examples to avoid potential side
 * effects. Also see http://www.ti.com/tool/mspdriverlib for an API functional
 * library & https://dev.ti.com/pinmux/ for a GUI approach to peripheral configuration.
 *
 * --/COPYRIGHT--*/
//******************************************************************************
//  MSP432P401 Demo - Software Port Interrupt Service on P1.1 from LPM4
//
//  Description: MSP432 device is configured to enter LPM4 mode with GPIOs
//  properly terminated. P1.1 is configured as an input. Pressing the button
//  connect to P1.1 results in device waking up and servicing the Port1 ISR.
//  LPM3 current can be measured when P1.0 is output low (e.g. LED off).
//
//  ACLK = 32kHz, MCLK = SMCLK = default DCO
//
//
//               MSP432P401x
//            -----------------
//        /|\|                 |
//         | |                 |
//         --|RST              |
//     /|\   |                 |
//      --o--|P1.1         P1.0|-->LED
//     \|/
//
//   Dung Dang
//   Texas Instruments Inc.
//   Oct 2016 (updated) | November 2013 (created)
//   Built with CCSv6.1, IAR, Keil, GCC
//******************************************************************************
#include "msp.h"

/*Global Variables Section*/
volatile int DelayCounter = 0;
volatile int ToggleFlag = 0;

/*
 * Initializes the Pins 1 and 2 on Port 2
 * for Green and Blue LEDs
 *
 * Parameters: None
 *
 * Returns: None
 */
void LED_Setup(void)
{
    /*Set Data Direction of Port 2 Pin 1*/
    P2->DIR |= BIT1;
    /*Set Output of Port 2 Pin 1*/
    P2->OUT |= BIT1;

    /*Set Data Direction of Port 2 Pin 2*/
    P2->DIR |= BIT2;
    /*Set Output of Port 2 Pin 2*/
    P2->OUT |= BIT2;
}
int main(void)
{
    // Hold the watchdog
    WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;

    /*Configuring P1.4 (switch) as input with pull-ip resistor*/
    P1->DIR = ~(uint8_t) BIT4;
    P1->OUT = BIT4;
    P1->REN = BIT4;                         // Enable pull-up resistor (P1.4 output high)


    /*Initialize Green and Blue LEDS*/
    LED_Setup();


    P1->SEL0 = 0;
    P1->SEL1 = 0;

    P1->IES = BIT4;                         // Interrupt on high-to-low transition

    P1->IFG = 0;                            // Clear all P1 interrupt flags

    P1->IE = BIT4;                          // Enable interrupt for P1.4

    // Enable Port 1 interrupt on the NVIC
    NVIC->ISER[1] = 1 << ((PORT1_IRQn) & 31);


    // Terminate all remaining pins on the device
    P2->DIR |= 0xFF; P2->OUT = 0;
    P3->DIR |= 0xFF; P3->OUT = 0;
    P4->DIR |= 0xFF; P4->OUT = 0;
    P5->DIR |= 0xFF; P5->OUT = 0;
    P6->DIR |= 0xFF; P6->OUT = 0;
    P7->DIR |= 0xFF; P7->OUT = 0;
    P8->DIR |= 0xFF; P8->OUT = 0;
    P9->DIR |= 0xFF; P9->OUT = 0;
    P10->DIR |= 0xFF; P10->OUT = 0;

    /*Turn ON the Green LED at Start*/
    P2->OUT |= BIT1;
    P2->OUT &= ~BIT2;

    // Configure Port J
    PJ->DIR |= (BIT0| BIT1 | BIT2 | BIT3);
    PJ->OUT &= ~(BIT0 | BIT1 | BIT2 | BIT3);

    // Enable PCM rude mode, which allows to device to enter LPM3 without waiting for peripherals
    PCM->CTL1 = PCM_CTL0_KEY_VAL | PCM_CTL1_FORCE_LPM_ENTRY;

    /*Configuration of Timer A*/
    TIMER_A0->CCTL[0] = TIMER_A_CCTLN_CCIE; // TACCR0 interrupt enabled

    TIMER_A0->CCR[0] = 0x1E78;
    TIMER_A0->CTL = TIMER_A_CTL_SSEL__SMCLK | // SMCLK, continuous mode , Frequency Divide
            TIMER_A_CTL_MC__CONTINUOUS | TIMER_A_CTL_ID_2;

    NVIC->ISER[0] = 1 << ((TA0_0_IRQn) & 31);


    // Enable global interrupt
    __enable_irq();

    // Setting the sleep deep bit
    SCB->SCR |= (SCB_SCR_SLEEPDEEP_Msk);

    // Do not wake up on exit from ISR
    SCB->SCR |= SCB_SCR_SLEEPONEXIT_Msk;

    // Ensures SLEEPONEXIT takes effect immediately
    __DSB();

    // Go to LPM4
    __sleep();
}

/* Port1 ISR */
void PORT1_IRQHandler(void)
{
    volatile uint32_t i;

    ToggleFlag ^= 1;

    // Delay for switch debounce
    for(i = 0; i < 10000; i++)
    {
        P1->IFG &= ~BIT4;
    }

}

/*Timer A ISR Hanlder*/
void TA0_0_IRQHandler(void) {

    TIMER_A0->CCTL[0] &= ~TIMER_A_CCTLN_CCIFG;


    /*If The Toggle is Set, the enable/disable of toggling stop*/
    if(ToggleFlag)
    {
        ;

    }
    else
    {
        /*Counter for a delay of 300ms*/
        if(DelayCounter == 29)
        {
            DelayCounter = 0;
            P2->OUT ^= BIT1;
            P2->OUT ^= BIT2;
        }
        DelayCounter++;
    }


    /*Reload the counter with 10ms delay*/
    TIMER_A0->CCR[0] += 0x1E78;


}
