/***********************************************************************************
 * gpio.h
 * This file contains declarations, typedefs and function prototypes for gpio.c
 *
 *  Created on: Nov 1, 2021
 *  @author: Dhiraj Bennadi
 ***********************************************************************************/

#ifndef GPIO_H_
#define GPIO_H_

/*--------------- Defines---------------*/
#define RED_LED_PORT    P2
#define RED_LED_PIN     BIT0

#define GREEN_LED_PORT    P2
#define GREEN_LED_PIN     BIT1

#define BLUE_LED_PORT    P2
#define BLUE_LED_PIN     BIT2

#define SWITCH1_PORT    P1  //right switch
#define SWITCH1_PIN     BIT1

#define SWITCH2_PORT    P1
#define SWITCH2_PIN     BIT4

#define SPI_CS_PORT     P6
#define SPI_CS_PIN      BIT7

#define AT8051_CTRL_PORT (P6)
#define AT8051_RESET_PIN  (BIT4)
#define AT8051_PSEN_PIN  (BIT5)

//#define TEST_ON_OSCILLOSCOPE

/*--------------- Datatypes-------------*/
typedef enum led_color{
    OFF,    //000
    BLUE,   //001
    GREEN,  //010
    CYAN,   //011 -> GREEN+BLUE
    RED,    //100
    MAGENTA,//101 -> RED+BLUE
    YELLOW, //110
    WHITE   //111 -> WHITE
}led_color_t;

/*----------function prototypes--------*/
void init_gpio(void);
void set_led(led_color_t color);
void Port_Mapping(void);
void enter_8051_into_bootloader(void);
void reset_8051();

#endif /* GPIO_H_ */
