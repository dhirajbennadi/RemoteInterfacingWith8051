/***************************************************************************************
 * @file spi.c :
 * @brief : This file contains UART initialization and functions for SPI handling
 *
 * @author : Dhiraj Bennadi
 * @date : Nov 24 2021
 *
 ****************************************************************************************/

/*---Includes---*/
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "msp.h"
#include "uart.h"
#include "cbfifo.h"
#include "gpio.h"

/*---Defines---*/

uint16_t spi_tx_data = 0;
uint16_t spi_rx_data = 0;
/*----------------------------------------------------------------------------
 * Initializing SPI
 * (refer spi.h for additional details)
 * @Resource : This function is written with the help of example code provided
 * in assignment document
 ----------------------------------------------------------------------------*/
void init_spi()
{
    //P1.6 MOSI
    //P1.7 MISO
    //P1.5 CLK

    // Configure SPI
    P10->SEL0 |= BIT0 | BIT1 | BIT2 | BIT3;  // set 4-SPI pin as second function

    EUSCI_B3->CTLW0 |= EUSCI_B_CTLW0_SWRST; // Put state machine in reset

    EUSCI_B3->CTLW0 = EUSCI_B_CTLW0_SWRST | // Remain in reset state
            EUSCI_B_CTLW0_MST |             // SPI master
            EUSCI_B_CTLW0_SYNC |            // Synchronous mode
            EUSCI_B_CTLW0_CKPL |            // Clock polarity high
            EUSCI_B_CTLW0_MSB |             // MSB first
            EUSCI_B_CTLW0_MODE_2 |          // 4-pin mode
            EUSCI_B_CTLW0_STEM |            // STE mode select
            EUSCI_B_CTLW0_SSEL__ACLK;       // ACLK

    EUSCI_B3->BRW = 0x00;                   // /2,fBitClock = fBRCLK/(UCBRx+1).
    EUSCI_B3->CTLW0 &= ~EUSCI_B_CTLW0_SWRST;// **Initialize USCI state machine**


    // Enable eUSCI_B0 interrupt in NVIC module
    NVIC->ISER[0] = 1 << ((EUSCIB3_IRQn) & 31);

}

/*----------------------------------------------------------------------------
 * transmit over SPI
 * (refer spi.h for additional details)
 * @Resource : This function is written with the help of example code provided
 * in assignment document
 ----------------------------------------------------------------------------*/
void spi_tx(uint16_t data)
{
//    SPI_CS_PORT->OUT &= ~SPI_CS_PIN;
    spi_tx_data = data;
    EUSCI_B3->IFG |= EUSCI_B_IFG_TXIFG;// Clear TXIFG flag
    EUSCI_B3->IE |= EUSCI_B_IE_TXIE;    // Enable TX interrupt

}

