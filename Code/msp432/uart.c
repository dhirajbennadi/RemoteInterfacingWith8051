/***************************************************************************************
 * @file uart.c :
 * @brief : This file contains UART initialization and functions for UART handling
 *
 * @author : Dhiraj Bennadi
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

/*---Variables---*/


extern cbfifo_t cbfifo_transmit_uart0;
extern cbfifo_t cbfifo_receive_uart0;

extern cbfifo_t cbfifo_transmit_uart2;
extern cbfifo_t cbfifo_receive_uart2;

extern cbfifo_t cbfifo_transmit_uart3;
extern cbfifo_t cbfifo_receive_uart3;

/*----------------------------------------------------------------------------
 * Initializing UART0
 * (refer uart.h for additional details)
 * @Resource : This function is written with the help of example code provided
 * in assignment document
 ----------------------------------------------------------------------------*/
void uart_init()
{
    //----------------------------Configure UART pins-----------------------------
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
    


    //-------------------configuring UART2----------------------------
    // Configure UART pins
    P3->SEL0 |= 0x0C;           // Configure P3.2(RXD) and P3.3(TXD) as UART port
    P3->SEL1 &= ~0x0C;

    // Configure UART
    EUSCI_A2->CTLW0 |= EUSCI_A_CTLW0_SWRST; // Put eUSCI in reset
    EUSCI_A2->CTLW0 = EUSCI_A_CTLW0_SWRST | // Remain eUSCI in reset
            EUSCI_B_CTLW0_SSEL__SMCLK;      // Configure eUSCI clock source for SMCLK
    // Baud Rate calculation
    // 12000000/(16*9600) = 78.125
    // Fractional portion = 0.125
    // User's Guide Table 21-4: UCBRSx = 0x10
    // UCBRFx = int ( (78.125-78)*16) = 2
    EUSCI_A2->BRW = 78;//6;//(115200);                     // 12000000/16/9600
    EUSCI_A2->MCTLW = (2 << EUSCI_A_MCTLW_BRF_OFS) |    //8 (115200)
            EUSCI_A_MCTLW_OS16;

    EUSCI_A2->CTLW0 &= ~EUSCI_A_CTLW0_SWRST; // Initialize eUSCI
    EUSCI_A2->IFG &= ~EUSCI_A_IFG_RXIFG;    // Clear eUSCI RX interrupt flag
    EUSCI_A2->IE |= EUSCI_A_IE_RXIE;        // Enable USCI_A0 RX interrupt

    // Enable eUSCIA0 interrupt in NVIC module
    NVIC->ISER[0] |= 1 << ((EUSCIA2_IRQn) & 31);


    //configuring UART3
    // Configure UART pins
    P9->SEL0 |= BIT6 | BIT7;           // Configure P3.2(RXD) and P3.3(TXD) as UART port
    //P9->SEL1 &= ~0x0C;
    //P9->SEL0 &= ~(BIT6 | BIT7);

    // Configure UART
    EUSCI_A3->CTLW0 |= EUSCI_A_CTLW0_SWRST; // Put eUSCI in reset
    EUSCI_A3->CTLW0 = EUSCI_A_CTLW0_SWRST | // Remain eUSCI in reset
            EUSCI_B_CTLW0_SSEL__SMCLK;      // Configure eUSCI clock source for SMCLK
    // Baud Rate calculation
    // 12000000/(16*9600) = 78.125
    // Fractional portion = 0.125
    // User's Guide Table 21-4: UCBRSx = 0x10
    // UCBRFx = int ( (78.125-78)*16) = 2
    EUSCI_A3->BRW = 78;                     // 12000000/16/9600
    EUSCI_A3->MCTLW = (2 << EUSCI_A_MCTLW_BRF_OFS) |
            EUSCI_A_MCTLW_OS16;

    EUSCI_A3->CTLW0 &= ~EUSCI_A_CTLW0_SWRST; // Initialize eUSCI
    EUSCI_A3->IFG &= ~EUSCI_A_IFG_RXIFG;    // Clear eUSCI RX interrupt flag
    EUSCI_A3->IE |= EUSCI_A_IE_RXIE;        // Enable USCI_A0 RX interrupt

    // Enable eUSCIA0 interrupt in NVIC module
    NVIC->ISER[0] |= 1 << ((EUSCIA3_IRQn) & 31);

}

/*----------------------------------------------------------------------------
 * This function echoes back characters to serial output
 * (refer uart.h for additional details)
 ----------------------------------------------------------------------------*/
