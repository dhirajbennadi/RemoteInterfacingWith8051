/*************************************************
 * @filename : main.c
 * @author   : Dhiraj Bennadi
 * @compiler : arm
 * @IDE      : Code Composer Studio
 *
 * Identification of any leveraged code : None
 * Applicable Links: None
 */

/*UART Polling*/
#include "msp.h"
#include "cbfifo.h"
#include <stdbool.h>
#include <stdio.h>

char ReceivedCharacter = '\0';

char *ptrCounter = NULL;

char ptr[1000] = "Welcome to Lab 3 Part 3 Signoff, My name is Dhiraj Bennadi, I will be giving my signoff to Alex Fritz \
        A universal asynchronous receiver-transmitter (UART) is a computer hardware device for\
        asynchronous serial communication in which the data format and transmission speeds are\
        configurable. It sends data bits one by one, from the least significant to the most significant,\
        framed by start and stop bits so that precise timing is handled by the communication channel.\
        The electric signaling levels are handled by a driver circuit external to the UART\
        Embedded systems often require communication between integrated circuits.\
        An example would be a digital temperature sensor reporting the ambient temperature of the room\
        to the the main microprocessor.This data is often transmitted over a serial interface.\
        So what is a serial interface?  At a very basic level, a serial interface is a shift";

char ptr2[1000] = "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzz\
zzzzzzzzzzzzzzzzzzzzzzzzzzzzzz\
zzzzzzzzzzzzzzzzzzzzzzzzzzzzzz\
zzzzzzzzzzzzzzzzzzzzzzzzzzzzzz\
zzzzzzzzzzzzzzzzzzzzzzzzzzzzzz\
zzzzzzzzzzzzzzzzzzzzzzzzzzzzzz\
zzzzzzzzzzzzzzzzzzzzzzzzzzzzzz\
zzzzzzzzzzzzzzzzzzzzzzzzzzzzzz\
zzzzzzzzzzzzzzzzzzzzzzzzzzzzzz\
zzzzzzzzzzzzzzzzzzzzzzzzzzzzzz\
zzzzzzzzzzzzzzzzzzzzzzzzzzzzzz\
zzzzzzzzzzzzzzzzzzzzzzzzzzzzzz\
zzzzzzzzzzzzzzzzzzzzzzzzzzzzzz\
zzzzzzzzzzzzzzzzzzzzzzzzzzzzzz\
zzzzzzzzzzzzzzzzzzzzzzzzzzzzzz\
zzzzzzzzzzzzzzzzzzzzzzzzzzzzzz\
zzzzzzzzzzzzzzzzzzzzzzzzzzzzzz\
zzzzzzzzzzzzzzzzzzzzzzzzzzzzzz\
zzzzzzzzzzzzzzzzzzzzzzzzzzzzzz\
zzzzzzzzzzzzzzzzzzzzzzzzzzzzzz\
zzzzzzzzzzzzzzzzzzzzzzzzzzzzzz\
zzzzzzzzzzzzzzzzzzzzzzzzzzzzzz\
zzzzzzzzzzzzzzzzzzzzzzzzzzzzzz\
zzzzzzzzzzzzzzzzzzzzzzzzzzzzzz\
zzzzzzzzzzzzzzzzzzzzzzzzzzzzzz\
zzzzzzzzzzzzzzzzzzzzzzzzzzzzzz\
zzzzzzzzzzzzzzzzzzzzzzzzzzzzzz\
zzzzzzzzzzzzzzzzzzzzzzzzzzzzzz\
zzzzzzzzzzzzzzzzzzzzzzzzzzzzzz\
zzzzzzz";


