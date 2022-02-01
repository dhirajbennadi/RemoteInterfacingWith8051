/****************************************************************************
 * gpio.c
 * This file initializes gpios
 *
 *  Created on: Nov 3, 2021
 *  @author: Dhiraj Bennadi
 ****************************************************************************/

#include "gpio.h"
#include "msp.h"
#include "uart.h"
#include "timers.h"

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

        // Set P2.4 to output direction
        SPI_CS_PORT->DIR |= SPI_CS_PIN;
        SPI_CS_PORT->OUT |= SPI_CS_PIN;

        /*Set Output of Port 6 Pin 5*/
        AT8051_CTRL_PORT->OUT |= AT8051_PSEN_PIN;
        /*Set Output of Port 6 Pin 4*/
        AT8051_CTRL_PORT->OUT &= ~AT8051_RESET_PIN;

        /*Set Data Direction of Port 6 Pin 4*/
        AT8051_CTRL_PORT->DIR |= AT8051_RESET_PIN;

        /*Set Data Direction of Port 6 Pin 5*/
        AT8051_CTRL_PORT->DIR |= AT8051_PSEN_PIN;


#ifdef TEST_ON_OSCILLOSCOPE
        P1->DIR |= BIT5;
#endif


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


/*----------------------------------------------------------------------------
 * Enter 8051 into bootloader mode
 * Sequence: RESET HIGH -> PSEN LOW -> RESET LOW -> PSEN HIGH
 * (refer gpio.h for more details)
 ----------------------------------------------------------------------------*/
void enter_8051_into_bootloader()
{
    /*Reset*/
    delay(150000);
    AT8051_CTRL_PORT->OUT |= AT8051_RESET_PIN;
    delay(150000);
    /*PSEN*/
    AT8051_CTRL_PORT->OUT &= ~AT8051_PSEN_PIN;
    delay(150000);

    AT8051_CTRL_PORT->OUT &= ~AT8051_RESET_PIN;
    delay(150000);

    AT8051_CTRL_PORT->OUT |= AT8051_PSEN_PIN;
    delay(150000);


}

/*----------------------------------------------------------------------------
 * Enter 8051 into application mode
 * (refer gpio.h for more details)
 ----------------------------------------------------------------------------*/
void reset_8051()
{
    delay(100000);
    /*Reset*/
    AT8051_CTRL_PORT->OUT |= AT8051_RESET_PIN;
    delay(100000);

    AT8051_CTRL_PORT->OUT &= ~AT8051_RESET_PIN;
    delay(100000);

}
