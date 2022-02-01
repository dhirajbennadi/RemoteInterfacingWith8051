/***************************************************************************************
 * @file uart.c :
 * @brief : This file contains UART initialization and functions for UART handling
 *
 * @author : Rajat Chaple (rajat.chaple@colorado.edu)
 * @date : Oct 22 2021
 *
 ****************************************************************************************/

/*---Includes---*/
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "msp.h"
#include "uart.h"
#include "cbfifo.h"

/*---Defines---*/
//This is a configuration for UART0
#define BAUD_RATE			(38400)		//desired baud rate for UART0
#define DATA_SIZE			(8)			//desired data size in bits for UART0
#define PARITY				(0)			//No parity for UART0
#define STOP_BITS			(2)			//Two stop bits for UART0
#define OVERSAMPLING_RATE	(16)

extern cbfifo_t cbfifo_transmit;
extern cbfifo_t cbfifo_receive;

//#define OVERRIDE_STDIO_FUNCTIONS

/*----------------------------------------------------------------------------
 * Initializing UART0
 * (refer uart.h for additional details)
 * @Resource : This function is written with the help of example code provided
 * in assignment document
 ----------------------------------------------------------------------------*/
void uart_init()
{
    // Configure UART pins
    P1->SEL0 |= BIT2 | BIT3;                // set 2-UART pin as secondary function

    // Configure UART
    EUSCI_A0->CTLW0 |= EUSCI_A_CTLW0_SWRST; // Put eUSCI in reset
    EUSCI_A0->CTLW0 = EUSCI_A_CTLW0_SWRST | // Remain eUSCI in reset
            EUSCI_B_CTLW0_SSEL__SMCLK;      // Configure eUSCI clock source for SMCLK
    // Baud Rate calculation
    // 12000000/(16*9600) = 78.125
    // Fractional portion = 0.125
    // User's Guide Table 21-4: UCBRSx = 0x10
    // UCBRFx = int ( (78.125-78)*16) = 2
    EUSCI_A0->BRW = 78;                     // 12000000/16/9600
    EUSCI_A0->MCTLW = (2 << EUSCI_A_MCTLW_BRF_OFS) |
            EUSCI_A_MCTLW_OS16;

    EUSCI_A0->CTLW0 &= ~EUSCI_A_CTLW0_SWRST; // Initialize eUSCI
    EUSCI_A0->IFG &= ~EUSCI_A_IFG_RXIFG;    // Clear eUSCI RX interrupt flag
    EUSCI_A0->IE |= EUSCI_A_IE_RXIE;        // Enable USCI_A0 RX interrupt


    // Enable eUSCIA0 interrupt in NVIC module
    NVIC->ISER[0] |= 1 << ((EUSCIA0_IRQn) & 31);

}

/*----------------------------------------------------------------------------
 * This function echoes back characters to serial output
 * (refer uart.h for additional details)
 ----------------------------------------------------------------------------*/
void echo(char c)
{
    char str[1] = c;
    //str[1] = 0;

	 switch((int8_t)c)
	  {

	 	 //no new character available
	  case -1:
		  break;

		  //user presses backspace
	  case '\b':
		    putstr("\b \b");
		  break;

		  //user presses enter
	  case '\r':
		  putstr("\r\n");
		  break;

	  case 0xFF:
	      break;

		  //echoing received chars
	  default:
		  putstr(str);
		  break;
	  }
}

/*----------------------------------------------------------------------------
 * This function forms a line of command as characters are entered over serial
 * (refer uart.h for additional details)
 ----------------------------------------------------------------------------*/
char* get_line_of_command_raw(int8_t c, uint32_t* num_of_chars_entered_per_command)
{
	static char input_raw[1024] = {0};
	static char* p = input_raw;

	char* ret = NULL;

	switch(c)
		  {
			//no new character available
		  case -1:
			  break;

			  //user presses backspace
		  case '\b':
			  if(p != input_raw)
			  {
				  *p-- = '\0';
				  (*num_of_chars_entered_per_command)--;
			  }
			  break;

			  //user presses enter
		  case '\r':
			  *p++ = '\0';
			  *num_of_chars_entered_per_command = 0;
			  ret = input_raw;
			  p = input_raw;
 			  break;

 			  //append characters to command line string
		  default:
			  *p++ = c;
			  (*num_of_chars_entered_per_command)++;
			  break;
		  }

	return ret;

}


/********************************************************************
// Converts number to string
*********************************************************************/
char* num_to_str(float num)
{
    char text[100];
    memset(text, 0, 100);
    sprintf(text, "%.2f", num);
    return text;
}

/********************************************************************
//Sends string oveer UART
*********************************************************************/
int putstr(char *buf)
{
    uint32_t masking_state;
    int num_of_enqueued_elements = 0;
    int remaining_elements = strlen(buf);
    static char* character_buffer;
    character_buffer = buf;

    //as buf might be larger than available space in cbfifo
    while(remaining_elements)
    {
        //Entering critical section
        masking_state = __get_PRIMASK();
        __disable_irq();
        num_of_enqueued_elements = cbfifo_enqueue(&cbfifo_transmit, character_buffer, remaining_elements);
        __set_PRIMASK(masking_state);

        //updating remaining data
        remaining_elements = remaining_elements - num_of_enqueued_elements;
        character_buffer += num_of_enqueued_elements;

        if((remaining_elements == 0) ||
                (cbfifo_length(&cbfifo_transmit) == cbfifo_capacity(&cbfifo_transmit)))
        {
            //enabling transmit interrupt
            EUSCI_A0->IE |= EUSCI_A_IE_TXIE;
        }
    }

    return 0;
}



/********************************************************************
// receive a character from user input
*********************************************************************/
int getchar()
{
    int c = 0;
    uint32_t masking_state;
    //returns -1 to indicate that no new char has received
    if(cbfifo_length(&cbfifo_receive) < 1)
    {
        return -1;
    }
    else
    {
        //Entering critical section
        masking_state = __get_PRIMASK();
        __disable_irq();
        cbfifo_dequeue(&cbfifo_receive, &c, sizeof(c));
        __set_PRIMASK(masking_state);
        return c;
    }
}


/********************************************************************
// receive a number from user input
// Returns length of printed string with null char
*********************************************************************/
int accept_number_from_user()
{
    char received_char = '`';
    char number_in_char[25] = "\0";
    bool valid_number_status = false;
    int number = 0;
    int i = 0;
    while (valid_number_status == false)
    {
        received_char = (char)getchar();

        if(received_char == 0xFF)
                continue;

        echo(received_char);

        i++;
        // if(received_char is in range of allowable values) //sanity check for alphabetical chars
        if (!(received_char >= '0' && received_char <= '9') && (received_char != '\r'))
        {
            valid_number_status = false;
            memset(number_in_char, 0, strlen(number_in_char));
            //putstr("\r\n\t\t Error: Re-enter the number: ");
            i = 0;

        }
        else if (received_char == '\r')
        {
            strcat(number_in_char, '\0');
            number = atoi(number_in_char);
            valid_number_status = true;
            //return number;
        }
        strncat(number_in_char, &received_char, 1);

        if (i >= 24)
        {
            putstr("\r\n\t\t Error: Reading a number failed, Reached maximum length supported");
            putstr("\r\n\t\t Error: Re-enter the number: ");
            valid_number_status = false;
            memset(number_in_char, 0, sizeof(number_in_char));
            i = 0;
        }
    }
    return number;
}

