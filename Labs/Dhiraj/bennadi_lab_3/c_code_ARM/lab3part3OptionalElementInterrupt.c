/*************************************************
 * @filename : main.c
 * @author   : Dhiraj Bennadi
 * @compiler : arm
 * @IDE      : Code Composer Studio
 *
 * Identification of any leveraged code : None
 * Applicable Links: None
 */

/*UART Interrupt Test*/
#include <stdbool.h>
#include <stdio.h>
#include "msp.h"
#include "cbfifo.h"

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
        So what is a serial interface?  At a very basic level, a serial interface is a shift\
        register that shifts.UART\n";

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


char printString[30];
char ReceivedChar;


/*
 * @brief Puts the string into the circular buffer for Transmission
 *
 * @param None
 *
 * @return None
 */
void putstringInBuffer(char *ptr);

/*
 * @brief Handles the state machine executing cases for UART,PWM and Temp
 *        sensing
 *
 * @param None
 *
 * @return None
 */
static void StateMachine(void);




/*
 * @brief Initializes the UART module on P1.2 and P1.3
 *
 * @param None
 *
 * @return None
 */
void InitUart(void)
{
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
    EUSCI_A0->IE |= EUSCI_A_IE_RXIE;        // Enable USCI_A0 RX interrupt
    // Configure UART pins
    P1->SEL0 |= BIT2 | BIT3;                // set 2-UART pin as secondary function
}




/*
 * @brief Disables Watchdog Timer
 *
 * @param None
 *
 * @return None
 */
void disableWatchDogTimer(void)
{
    WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;
}


/*
 * @brief Enables the NVIC Interrupts for specified modules
 *
 * @param None
 *
 * @return None
 */
void enableNVICInterrupts(void)
{
    // Enable eUSCIA0 interrupt in NVIC module
    NVIC->ISER[0] = 1 << ((EUSCIA0_IRQn) & 31);

    // Enable global interrupt
    __enable_irq();

}





/*
 * @brief Enables the Sleep Mode
 *
 * @param None
 *
 * @return None
 */
void enableSleepMode(void)
{
    // Enable sleep on exit from ISR
    SCB->SCR |= SCB_SCR_SLEEPONEXIT_Msk;

    // Ensures SLEEPONEXIT occurs immediately
    __DSB();

    // Enter LPM0
    __sleep();
    __no_operation();                       // For debugger

}

/*
 * @brief Enables the CS Module
 *
 * @param None
 *
 * @return None
 */
void enableCSModule(void)
{
    CS->KEY = CS_KEY_VAL;                   // Unlock CS module for register access
    CS->CTL0 = 0;                           // Reset tuning parameters
    CS->CTL0 = CS_CTL0_DCORSEL_3;           // Set DCO to 12MHz (nominal, center of 8-16MHz range)
    CS->CTL1 = CS_CTL1_SELA_2 |             // Select ACLK = REFO
            CS_CTL1_SELS_3 |                // SMCLK = DCO
            CS_CTL1_SELM_3;                 // MCLK = DCO
    CS->KEY = 0;                            // Lock CS module from unintended accesses
}


/*
 * @brief main function
 *
 * @param None
 *
 * @return None
 */
int main(void)
{

    /*Disables the WatchDog Timer*/
    disableWatchDogTimer();
    /*Enables the CS Module for Register Access*/
    enableCSModule();
    /*Initializes the UART Module on P1.2 and P1.3*/
    InitUart();


    /*Enables the Interrupts for UART, GPIO and ADC 14*/
    enableNVICInterrupts();


    P2->DIR |= BIT0;
    P2->DIR |= BIT1;
    P2->DIR |= BIT5;

    ptrCounter = ptr2;

    while(*ptrCounter != '\0')
    {
        enqueue(*ptrCounter);
        ptrCounter++;
    }


    while(1)
    {
        /*State Machine to handle cases for UART,PWM and Temp Sensor*/
        StateMachine();
    }
}

/*
 * @brief UART interrupt service routine
 *
 * @param None
 *
 * @return None
 */
void EUSCIA0_IRQHandler(void)
{
    P2->OUT |= BIT0;
    P2->OUT &= ~BIT1;
    if (EUSCI_A0->IFG & EUSCI_A_IFG_RXIFG)
    {
        ReceivedChar = EUSCI_A0->RXBUF;
        enqueue(ReceivedChar);
    }

    if(EUSCI_A0->IE & EUSCI_A_IE_TXIE)
    {
        EUSCI_A0->IE &= ~EUSCI_A_IE_TXIE;
    }
}




/*
 * @brief Puts the string into the circular buffer for Transmission
 *
 * @param None
 *
 * @return None
 */
void putstringInBuffer(char *ptr)
{
    while(*ptr != '\0')
    {
        enqueue(*ptr);
        ptr++;
    }

    enqueue('\n');
    enqueue('\r');
}

/*
 * @brief Handles the state machine executing cases for UART,PWM and Temp
 *        sensing
 *
 * @param None
 *
 * @return None
 */
static void StateMachine(void)
{

    P2->OUT |= BIT1;
    P2->OUT &= ~BIT0;
    /*Check if the UART TX Interrupt Flag is active*/
    if(!(EUSCI_A0->IE & EUSCI_A_IE_TXIE))
    {
        if(!isBufferEmpty())
        {
            EUSCI_A0->TXBUF = dequeue();
            EUSCI_A0->IE |= EUSCI_A_IE_TXIE;

            /*Only for UART Testing*/

            P2->OUT |= BIT5;
        }
        else
        {
            P2->OUT &= ~BIT5;
            ptrCounter = ptr2;
            while(*ptrCounter != '\0')
            {
                enqueue(*ptrCounter);
                ptrCounter++;
            }
            /*Only for UART Testing*/
        }

    }


}
