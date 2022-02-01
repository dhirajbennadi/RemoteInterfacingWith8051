/*************************************************
 * @filename : main.c
 * @author   : Dhiraj Bennadi
 * @compiler : arm
 * @IDE      : Code Blocks
 *
 * Identification of any leveraged code : None
 * Applicable Links: None
 */

#include <mcs51/8051.h>
#include <at89c51ed2.h>
#include <mcs51reg.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "uart.h"



/*
 * @brief Startup code
 *
 * @param None
 *
 * @return None
 */
_sdcc_external_startup()
{
    AUXR |= 0X0C;
    return 0;
}


/*
 * @brief Initializes the INTO Interrupt
 *
 * @param None
 *
 * @return None
 */
void init_interrupt()
{
    IE = 0x81;
    IT0 = 1;
    EX0 = 1;
    EA = 1;
}


/*
 * @brief INT0 ISR Service Routine
 *
 * @param None
 *
 * @return None
 */
void isr_zero(void) __interrupt (IE0_VECTOR)
{
    //P1_0 = ~(P1_0);
    //PCON &= ~(0x01);
}
void setIdleMode(){
    PCON |= 0x01;
    printf("Idle Mode Set\n\r");
}

void setPowerDownMode(){
    PCON |= 0x02;
}

void max_frequency(){
    CKRL = 0xFF;
}

void min_frequency(){
    CKRL = 0x00;
}

void initPWM(){
    CMOD |= 0x02;
    CCAPM0 &= ~0xFF;
    CCAPM0 |= 0x42;

    CCAP0L &= ~0xFF;
    CCAP0H &= ~0xFF;

    CCAP0L = 0x4C;
    CCAP0H = 0x4C;
    CCON |= 0x40; //Enable counter - PCA run control bit

}
void main(void)
{
    CKCON0 |= 0x01; //X2 Mode

    P1 |= 0xFF;

    setPowerDownMode();

    //setIdleMode();

    //initPWM();

    //max_frequency();

    //min_frequency();



    uint16_t counter = 0;
    while(1)
    {
        counter++;
        if(counter == 0xFFFF)
        {
            counter = 0;
            P1_0 ^= P1_0;
        }
    }


}

