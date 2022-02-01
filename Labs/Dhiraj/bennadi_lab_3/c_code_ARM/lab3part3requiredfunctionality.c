/*************************************************
 * @filename : main.c
 * @author   : Dhiraj Bennadi
 * @compiler : arm
 * @IDE      : Code Composer Studio
 *
 * Identification of any leveraged code : None
 * Applicable Links: None
 */
#include <stdbool.h>
#include <stdio.h>
#include "msp.h"
#include "cbfifo.h"


#define MAX_DUTY_CYCLE               (50000)
#define DEF_DUTY_CYCLE               (27500)
#define DUTY_CYCLE_VARIATION_VALUE   (5000)
#define MAX_PWM_PERIOD               (65535)
#define INIT_VAL                     (0)

uint8_t ReceivedChar = 0;
bool CharacterReceived = false;

bool Switch1Pressed = false;
bool Switch2Pressed = false;

volatile long temp;
volatile float IntDegF;
volatile float IntDegC;

float FirstTempRecord;
float CurrentTemp;
bool IsFirstTempRecorded = false;
int TempReadCounter = 0;
bool ReadTemperature = false;
float DutyCycle;
float OnPeriodCount = 0;
float PWM_Period = MAX_DUTY_CYCLE;

char printString[30];

typedef enum{
    HIGHER,
    LOWER,
    NO_DIFF
}TempChange;

TempChange TempVariation = NO_DIFF;

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
 * @brief Initializes the PWM module on P2.7
 *
 * @param None
 *
 * @return None
 */
void Init_PWM(void)
{
    P2->SEL0 |= BIT7;
    P2->SEL1 = 0;
    P2->DIR |= BIT7;

    TIMER_A0->CCR[0] = 50000;
    TIMER_A0->CCR[4] = 27500;
    OnPeriodCount = 27500;
    TIMER_A0->CCTL[4] = TIMER_A_CCTLN_OUTMOD_7;
    TIMER_A0->CTL = TIMER_A_CTL_SSEL__SMCLK | TIMER_A_CTL_MC__UP | TIMER_A_CTL_CLR;
}


/*
 * @brief Initializes the Button Switch P1.1 and P1.4
 *
 * @param None
 *
 * @return None
 */
void InitSwitch(void)
{
    /*Configuring P1.4 (switch) as input with pull-ip resistor*/
    P1->DIR = ~(uint8_t) BIT1 | BIT4;
    P1->OUT = BIT1 | BIT4;
    P1->REN = BIT1 | BIT4;                         // Enable pull-up resistor (P1.4 output high)

    P1->SEL0 = 0;
    P1->SEL1 = 0;

    P1->IES = BIT1 | BIT4;                         // Interrupt on high-to-low transition

    P1->IFG = 0;                            // Clear all P1 interrupt flags

    P1->IE = BIT1 | BIT4;                          // Enable interrupt for P1.4
}


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
 * @brief Initializes the ADC14 for Temperature Sensing
 *
 * @param None
 *
 * @return None
 */
void InitTempSensor(void)
{
    // Initialize the shared reference module
    // By default, REFMSTR=1 => REFCTL is used to configure the internal reference
    while(REF_A->CTL0 & REF_A_CTL0_GENBUSY);// If ref generator busy, WAIT
    REF_A->CTL0 |= REF_A_CTL0_VSEL_0 |      // Enable internal 1.2V reference
            REF_A_CTL0_ON;                  // Turn reference on

    REF_A->CTL0 &= ~REF_A_CTL0_TCOFF;       // Enable temperature sensor

    // Configure ADC - Pulse sample mode; ADC14_CTL0_SC trigger
    ADC14->CTL0 |= ADC14_CTL0_SHT0_6 |      // ADC ON,temperature sample period>5us
            ADC14_CTL0_ON |
            ADC14_CTL0_SHP;
    ADC14->CTL1 |= ADC14_CTL1_TCMAP;        // Enable internal temperature sensor
    ADC14->MCTL[0] = ADC14_MCTLN_VRSEL_1 |  // ADC input ch A22 => temp sense
            ADC14_MCTLN_INCH_22;
    ADC14->IER0 = 0x0001;                   // ADC_IFG upon conv result-ADCMEM0

    // Wait for reference generator to settle
    while(!(REF_A->CTL0 & REF_A_CTL0_GENRDY));

    ADC14->CTL0 |= ADC14_CTL0_ENC;

}


