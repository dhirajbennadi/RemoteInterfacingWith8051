/*****************************************************************************************
 * @file uart.h :
 * @brief : This file contains defines, includes, and function prototypes for uart.c
 *
 * @author : Dhiraj Bennadi
 * @date : Nov 6 2021
 *
 ******************************************************************************************/

#ifndef UART_H_
#define UART_H_

#include <stdint.h>

#define putchar(c) putstr(&c)

#define send_to_esp32(s) putstr_uart2(s)
#define receive_from_esp32() getchar_uart2()

#define send_to_8051(s) putstr_uart3(s)
#define receive_from_8051() getchar_uart3()
/** ------------------------------------------------------------------------------
 *  @brief      Initializes UART  to work at specified
 *					BAUD_RATE
 *					DATA_SIZE
 *					PARITY
 *					STOP_BITS
 *				in uart.c
 *
 * @param buf :  none
 *
 * @return none
 ---------------------------------------------------------------------------------**/
void uart_init(void);
/** ------------------------------------------------------------------------------
 *  @brief       echoes back characters to serial out
 *
 * @param 	:	c -> character c to be echoed
 * @param 	:	num_of_chars -> number of characters to keep track of characters entered per
 * 				command line
 * @return none
 ---------------------------------------------------------------------------------**/
void echo(char c);
void echo_uart2(char c);

/** ------------------------------------------------------------------------------
 *  @brief       receives raw line of command over uart until enter key is pressed
 *
  * @param 	:	num_of_chars -> number of characters to keep track of characters entered per
 * 				command line
 * @return command_line when enter key is pressed
 ---------------------------------------------------------------------------------**/
char* get_line_of_command_raw(int8_t c, uint32_t*);
void get_esp32_response(char *);
/********************************************************************
// Send string over UART
*********************************************************************/
int putstr(char *buf);
int putstr_uart2(char *buf);
int putstr_uart3(char *buf);

/********************************************************************
// receive character over UART
*********************************************************************/
int getchar();
int getchar_uart2();
int getchar_uart3();

/********************************************************************
// convert number to string
*********************************************************************/
char* num_to_str(float num);

/********************************************************************
// accepts a number from the user
*********************************************************************/
int accept_number_from_user(void);

#endif /* UART_H_ */
