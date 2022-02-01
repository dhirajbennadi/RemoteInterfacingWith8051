/*Title: Embedded System Design ECEN 5613*/
/*Submitted by: Dhiraj Bennadi*/

#include "msp.h"


/*
*@Function : main
*@Brief    : Entry Point to the Program
*Parameters: None
*Returns   : None
*/
int main(void)
{
    /*Stops the Watchdog Timer*/
    WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;

    // Terminate all remaining pins on the device
    P1->DIR |= 0xFF; P1->OUT = 0;
    P2->DIR |= 0xFF; P2->OUT = 0;
    P3->DIR |= 0xFF; P3->OUT = 0;
    P4->DIR |= 0xFF; P4->OUT = 0;
    P5->DIR |= 0xFF; P5->OUT = 0;
    P6->DIR |= 0xFF; P6->OUT = 0;
    P7->DIR |= 0xFF; P7->OUT = 0;
    P8->DIR |= 0xFF; P8->OUT = 0;
    P9->DIR |= 0xFF; P9->OUT = 0;
    P10->DIR |= 0xFF; P10->OUT = 0;

    // Configure Port J
    PJ->DIR |= (BIT2 | BIT3); PJ->OUT &= ~(BIT2 | BIT3);

    PJ->SEL0 |= BIT0 | BIT1;                // set LFXT pin as second function

    CS->KEY = CS_KEY_VAL ;                  // Unlock CS module for register access

    CS->CTL2 |= CS_CTL2_LFXT_EN;            // LFXT on

    // Loop until XT1, XT2 & DCO fault flag is cleared
    do
    {
       // Clear XT2,XT1,DCO fault flags
       CS->CLRIFG |= CS_CLRIFG_CLR_DCOR_OPNIFG | CS_CLRIFG_CLR_HFXTIFG |
               CS_CLRIFG_CLR_LFXTIFG | CS_CLRIFG_CLR_FCNTLFIFG;
       SYSCTL->NMI_CTLSTAT &= ~ SYSCTL_NMI_CTLSTAT_CS_SRC;
    } while ((SYSCTL->NMI_CTLSTAT | SYSCTL_NMI_CTLSTAT_CS_FLG)
            && (CS->IFG & CS_IFG_LFXTIFG)); // Test oscillator fault flag

    // Select ACLK as LFXTCLK
    CS->CTL1 &= ~(CS_CTL1_SELA_MASK) | CS_CTL1_SELA_0;
    CS->KEY = 0;                            // Lock CS module from unintended accesses

    // Configure RTC

    // Unlock RTC key protected registers
    // RTC enable, BCD mode, RTC hold
    // enable RTC read ready interrupt
    // enable RTC time event interrupt
    // set time event interrupt to trigger when minute changes
    RTC_C->CTL0 = RTC_C_KEY | RTC_C_CTL0_TEVIE;
    RTC_C->CTL13 = RTC_C_CTL13_HOLD |
            RTC_C_CTL13_MODE |
            RTC_C_CTL13_BCD |
            RTC_C_CTL13_TEV_0;

    RTC_C->YEAR = 0x2021;                   // Year = 0x2021
    RTC_C->DATE = (0xB << RTC_C_DATE_MON_OFS) | // Month = 0xA = November
            (0xE | RTC_C_DATE_DAY_OFS);    // Day = 0xE = 14th
    RTC_C->TIM1 = (0x00 << RTC_C_TIM1_DOW_OFS) | // Day of week = 0x00 = Sunday
            (0xE << RTC_C_TIM1_HOUR_OFS);  // Hour = 0xE
    RTC_C->TIM0 = (0x4 << RTC_C_TIM0_MIN_OFS) | // Minute = 0x4
            (0x45 << RTC_C_TIM0_SEC_OFS);   // Seconds = 0x45

    // Start RTC calendar mode
    RTC_C->CTL13 = RTC_C->CTL13 & ~(RTC_C_CTL13_HOLD);

    // Lock the RTC registers
    RTC_C->CTL0 = RTC_C->CTL0 & ~(RTC_C_CTL0_KEY_MASK);

    // Enable all SRAM bank retentions prior to going to LPM3 (Deep-sleep)
    SYSCTL->SRAM_BANKRET |= SYSCTL_SRAM_BANKRET_BNK7_RET;

    // Enable global interrupt
    __enable_irq();

    NVIC->ISER[0] = 1 << ((RTC_C_IRQn) & 31);

    // Sleep on exit from ISR
    SCB->SCR |= SCB_SCR_SLEEPONEXIT_Msk;

    __DSB();

    while (1)
    {
        // Setting the sleep deep bit
        SCB->SCR |= (SCB_SCR_SLEEPDEEP_Msk);

        // Ensures SLEEPDEEP takes effect immediately
        __DSB();

        __sleep();

        // Clearing the sleep deep bit
        SCB->SCR &= ~(SCB_SCR_SLEEPDEEP_Msk);
    }
}


/*
*@Function : RTC_C_IRQHandler
*@Brief    : ISR Routine for RTC 
*Parameters: None
*Returns   : None
*/
void RTC_C_IRQHandler(void)
{
    if (RTC_C->CTL0 & RTC_C_CTL0_TEVIFG)
    {
        P1->OUT ^= BIT0;

        // Unlock the RTC module and clear time event interrupt flag
        RTC_C->CTL0 = (RTC_C->CTL0 & ~(RTC_C_CTL0_KEY_MASK |  RTC_C_CTL0_TEVIFG)) | RTC_C_KEY;

        // Re-lock the RTC
        RTC_C->CTL0 = RTC_C->CTL0 & ~(RTC_C_CTL0_KEY_MASK);
    }
}