/*
 * @brief Reads the Temperature value in Degrees from ADC14
 *
 * @param None
 *
 * @return None
 */
float ReadTemperatureInDegrees(void)
{
    // Variables to store the ADC temperature reference calibration value
    int32_t adcRefTempCal_1_2v_30;
    int32_t adcRefTempCal_1_2v_85;

    // Read the ADC temperature reference calibration value
    adcRefTempCal_1_2v_30 = TLV->ADC14_REF1P2V_TS30C;
    adcRefTempCal_1_2v_85 = TLV->ADC14_REF1P2V_TS85C;
    //Temp
    // Temperature in Celsius
    // The temperature (Temp, C)=
    IntDegC = (((float) temp - adcRefTempCal_1_2v_30) * (85 - 30)) /
            (adcRefTempCal_1_2v_85 - adcRefTempCal_1_2v_30) + 30.0f;

    return IntDegC;
}

/*
 * @brief Reads the Temperature value in Kelvin from ADC14
 *
 * @param None
 *
 * @return None
 */
float ReadTemperatureInKelvin(void)
{
    // Variables to store the ADC temperature reference calibration value
    int32_t adcRefTempCal_1_2v_30;
    int32_t adcRefTempCal_1_2v_85;

    // Read the ADC temperature reference calibration value
    adcRefTempCal_1_2v_30 = TLV->ADC14_REF1P2V_TS30C;
    adcRefTempCal_1_2v_85 = TLV->ADC14_REF1P2V_TS85C;
    //Temp
    // Temperature in Celsius
    // The temperature (Temp, C)=
    IntDegC = (((float) temp - adcRefTempCal_1_2v_30) * (85 - 30)) /
            (adcRefTempCal_1_2v_85 - adcRefTempCal_1_2v_30) + 30.0f;

    return IntDegC + 273;
}


/*
 * @brief Reads the Fahreniet value in Degrees from ADC14
 *
 * @param None
 *
 * @return None
 */
float ReadTemperatureInFahreniet(void)
{
    // Variables to store the ADC temperature reference calibration value
    int32_t adcRefTempCal_1_2v_30;
    int32_t adcRefTempCal_1_2v_85;

    // Read the ADC temperature reference calibration value
    adcRefTempCal_1_2v_30 = TLV->ADC14_REF1P2V_TS30C;
    adcRefTempCal_1_2v_85 = TLV->ADC14_REF1P2V_TS85C;
    //Temp
    // Temperature in Celsius
    // The temperature (Temp, C)=
    IntDegC = (((float) temp - adcRefTempCal_1_2v_30) * (85 - 30)) /
            (adcRefTempCal_1_2v_85 - adcRefTempCal_1_2v_30) + 30.0f;

    // Temperature in Fahrenheit
    // Tf = (9/5)*Tc | 32
    IntDegF = ((9 * IntDegC) / 5) + 32;

    return IntDegF;
}


/*
 * @brief Compares the current temperature and the previous temperature
 *        for a change in the temperature
 *
 * @param None
 *
 * @return None
 */
TempChange CompareTempRecordedForDiff(float ReferenceTemp, float CurrentTemp)
{


    if(CurrentTemp > ReferenceTemp + 0.5f)
    {
        return HIGHER;
    }
    else if(CurrentTemp < ReferenceTemp - 0.5f)
    {
        return LOWER;
    }
    else
    {
        return NO_DIFF;
    }

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

    // Enable Port 1 interrupt on the NVIC
    NVIC->ISER[1] = 1 << ((PORT1_IRQn) & 31);

    NVIC->ISER[0] = 1 << ((ADC14_IRQn) & 31);// Enable ADC interrupt in NVIC module

    NVIC->ISER[0] = 1 << ((TA0_0_IRQn) & 31);

    // Enable global interrupt
    __enable_irq();

}


