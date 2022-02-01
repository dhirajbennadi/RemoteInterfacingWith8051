/***************************************************************************************
 * @file main.c :
 * @brief : application entry point
 *
 * @author :Rajat Chaple
 ****************************************************************************************/

/**************Includes************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "cbfifo.h"
#include "msp.h"
#include "uart.h"
#include "cmd_processor.h"
#include "msp.h"
#include "timers.h"
#include "gpio.h"
#include "temp.h"


extern cbfifo_t cbfifo_transmit;
extern cbfifo_t cbfifo_receive;
extern bool temp_ready_status;


/**=================================================================================
 * Application entry point
 ==================================================================================*/
void main(void)
{

    float ref_temp = 0; //for detecting changee in temperature
    float temp_diff = 0;
    float temperature;
    int new_pwm_duty;
    int8_t c;


    WDT_A->CTL = WDT_A_CTL_PW |             // Stop watchdog timer
            WDT_A_CTL_HOLD;


    //initiating system clock
    CS->KEY = CS_KEY_VAL;                   // Unlock CS module for register access
    CS->CTL0 = 0;                           // Reset tuning parameters
    CS->CTL0 = CS_CTL0_DCORSEL_3;           // Set DCO to 12MHz (nominal, center of 8-16MHz range)
    CS->CTL1 = CS_CTL1_SELA_2 |             // Select ACLK = REFO
            CS_CTL1_SELS_3 |                // SMCLK = DCO
            CS_CTL1_SELM_3;                 // MCLK = DCO
    CS->KEY = 0;                            // Lock CS module from unintended accesses


    init_gpio();
    init_timer();
    uart_init();
    init_temp();    //initiates ADC


    // Enable global interrupt
    __enable_irq();


    putstr("\r\n--------------------------------------------------------------------------------\r\n");
    putstr("Welcome to MSP432 serial!\r\n? ");

    // entering infinite loop
    while (1) {


        c = getchar();

        if(temp_ready_status == true)
        {
            temperature = get_temp();   //store current temperature

            if(ref_temp == 0)
            {
                ref_temp = temperature;
            }
            else
            {
                temp_diff = (float)temperature - (float)ref_temp;
                if((temp_diff) >= 0.5)
                {
                    if(get_pwm_duty_cycle() + PWM_STEP_SIZE < 100)  //verifying that pwm hasn't increased beyond 100%
                    {
                        new_pwm_duty = get_pwm_duty_cycle() + (int)(PWM_STEP_SIZE * ((int)(temp_diff*20) / 10));
                        set_pwm_duty_cycle(new_pwm_duty);
                    }
                    //	                  putstr("\r\n\tPWM changed to ");
                    //	                  putstr(num_to_str(new_pwm_duty));
                    //	                  putstr("% because of temp rise");
                    //	                  printf("temperature changed %f %f %f\n", ref_temp, temperature, (temp_diff));
                    ref_temp = temperature;
                }

                if((temp_diff) <= -0.5)
                {
                    if(get_pwm_duty_cycle() - PWM_STEP_SIZE > 0)  //verifying that pwm hasn't decreased below 100%
                    {
                        new_pwm_duty = get_pwm_duty_cycle() + (int)(PWM_STEP_SIZE * ((int)(temp_diff*20) / 10));
                        set_pwm_duty_cycle(new_pwm_duty);
                    }
                    //	                    putstr("\r\n\tPWM changed to ");
                    //                      putstr(num_to_str(new_pwm_duty));
                    //                      putstr("% because of temp fall");
                    //                      printf("temperature changed %f %f %f\n", ref_temp, temperature, (temp_diff));
                    ref_temp = temperature;
                }

            }
        }


        //echoing characters back to serial
        echo(c);

        process_char_command(c);

    }

}
