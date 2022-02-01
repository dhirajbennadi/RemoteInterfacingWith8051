/***************************************************************************************
 * @file cmd_processor.c :
 * @brief : This file contains functions to perform lexical analysis to extract commands
 * 			over serial input and run respective handlers
 *
 * @author : Rajat Chaple (rajat.chaple@colorado.edu)
 *
 ****************************************************************************************/

/*Includes*/
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "uart.h"
#include "cmd_processor.h"
#include "temp.h"
#include "timers.h"
#include "gpio.h"
#include "msp.h"

/*Defines*/
extern temp_unit_t temp_unit;



/*--------------------------------------------------------------------------------
* command processor function to carry functions related to commands provided
* (please refer cmd_processor.h for additional details)

--------------------------------------------------------------------------------*/
void process_char_command(char c)
{
    int new_pwm_duty_cycle;
    int new_temp_unit;
    int new_period;
    int prev_duty_cycle;
    int r = 0;
    int g = 0;
    int b = 0;



  switch(c)
  {
      case 'P':
          putstr("\r\n\t\t** Command received for printing duty cycle **\r\n");
          putstr("\r\n---> PWM duty cycle : ");
          putstr(num_to_str(get_pwm_duty_cycle()));
          putstr("\r\n--------------------------------------------------------------------------------\r\n");
          putstr("\r\n\r\n? "); //ready for next command
          break;

      case 'T':
          putstr("\r\n\t\t** Command received for Temperature **\r\n");
          putstr("\r\n---> Temperature : ");
          putstr(num_to_str(get_temp()));
          putstr("\r\n--------------------------------------------------------------------------------\r\n");
          putstr("\r\n\r\n? "); //ready for next command
         break;

      case 'D':
          putstr("\r\n\t\t** Command received for changing duty cycle **\r\n");
          putstr("\r\n\t\tEnter duty cycle value (0 to 100%): ");
          new_pwm_duty_cycle = accept_number_from_user();
          if((new_pwm_duty_cycle > 100) || (new_pwm_duty_cycle < 0))
          {
              putstr("\r\nError: Incorrect value for duty cycle(\r\n");
              process_char_command('D');

          }
          else
          {
              putstr("\r\n\tPWM duty cycle changed to: ");
              putstr(num_to_str(new_pwm_duty_cycle));
              putstr("\r\n--------------------------------------------------------------------------------\r\n");
              putstr("\r\n? ");
              set_pwm_duty_cycle(new_pwm_duty_cycle);
          }

          break;

      case 'U':
          putstr("\r\n\t\t** Command received for changing Temp unit **\r\n");
          putstr("\r\n\t\t Select unit:\r\n\t\t\t1.Temperature in Celcius\r\n\t\t\t2.Temperature in Fahrenheit\r\n\t\t\t Input:");
          new_temp_unit = accept_number_from_user();
          if(new_temp_unit == 1)
          {
              temp_unit = TEMP_CELCIUS;
          }
          else if(new_temp_unit == 2)
          {
              temp_unit = TEMP_FAHRENHEIT;
          }
          else
          {
              putstr("\r\nError: Incorrect value for temperature unit(\r\n");
              process_char_command('U');
          }
          putstr("\r\n--------------------------------------------------------------------------------\r\n");
          putstr("\r\n? ");
          break;

      case 'S':
          putstr("\r\n\t\t** Command received for changing PWM Period **\r\n");
          putstr("\r\n\t\tEnter PWM period value (uS): ");
          new_period = accept_number_from_user();
          prev_duty_cycle = get_pwm_duty_cycle();
          set_pwm_period(new_period);
          set_pwm_duty_cycle(prev_duty_cycle);
          putstr("\r\n--------------------------------------------------------------------------------\r\n");
          putstr("\r\n? ");
          break;

      case 'B':
          putstr("\r\n\t\t** Command received for blinky LED pattern **\r\n");
          Port_Mapping();

          while(r != 45000)
          {
              led_pattern(r, g, b);
              r+=500;
              delay();

          }
          r = 0;
          while(g != 45000)
          {
                led_pattern(r, g++, b);
                g+=500;
                delay();
          }
          g = 0;
          while(b != 45000)
          {
                  led_pattern(r, g, b++);
                  b+=500;
                  delay();
          }
          r = 0;
                   g = 0;
                   b = 0;
         while(r != 45000)
        {
              led_pattern(r++, g++, b++);
              r+=500;
              g+=500;
              b+=500;
              delay();
        }
         r = 0;
         g = 0;
         b = 0;
         init_gpio();
         putstr("\r\n--------------------------------------------------------------------------------\r\n");
         putstr("\r\n? ");
          break;


      default:
          break;

  }

}

