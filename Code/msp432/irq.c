/*****************************************************************************************
 * @file irq.c :
 * @brief : This file contains interrupt handlers for peripherals
 *
 * @author : Rajat Chaple (rajat.chaple@colorado.edu)
 * @date : Nov 15, 2021
 *
******************************************************************************************/

#include "msp.h"
#include "cbfifo.h"
#include "gpio.h"
#include "stdbool.h"
#include "uart.h"

extern cbfifo_t cbfifo_transmit_uart0;
extern cbfifo_t cbfifo_receive_uart0;

extern cbfifo_t cbfifo_transmit_uart2;
extern cbfifo_t cbfifo_receive_uart2;

extern cbfifo_t cbfifo_transmit_uart3;
extern cbfifo_t cbfifo_receive_uart3;

extern uint16_t spi_tx_data;
extern uint16_t spi_rx_data;

extern uint8_t i2c_tx_data;
extern uint8_t i2c_rx_data;


/*--------------- Datatypes-------------*/
typedef enum led_status_e{
    GREEN_LED,
    BLUE_LED,  //010
    NO_CHANGE
}led_status_t;



led_status_t led_status = BLUE_LED;//as init is always green
led_status_t prev_led_status = GREEN_LED;

bool toggle_state_by_switch = true;
bool debounce_period_elapsed = false;

volatile long temp;
volatile float IntDegF;

bool temp_ready_status = false;


/** ------------------------------------------------------------------------------
 * @brief UART0 IRQ handler for tranmit and receive
 * @param none
 * @return none
 ---------------------------------------------------------------------------------**/
void EUSCIA0_IRQHandler(void)
{

    int RXData;
    int TXData;
    uint32_t masking_state;

    //data is received over UART
        if (EUSCI_A0->IFG & EUSCI_A_IFG_RXIFG)
        {
            EUSCI_A0->IFG &= ~EUSCI_A_IFG_RXIFG;// Clear interrupt
            RXData = EUSCI_A0->RXBUF;           // Clear buffer
            if(cbfifo_length(&cbfifo_receive_uart0) != cbfifo_capacity(&cbfifo_receive_uart0)) //if fifo not full
            {
                //entering critical section
                masking_state = __get_PRIMASK();
                __disable_irq();
                cbfifo_enqueue(&cbfifo_receive_uart0, &RXData, sizeof(RXData));   //adding element to the queue
                __set_PRIMASK(masking_state);
            }
            else
            {
                //character discarded when queue is full
            }
        }



        //Transmit interrupt received
        if((EUSCI_A0->IFG & EUSCI_A_IFG_TXIFG) &
                ( EUSCI_A0->IE & EUSCI_A_IE_TXIE))
        {
            if(cbfifo_length(&cbfifo_transmit_uart0) != 0)
            {
                //entering critical section
                masking_state = __get_PRIMASK();
                __disable_irq();
                 if(cbfifo_dequeue(&cbfifo_transmit_uart0, &TXData, 1) == 1)  //dequeue elemnt to be sent
                     EUSCI_A0->TXBUF = TXData;
                __set_PRIMASK(masking_state);
            }
            else
            {
                EUSCI_A0->IE &= ~EUSCI_A_IE_TXIE;    //disabling transmit interrupt
            }
        }
}


/** ------------------------------------------------------------------------------
 * @brief UART2 IRQ handler for tranmit and receive
 * @param none
 * @return none
 ---------------------------------------------------------------------------------**/
