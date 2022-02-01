/*
 * temp.c
 *
 *  Created on: Oct 22, 2021
 *      Author: Rajat
 */

#include "msp.h"
#include "temp.h"
#include "stdint.h"

/*----------------------------------------------------------------------------
 * Initializes ADC required for temp
 * Resource : example code mentioned in assignment document
 ----------------------------------------------------------------------------*/
void init_temp()
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

    NVIC->ISER[0] = 1 << ((ADC14_IRQn) & 31);// Enable ADC interrupt in NVIC module

}

/*----------------------------------------------------------------------------
 * Initiates temp measurement
 ----------------------------------------------------------------------------*/
void start_temp_measurement(void)
{
    ADC14->CTL0 |= ADC14_CTL0_SC;       // Sampling and conversion start
}