/*
 * @brief Prints the Initial Details on Startup
 *
 * @param None
 *
 * @return None
 */
void printInitialDetails(void)
{
    sprintf(printString,"Lab 3 Part 3 SignOff\n\r");
    putstringInBuffer(printString);
    DutyCycle = (OnPeriodCount / PWM_Period) * 100;
    sprintf(printString,"Current Duty Cycle = %f\n\r",DutyCycle);
    putstringInBuffer(printString);
    sprintf(printString,"Current PWM Period Value = %f\n\r",PWM_Period);
    putstringInBuffer(printString);
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
+{

    /*Disables the WatchDog Timer*/
    disableWatchDogTimer();
    /*Enables the CS Module for Register Access*/
    enableCSModule();

    /*Initializes the P1.1 and P1.4 Switch*/
    InitSwitch();
    /*Initializes the UART Module on P1.2 and P1.3*/
    InitUart();
    /*Initializes the Temp Sensor on ADC 14*/
    InitTempSensor();
    /*Initializes the PWM Module on Timer A*/
    Init_PWM();

    /*Enables the Interrupts for UART, GPIO and ADC 14*/
    enableNVICInterrupts();


    P2->DIR |= BIT1;

    /*Prints the Initial Details of PWM Period and Duty Cycle*/
    printInitialDetails();

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
    if (EUSCI_A0->IFG & EUSCI_A_IFG_RXIFG)
    {
        CharacterReceived = true;
        ReceivedChar = EUSCI_A0->RXBUF;
        enqueue(ReceivedChar);
    }

    if(EUSCI_A0->IE & EUSCI_A_IE_TXIE)
    {
        EUSCI_A0->IE &= ~EUSCI_A_IE_TXIE;
    }
}


/*
 * @brief Port 1 ISR service routine
 *
 * @param None
 *
 * @return None
 */
void PORT1_IRQHandler(void)
{
    volatile uint32_t i;

    if(P1->IFG & BIT1)
    {
        Switch1Pressed = true;
        for(i = 0; i < 1000; i++)
        {
            P1->IFG &= ~BIT1;
        }
    }

    if(P1->IFG & BIT4)
    {
        Switch2Pressed = true;
        for(i = 0; i < 1000; i++)
        {
            P1->IFG &= ~BIT4;
        }
    }

}

/*
 * @brief ADC14 interrupt service routine
 *
 * @param None
 *
 * @return None
 */
void ADC14_IRQHandler(void)
{
    if (ADC14->IFGR0 & ADC14_IFGR0_IFG0)
    {
        temp = ADC14->MEM[0];
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

    TempReadCounter++;
    /* ADC Sampling and conversion start*/
    ADC14->CTL0 |= ADC14_CTL0_SC;

    if(CharacterReceived)
    {
        switch(ReceivedChar)
        {
        case 'P':
            DutyCycle = (OnPeriodCount / PWM_Period) * 100;

            sprintf(printString,"\n\rDuty Cycle Reading = %f", DutyCycle);
            putstringInBuffer(printString);
            break;

        case 'T':
            sprintf(printString,"\n\rTemp Reading = %f C", ReadTemperatureInDegrees());
            putstringInBuffer(printString);
            break;

        case 'F':
            sprintf(printString,"\n\rTemp Reading = %f F", ReadTemperatureInFahreniet());
            putstringInBuffer(printString);
            break;
        case 'K':
            sprintf(printString,"\n\rTemp Reading = %f K", ReadTemperatureInKelvin());
            putstringInBuffer(printString);
            break;

        case '+':
            if(OnPeriodCount + DUTY_CYCLE_VARIATION_VALUE < MAX_DUTY_CYCLE)
            {
                TIMER_A0->CCR[4] = OnPeriodCount + DUTY_CYCLE_VARIATION_VALUE;
                OnPeriodCount += DUTY_CYCLE_VARIATION_VALUE;
                TIMER_A0->CTL |= TIMER_A_CTL_CLR;
                sprintf(printString,"\n\rCommand Received to Increase Duty Cycle");
                putstringInBuffer(printString);
                DutyCycle = (OnPeriodCount / PWM_Period) * 100;
                sprintf(printString,"\n\rDuty Cycle Value = %f", DutyCycle);
                putstringInBuffer(printString);

            }
            else
            {
                sprintf(printString,"\n\rDuty Cycle Variation Max Value Reached");
                putstringInBuffer(printString);
            }
            break;

        case '-':
            if(OnPeriodCount - DUTY_CYCLE_VARIATION_VALUE > 0)
            {
                TIMER_A0->CCR[4] = OnPeriodCount - DUTY_CYCLE_VARIATION_VALUE;
                OnPeriodCount -= DUTY_CYCLE_VARIATION_VALUE;
                TIMER_A0->CTL |= TIMER_A_CTL_CLR;
                sprintf(printString,"\n\rCommand Received to Decrease Duty Cycle");
                putstringInBuffer(printString);
                DutyCycle = (OnPeriodCount / PWM_Period) * 100;
                sprintf(printString,"\n\rDuty Cycle Value = %f", DutyCycle);
                putstringInBuffer(printString);

            }
            else
            {
                sprintf(printString,"\n\rDuty Cycle Variation Minimum Value Reached");
                putstringInBuffer(printString);
            }
            break;

        case 'Q':
            if(PWM_Period + DUTY_CYCLE_VARIATION_VALUE < MAX_PWM_PERIOD)
            {
                TIMER_A0->CCR[0] = PWM_Period + DUTY_CYCLE_VARIATION_VALUE;
                PWM_Period += DUTY_CYCLE_VARIATION_VALUE;
                TIMER_A0->CTL |= TIMER_A_CTL_CLR;
                sprintf(printString,"\n\rCommand Received to Increase Period");
                putstringInBuffer(printString);
                sprintf(printString,"\n\rPWM Period = %f", PWM_Period);
                putstringInBuffer(printString);
            }
            else
            {
                sprintf(printString,"\n\rPWM Period Max Reached");
                putstringInBuffer(printString);
            }
            break;

        case 'W':
            if(PWM_Period - DUTY_CYCLE_VARIATION_VALUE > 0)
            {
                TIMER_A0->CCR[0] = PWM_Period - DUTY_CYCLE_VARIATION_VALUE;
                PWM_Period -= DUTY_CYCLE_VARIATION_VALUE;
                TIMER_A0->CTL |= TIMER_A_CTL_CLR;
                sprintf(printString,"\n\rCommand Received to Decrease Period");
                putstringInBuffer(printString);
                sprintf(printString,"\n\rPWM Period = %f", PWM_Period);
                putstringInBuffer(printString);
            }
            else
            {
                sprintf(printString,"\n\rPWM Period Min Reached");
                putstringInBuffer(printString);
            }

            break;

        case 'E':
            TIMER_A0->CCR[0] = MAX_DUTY_CYCLE;
            PWM_Period = MAX_DUTY_CYCLE;
            TIMER_A0->CCR[4] = DEF_DUTY_CYCLE;
            OnPeriodCount = DEF_DUTY_CYCLE;
            TIMER_A0->CTL |= TIMER_A_CTL_CLR;
            sprintf(printString,"\n\rCommand Received to Set Default Period");
            putstringInBuffer(printString);
            DutyCycle = (OnPeriodCount / PWM_Period) * 100;
            sprintf(printString,"\n\rDuty Cycle Value = %f", DutyCycle);
            putstringInBuffer(printString);
            break;

        }

        ReceivedChar = '\0';
        CharacterReceived = false;
    }


    /*Check if the UART TX Interrupt Flag is active*/
    if(!(EUSCI_A0->IE & EUSCI_A_IE_TXIE))
    {
        if(!isBufferEmpty())
        {
            EUSCI_A0->TXBUF = dequeue();
            EUSCI_A0->IE |= EUSCI_A_IE_TXIE;

            /*Only for UART Testing*/
            P2->OUT |= BIT1;
        }
        else
        {
            /*Only for UART Testing*/
            P2->OUT &= ~BIT1;
        }

    }


    if(IsFirstTempRecorded == false)
    {
        IsFirstTempRecorded = true;
        FirstTempRecord = ReadTemperatureInDegrees();

    }

    if(TempReadCounter == 100000)
    {
        TempReadCounter = 0;
        ReadTemperature = false;
        CurrentTemp = ReadTemperatureInDegrees();
        TempVariation = CompareTempRecordedForDiff(FirstTempRecord, CurrentTemp);
        FirstTempRecord = CurrentTemp;

        if(TempVariation == HIGHER)
        {
            if(OnPeriodCount + DUTY_CYCLE_VARIATION_VALUE < PWM_Period)
            {
                TIMER_A0->CCR[4] = OnPeriodCount + DUTY_CYCLE_VARIATION_VALUE;
                OnPeriodCount += DUTY_CYCLE_VARIATION_VALUE;
                TIMER_A0->CTL |= TIMER_A_CTL_CLR;
                sprintf(printString,"\n\rPWM Increase By Temperature");
                putstringInBuffer(printString);
                DutyCycle = (OnPeriodCount / PWM_Period) * 100;
                sprintf(printString,"\n\rDuty Cycle Value = %f", DutyCycle);
                putstringInBuffer(printString);
            }
        }
        else if(TempVariation == LOWER)
        {
            if(OnPeriodCount - DUTY_CYCLE_VARIATION_VALUE > 0)
            {
                TIMER_A0->CCR[4] = OnPeriodCount - DUTY_CYCLE_VARIATION_VALUE;
                OnPeriodCount -= DUTY_CYCLE_VARIATION_VALUE;
                TIMER_A0->CTL |= TIMER_A_CTL_CLR;
                sprintf(printString,"\n\rPWM Decrease By Temperature");
                putstringInBuffer(printString);
                DutyCycle = (OnPeriodCount / PWM_Period) * 100;
                sprintf(printString,"\n\rDuty Cycle Value = %f", DutyCycle);
                putstringInBuffer(printString);
            }
        }


    }


    if(Switch1Pressed)
    {
        Switch1Pressed = false;

        sprintf(printString,"\n\rSwitch S1 Pressed");
        putstringInBuffer(printString);
        if(OnPeriodCount + DUTY_CYCLE_VARIATION_VALUE < PWM_Period)
        {
            TIMER_A0->CCR[4] = OnPeriodCount + DUTY_CYCLE_VARIATION_VALUE;
            OnPeriodCount += DUTY_CYCLE_VARIATION_VALUE;
            TIMER_A0->CTL |= TIMER_A_CTL_CLR;
            DutyCycle = (OnPeriodCount / PWM_Period) * 100;
            sprintf(printString,"\n\rDuty Cycle Value = %f", DutyCycle);
            putstringInBuffer(printString);
        }
    }

    if(Switch2Pressed)
    {
        Switch2Pressed = false;
        sprintf(printString,"\n\rSwitch S2 Pressed");
        putstringInBuffer(printString);
        if(OnPeriodCount - DUTY_CYCLE_VARIATION_VALUE > 0)
        {
            TIMER_A0->CCR[4] = OnPeriodCount - DUTY_CYCLE_VARIATION_VALUE;
            OnPeriodCount -= DUTY_CYCLE_VARIATION_VALUE;
            TIMER_A0->CTL |= TIMER_A_CTL_CLR;
            DutyCycle = (OnPeriodCount / PWM_Period) * 100;
            sprintf(printString,"\n\rDuty Cycle Value = %f", DutyCycle);
            putstringInBuffer(printString);
        }
    }

}