void echo(char c)
{
    char str[1] = {c};
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
 * This function echoes back characters to serial output
 * (refer uart.h for additional details)
 ----------------------------------------------------------------------------*/
void echo_uart2(char c)
{
    char str[1] = {c};
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
          putstr_uart2("\r\n");
          break;

      case 0xFF:
          break;

          //echoing received chars
      default:
          putstr_uart2(str);
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

/*----------------------------------------------------------------------------
 * This function forms a line of command as characters are entered over serial
 * (refer uart.h for additional details)
 ----------------------------------------------------------------------------*/
void get_esp32_response(char* readline)
{
    char* p = readline;

    int received_char = -1;

    while(1)
    {
        received_char = getchar_uart2();
        if(received_char != -1)
        {
            //echo(received_char);

            if(/*received_char == '\r' || */received_char == '\n')
                break;
            else
                *p++ = (char)received_char;
        }

    }
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
        num_of_enqueued_elements = cbfifo_enqueue(&cbfifo_transmit_uart0, character_buffer, remaining_elements);
        __set_PRIMASK(masking_state);

        //updating remaining data
        remaining_elements = remaining_elements - num_of_enqueued_elements;
        character_buffer += num_of_enqueued_elements;

        if((remaining_elements == 0) ||
                (cbfifo_length(&cbfifo_transmit_uart0) == cbfifo_capacity(&cbfifo_transmit_uart0)))
        {
            //enabling transmit interrupt
            EUSCI_A0->IE |= EUSCI_A_IE_TXIE;
        }
    }

    return 0;
}


/********************************************************************
//Sends string oveer UART
*********************************************************************/
int putstr_uart2(char *buf)
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
        num_of_enqueued_elements = cbfifo_enqueue(&cbfifo_transmit_uart2, character_buffer, remaining_elements);
        __set_PRIMASK(masking_state);

        //updating remaining data
        remaining_elements = remaining_elements - num_of_enqueued_elements;
        character_buffer += num_of_enqueued_elements;

        if((remaining_elements == 0) ||
                (cbfifo_length(&cbfifo_transmit_uart2) == cbfifo_capacity(&cbfifo_transmit_uart2)))
        {
            //enabling transmit interrupt
            EUSCI_A2->IE |= EUSCI_A_IE_TXIE;
        }
    }

    return 0;
}

/********************************************************************
//Sends string over UART3
*********************************************************************/
int putstr_uart3(char *buf)
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
        num_of_enqueued_elements = cbfifo_enqueue(&cbfifo_transmit_uart3, character_buffer, remaining_elements);
        __set_PRIMASK(masking_state);

        //updating remaining data
        remaining_elements = remaining_elements - num_of_enqueued_elements;
        character_buffer += num_of_enqueued_elements;

        if((remaining_elements == 0) ||
                (cbfifo_length(&cbfifo_transmit_uart3) == cbfifo_capacity(&cbfifo_transmit_uart3)))
        {
            //enabling transmit interrupt
            EUSCI_A3->IE |= EUSCI_A_IE_TXIE;
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
    if(cbfifo_length(&cbfifo_receive_uart0) < 1)
    {
        return -1;
    }
    else
    {
        //Entering critical section
        masking_state = __get_PRIMASK();
        __disable_irq();
        cbfifo_dequeue(&cbfifo_receive_uart0, &c, sizeof(c));
        __set_PRIMASK(masking_state);
        return c;
    }
}


/********************************************************************
// receive a character from user input
*********************************************************************/
int getchar_uart2()
{
    int c = 0;
    uint32_t masking_state;
    //returns -1 to indicate that no new char has received
    if(cbfifo_length(&cbfifo_receive_uart2) < 1)
    {
        return -1;
    }
    else
    {
        //Entering critical section
        masking_state = __get_PRIMASK();
        __disable_irq();
        cbfifo_dequeue(&cbfifo_receive_uart2, &c, sizeof(c));
        __set_PRIMASK(masking_state);
        return c;
    }
}

/********************************************************************
// receive a character from user input
*********************************************************************/
int getchar_uart3()
{
    int c = 0;
    uint32_t masking_state;
    //returns -1 to indicate that no new char has received
    if(cbfifo_length(&cbfifo_receive_uart3) < 1)
    {
        return -1;
    }
    else
    {
        //Entering critical section
        masking_state = __get_PRIMASK();
        __disable_irq();
        cbfifo_dequeue(&cbfifo_receive_uart3, &c, sizeof(c));
        __set_PRIMASK(masking_state);
        return c;
    }
}
/*----------------------------------------------------------------------------
 * This function echoes back characters to serial output
 * (refer uart.h for additional details)
 ----------------------------------------------------------------------------*/
void echo_uart3(char c)
{
    char str[1] = {c};
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
          putstr_uart3("\r\n");
          break;

      case 0xFF:
          break;

          //echoing received chars
      default:
          putstr_uart3(str);
          break;
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

