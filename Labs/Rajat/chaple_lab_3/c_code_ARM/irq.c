/*****************************************************************************************
 * @file irq.c :
 * @brief : This file contains interrupt handlers for peripherals
 *
 * @author : Rajat Chaple (rajat.chaple@colorado.edu)
 * @date : Oct 22, 2021
 *
******************************************************************************************/

#include "msp.h"
#include "cbfifo.h"
#include "gpio.h"
#include "stdbool.h"
#include "timers.h"
#include "uart.h"
#include "temp.h"

extern cbfifo_t cbfifo_transmit;
extern cbfifo_t cbfifo_receive;



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
static float IntDegC = 0;

bool temp_ready_status = false;

temp_unit_t temp_unit = TEMP_CELCIUS;

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
            if(cbfifo_length(&cbfifo_receive) != cbfifo_capacity(&cbfifo_receive)) //if fifo not full
            {
                //entering critical section
                masking_state = __get_PRIMASK();
                __disable_irq();
                cbfifo_enqueue(&cbfifo_receive, &RXData, sizeof(RXData));   //adding element to the queue
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
            if(cbfifo_length(&cbfifo_transmit) != 0)
            {
                //entering critical section
                masking_state = __get_PRIMASK();
                __disable_irq();
                 if(cbfifo_dequeue(&cbfifo_transmit, &TXData, 1) == 1)  //dequeue elemnt to be sent
                     EUSCI_A0->TXBUF = TXData;
                __set_PRIMASK(masking_state);
            }
            else
            {
                EUSCI_A0->IE &= ~EUSCI_A_IE_TXIE;    //disabling transmit interrupt
            }
        }
}


/*----------------------------------------------------------------------------
 * Interrupt handler for TimerA. Used for debounce
  ----------------------------------------------------------------------------*/
void TA3_0_IRQHandler(void)
{
    TIMER_A3->CCTL[0] &= ~TIMER_A_CCTLN_CCIFG;
    //5 ms has elapsed
    SWITCH1_PORT->IES = 1;                         // enabling interrupt
    SWITCH2_PORT->IES = 1;                         // enabling interrupt
}


/*----------------------------------------------------------------------------
 * Interrupt handler for TimerA. Used for temperature measurement delay
  ----------------------------------------------------------------------------*/
void TA2_0_IRQHandler(void)
{
    TIMER_A2->CCTL[0] &= ~TIMER_A_CCTLN_CCIFG;
    start_temp_measurement();
    P1->OUT ^= BIT5;
}

/*----------------------------------------------------------------------------
PORT1 IRQ handler
 ----------------------------------------------------------------------------*/
void PORT1_IRQHandler(void)
{

    if(P1->IFG & BIT1)  //Interrupt for switch 1
    {
        set_led(GREEN);
        if(get_pwm_duty_cycle() + PWM_STEP_SIZE < 100)  //verifying that pwm hasn't increased beyond 100
        {
           set_pwm_duty_cycle(get_pwm_duty_cycle() + PWM_STEP_SIZE);//increase
           putstr("\r\n\t\tPWM duty cycle increased by 10. set to ");
           putstr(num_to_str(get_pwm_duty_cycle()));
           putstr("\r\n?");
        }


    }
    else if(P1->IFG & BIT4)
    {
        set_led(RED);
        if(get_pwm_duty_cycle() - PWM_STEP_SIZE > 0)  //verifying that pwm hasn't decreased below 0
        {
            set_pwm_duty_cycle(get_pwm_duty_cycle() - PWM_STEP_SIZE);//increase
            putstr("\r\n\t\tPWM duty cycle decreased by 10. set to ");
           putstr(num_to_str(get_pwm_duty_cycle()));
           putstr("\r\n?");
        }
    }

    SWITCH1_PORT->IFG &= ~((uint8_t)SWITCH1_PIN | (uint8_t)SWITCH2_PIN);    //switch2 has same port

    toggle_state_by_switch = !toggle_state_by_switch;

    //disable interrupt until debounce timer has elapsed
    SWITCH1_PORT->IES = 0;
    SWITCH2_PORT->IES = 0;

    set_led(OFF);
}



/*----------------------------------------------------------------------------
@brief: ADC14 IRQ handler
@resource: example mentioned in assignment document
 ----------------------------------------------------------------------------*/
void ADC14_IRQHandler(void)
{
    //setting up calibration value
    int32_t adcRefTempCal_1_2v_30 = TLV->ADC14_REF1P2V_TS30C;
    int32_t adcRefTempCal_1_2v_85 = TLV->ADC14_REF1P2V_TS85C;

uint32_t masking_state;
    masking_state = __get_PRIMASK();    //saving PRIMASK. TO be used later below.
            __disable_irq();

    if (ADC14->IFGR0 & ADC14_IFGR0_IFG0)
    {
        temp = ADC14->MEM[0];
        IntDegC = (((float) temp - adcRefTempCal_1_2v_30) * (85 - 30)) /
                            (adcRefTempCal_1_2v_85 - adcRefTempCal_1_2v_30) + 30.0f;    //calculating temperature in Celcius

        // Temperature in Fahrenheit
        IntDegF = ((9 * IntDegC) / 5) + 32; //calculating temperature in Farheneit

        temp_ready_status = true;
    }
    __set_PRIMASK(masking_state);


}

/*----------------------------------------------------------------------------
@brief: An API to retrieve temperature
 ----------------------------------------------------------------------------*/
float get_temp()
{

    temp_ready_status = false;
    //returns temperature depending upon unit set
    if(temp_unit == TEMP_CELCIUS)
        return IntDegC;
    else if(temp_unit == TEMP_FAHRENHEIT)
        return IntDegF;

    return IntDegC;
}
