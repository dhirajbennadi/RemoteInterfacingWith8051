/****************************************************************************
 * gpio.c
 * This file initializes gpios
 *
 *  Created on: Oct 22, 2021
 *      Author: Rajat
 ****************************************************************************
 ****************************************************************************/
#include "gpio.h"
#include "msp.h"


// Port2 Port Mapping definitions
const uint8_t P2Mapping[8] = {
        PMAP_TA0CCR1A,
        PMAP_TA0CCR2A,
        PMAP_TA0CCR3A,
        PMAP_NONE
};
/*----------------------------------------------------------------------------
 * Initializes pins to Inputs and outputs as defined in gpio_init.h
 * (refer gpio.h for more details)
 ----------------------------------------------------------------------------*/
void init_gpio()
{
       // Set P2.0 to output direction
        RED_LED_PORT->DIR |= RED_LED_PIN;
        // Set P2.1 to output direction
        GREEN_LED_PORT->DIR |= GREEN_LED_PIN;
        // Set P2.2 to output direction
        BLUE_LED_PORT->DIR |= BLUE_LED_PIN;


#ifdef TEST_ON_OSCILLOSCOPE
        P1->DIR |= BIT5;
#endif


        // Configuring P1.4 as input and respective interrupt
         SWITCH1_PORT->DIR = ~((uint8_t) SWITCH1_PIN | (uint8_t) SWITCH2_PIN);
         SWITCH1_PORT->OUT = SWITCH1_PIN | SWITCH2_PIN;
         SWITCH1_PORT->REN = SWITCH1_PIN | SWITCH2_PIN;                         // Enable pull-up resistor (SWITCH_PORT.1 output high)
         SWITCH1_PORT->SEL0 = 0;
         SWITCH1_PORT->SEL1 = 0;
         //SWITCH1_PORT->IES = SWITCH1_PIN | SWITCH2_PIN;                         // Interrupt on high-to-low transition
         SWITCH1_PORT->IFG = 0;                            // Clear all SWITCH_PORT interrupt flags
         SWITCH1_PORT->IE = SWITCH1_PIN | SWITCH2_PIN;                          // Enable interrupt for P1.1


         // Enable Port 1 interrupt on the NVIC
         NVIC->ISER[1] |= 1 << ((PORT1_IRQn) & 31);


         // Configure GPIO for PWM
              P7->DIR |= BIT6;                 // P7.6~7 set TA1.1~2
              P7->SEL0 |= BIT6;
              P7->SEL1 &= ~(BIT6);

}

/*----------------------------------------------------------------------------
 * Maps pins to PWM timers
 * (refer gpio.h for more details)
 * @resource : example code from TI
 ----------------------------------------------------------------------------*/
void Port_Mapping()
{
    uint8_t i;
    uint32_t interruptState;
    volatile uint8_t *ptr;

    // Get the current interrupt state and store it temporarily
    interruptState = __get_PRIMASK();

    // Disable the global interrupt before configuring the
    // port mapping registers
    __disable_irq();

    PMAP->KEYID = PMAP_KEYID_VAL;                  // Enable Write-access to modify port mapping registers

    #ifdef PORT_MAP_RECFG
    PMAP->CTL = PMAP_CTL_PRECFG;            // Allow reconfiguration during runtime
    #endif


    P2MAP->PMAP_REGISTER0 = 23;
    P2MAP->PMAP_REGISTER1 = 24;
    P2MAP->PMAP_REGISTER2 = 25;

    PMAP->KEYID = 0;                        // Disable Write-Access to modify port mapping registers

    // Setup Port Pins
        P2->DIR = 0x07;                         // P2.0 - P2.7 output
        P2->SEL0 = 0x07;                        // P2.0 - P2.6 Port Map functions
        P2->SEL1 &= ~0x07;                           // P2.0 - P2.6 Port Map functions

    // Re-configure the interrupt if it was enabled
    __set_PRIMASK(interruptState);




}


/*----------------------------------------------------------------------------
 * Sets Led color to passed parameter
 * (refer gpio.h for more details)
 ----------------------------------------------------------------------------*/
void set_led(led_color_t color)
{
    if(color & 0b001)   //Checking if Blue LED needs to be turned or
    {
        BLUE_LED_PORT->OUT |= BLUE_LED_PIN;   //Turns Blue LED ON
    }
    else
    {
        BLUE_LED_PORT->OUT &= ~BLUE_LED_PIN;  //Turns Blue LED off
    }

    if(color & 0b010)   //Checking if Green LED needs to be turned or
    {
        GREEN_LED_PORT->OUT |= GREEN_LED_PIN; //Turns Green LED on
    }
    else
    {
        GREEN_LED_PORT->OUT &= ~GREEN_LED_PIN; //Turns Green LED off
    }

    if(color & 0b100)   //Checking if Red LED needs to be turned or
    {
        RED_LED_PORT->OUT |= RED_LED_PIN;   //Turns Red LED on
    }
    else
    {
        RED_LED_PORT->OUT &= ~RED_LED_PIN;   //Turns Red LED off
    }

}