void EUSCIA2_IRQHandler(void)
{

    int RXData;
    int TXData;
    uint32_t masking_state;

    //data is received over UART
        if (EUSCI_A2->IFG & EUSCI_A_IFG_RXIFG)
        {
            EUSCI_A2->IFG &= ~EUSCI_A_IFG_RXIFG;// Clear interrupt
            RXData = EUSCI_A2->RXBUF;           // Clear buffer
            //echo(RXData);
            if(cbfifo_length(&cbfifo_receive_uart2) != cbfifo_capacity(&cbfifo_receive_uart2)) //if fifo not full
            {
                //entering critical section
                masking_state = __get_PRIMASK();
                __disable_irq();
                cbfifo_enqueue(&cbfifo_receive_uart2, &RXData, sizeof(RXData));   //adding element to the queue
                __set_PRIMASK(masking_state);
            }
            else
            {
                //character discarded when queue is full
            }
        }



        //Transmit interrupt received
        if((EUSCI_A2->IFG & EUSCI_A_IFG_TXIFG) &
                ( EUSCI_A2->IE & EUSCI_A_IE_TXIE))
        {
            if(cbfifo_length(&cbfifo_transmit_uart2) != 0)
            {
                //entering critical section
                masking_state = __get_PRIMASK();
                __disable_irq();
                 if(cbfifo_dequeue(&cbfifo_transmit_uart2, &TXData, 1) == 1)  //dequeue element to be sent
                     EUSCI_A2->TXBUF = TXData;
                __set_PRIMASK(masking_state);
            }
            else
            {
                EUSCI_A2->IE &= ~EUSCI_A_IE_TXIE;    //disabling transmit interrupt
            }
        }
}

/** ------------------------------------------------------------------------------
 * @brief UART3 IRQ handler for tranmit and receive
 * @param none
 * @return none
 ---------------------------------------------------------------------------------**/
void EUSCIA3_IRQHandler(void)
{

    int RXData;
    int TXData;
    uint32_t masking_state;

    //data is received over UART
        if (EUSCI_A3->IFG & EUSCI_A_IFG_RXIFG)
        {
            EUSCI_A3->IFG &= ~EUSCI_A_IFG_RXIFG;// Clear interrupt
            RXData = EUSCI_A3->RXBUF;           // Clear buffer
            //echo(RXData);
            if(cbfifo_length(&cbfifo_receive_uart3) != cbfifo_capacity(&cbfifo_receive_uart3)) //if fifo not full
            {
                //entering critical section
                masking_state = __get_PRIMASK();
                __disable_irq();
                cbfifo_enqueue(&cbfifo_receive_uart3, &RXData, sizeof(RXData));   //adding element to the queue
                __set_PRIMASK(masking_state);
            }
            else
            {
                //character discarded when queue is full
            }
        }



        //Transmit interrupt received
        if((EUSCI_A3->IFG & EUSCI_A_IFG_TXIFG) &
                ( EUSCI_A3->IE & EUSCI_A_IE_TXIE))
        {
            if(cbfifo_length(&cbfifo_transmit_uart3) != 0)
            {
                //entering critical section
                masking_state = __get_PRIMASK();
                __disable_irq();
                 if(cbfifo_dequeue(&cbfifo_transmit_uart3, &TXData, 1) == 1)  //dequeue elemnt to be sent
                     EUSCI_A3->TXBUF = TXData;
                __set_PRIMASK(masking_state);
            }
            else
            {
                EUSCI_A3->IE &= ~EUSCI_A_IE_TXIE;    //disabling transmit interrupt
            }
        }
}



/*----------------------------------------------------------------------------
@brief: SPI IRQ handler
@resource: example mentioned in assignment document
 ----------------------------------------------------------------------------*/
void EUSCIB3_IRQHandler(void)
{
    if (EUSCI_B3->IFG & EUSCI_B_IFG_TXIFG)
    {
        EUSCI_B3->TXBUF = spi_tx_data;           // Transmit characters
        EUSCI_B3->IE &= ~EUSCI_B__TXIE;     //disabling tx interrupt

        // Wait till a character is received
        //while (!(EUSCI_B0->IFG & EUSCI_B_IFG_RXIFG));

        // USCI_B0 TX buffer ready?
        while (!(EUSCI_B3->IFG & EUSCI_B_IFG_TXIFG));
    }

    if(EUSCI_B3->IFG & EUSCI_B_IFG_RXIFG)
    {
        spi_rx_data = EUSCI_B3->RXBUF;

        // Clear the receive interrupt flag
        EUSCI_B3->IFG &= ~EUSCI_B_IFG_RXIFG;
    }
}