int main(void)
{
    WDT_A->CTL = WDT_A_CTL_PW |             // Stop watchdog timer
            WDT_A_CTL_HOLD;

    CS->KEY = CS_KEY_VAL;                   // Unlock CS module for register access
    CS->CTL0 = 0;                           // Reset tuning parameters
    CS->CTL0 = CS_CTL0_DCORSEL_3;           // Set DCO to 12MHz (nominal, center of 8-16MHz range)
    CS->CTL1 = CS_CTL1_SELA_2 |             // Select ACLK = REFO
            CS_CTL1_SELS_3 |                // SMCLK = DCO
            CS_CTL1_SELM_3;                 // MCLK = DCO
    CS->KEY = 0;                            // Lock CS module from unintended accesses

    // Configure UART pins
    P1->SEL0 |= BIT2 | BIT3;                // set 2-UART pin as secondary function

    // Configure UART
    EUSCI_A0->CTLW0 |= EUSCI_A_CTLW0_SWRST; // Put eUSCI in reset
    EUSCI_A0->CTLW0 = EUSCI_A_CTLW0_SWRST | // Remain eUSCI in reset
            EUSCI_B_CTLW0_SSEL__SMCLK;      // Configure eUSCI clock source for SMCLK
    // Baud Rate calculation
    // 12000000/(16*9600) = 78.125
    // Fractional portion = 0.125
    // User's Guide Table 21-4: UCBRSx = 0x10
    // UCBRFx = int ( (78.125-78)*16) = 2
    EUSCI_A0->BRW = 78;                     // 12000000/16/9600
    EUSCI_A0->MCTLW = (2 << EUSCI_A_MCTLW_BRF_OFS) |
            EUSCI_A_MCTLW_OS16;

    EUSCI_A0->CTLW0 &= ~EUSCI_A_CTLW0_SWRST; // Initialize eUSCI
    EUSCI_A0->IFG &= ~EUSCI_A_IFG_RXIFG;    // Clear eUSCI RX interrupt flag
    //EUSCI_A0->IE |= EUSCI_A_IE_RXIE;        // Enable USCI_A0 RX interrupt

    /*To measure the frequency of the pin toggling on Oscilloscope*/
    /*Configure Port 2 Pin 5 as Output Pin*/
    P2->DIR |= BIT5;
    //P2->OUT |= BIT5;

    P2->DIR |= BIT0;
    P2->OUT |= BIT0;

    P2->DIR |= BIT1;
    P2->OUT |= BIT1;
    // Enable global interrupt
    __enable_irq();

    // Enable eUSCIA0 interrupt in NVIC module
    NVIC->ISER[0] = 1 << ((EUSCIA0_IRQn) & 31);

#if 0
    // Enable sleep on exit from ISR
    SCB->SCR |= SCB_SCR_SLEEPONEXIT_Msk;

    // Ensures SLEEPONEXIT occurs immediately
    __DSB();

    // Enter LPM0
    __sleep();
    __no_operation();                       // For debugger
#endif

    int count = 0;

    ptrCounter = ptr2;

    while(*ptrCounter != '\0')
    {
        enqueue(*ptrCounter);
        ptrCounter++;
    }



    while(1)
    {

        /*Check if UART is Busy*/
        while(!(EUSCI_A0->STATW & 0x1))
        {
            P2->OUT |= BIT1;
            P2->OUT &= ~BIT0;
            if(!isBufferEmpty())
            {
                // Check if the TX buffer is empty first
                while(!(EUSCI_A0->IFG & EUSCI_A_IFG_TXIFG));
                EUSCI_A0->TXBUF = dequeue();
                P2->OUT |= BIT5;

            }
            else
            {

                P2->OUT &= ~BIT5;
                if (EUSCI_A0->IFG & EUSCI_A_IFG_RXIFG)
                {
                    ReceivedCharacter = EUSCI_A0->RXBUF;
                    enqueue(ReceivedCharacter);
                }
                ptrCounter = ptr2;
                while(*ptrCounter != '\0')
                {
                    enqueue(*ptrCounter);
                    ptrCounter++;
                }
            }

        }
        P2->OUT |= BIT0;
        P2->OUT &= ~BIT1;

    }

}

// UART interrupt service routine
void EUSCIA0_IRQHandler(void)
{
    if (EUSCI_A0->IFG & EUSCI_A_IFG_RXIFG)
    {
        // Check if the TX buffer is empty first
        while(!(EUSCI_A0->IFG & EUSCI_A_IFG_TXIFG));

        // Echo the received character back
        EUSCI_A0->TXBUF = EUSCI_A0->RXBUF;
    }
}

