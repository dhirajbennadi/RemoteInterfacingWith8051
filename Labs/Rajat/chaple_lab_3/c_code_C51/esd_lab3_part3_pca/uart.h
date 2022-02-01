/*****************************************************************************************
 * @file uart.h :
 * @brief : This file contains defines, includes, and function prototypes for uart.c
 *
 * @author : Rajat Chaple (rajat.chaple@colorado.edu)
 * @date : Oct 13 2021
 *
 ******************************************************************************************/

#ifndef UART_H_
#define UART_H_

#include <stdint.h>
#include <stdbool.h>

/***********VARIABLES**********/
typedef enum command_e
{
    NO_CMD,
    CMD_ADD_BUFFER,
    CMD_REMOVE_BUFFER,
    CMD_QUERY,
    CMD_CURRENT_CONTENTS
} command_t;

typedef struct buffer_s
{
    char *buffer_pointer;
    int buf_index;
    int buf_id;
    int buf_size;
} buffer_t;

/************DEFINES***********/
#define MAX_NUM_OF_BUFFERS (210)
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

/** ------------------------------------------------------------------------------
 *  @brief       receives raw line of command over uart until enter key is pressed
 *
  * @param 	:	num_of_chars -> number of characters to keep track of characters entered per
 * 				command line
 * @return command_line when enter key is pressed
 ---------------------------------------------------------------------------------**/
// char* get_line_of_command_raw(char c, uint16_t*);

/** ------------------------------------------------------------------------------
 *  @brief       sending character over serial
 *
  * @param 	:	character c to be sent
 * @return none
 ---------------------------------------------------------------------------------**/
int putchar(int);

/** ------------------------------------------------------------------------------
 *  @brief       receiveing character from a serial port
 *
  * @param 	:	none
 * @return character
 ---------------------------------------------------------------------------------**/
int getchar(void);

/** ------------------------------------------------------------------------------
 *  @brief       transmitting string over serial
 *
  * @param 	:	none
 * @return number of characters sent
 ---------------------------------------------------------------------------------**/
int putstr(char *str);

/** ------------------------------------------------------------------------------
 *  @brief       Accepts following commands
                + for adding buffer
                - for removing buffer
                ? for query
                = for current contents of the buffer
* @param 	:	character received over serial
 * @return command mode entered
 ---------------------------------------------------------------------------------**/
void command(char c);

/** ------------------------------------------------------------------------------
 *  @brief       read a number form user

* @param 	:	none
 * @return number of bytes
 ---------------------------------------------------------------------------------**/
int accept_number_from_user();

/** ------------------------------------------------------------------------------
 *  @brief  prints buffer

 * @param 	:	none
 * @return number of bytes
 ---------------------------------------------------------------------------------**/
void print_buffers(buffer_t *);

/** -------------------------------------------------------------------------------------------
 * @brief returns memory data (HEX) of given size from mentioned starting location
 *
 * Given a pointer and size, this function returns memory data (HEX) of given size from mentioned
 * starting location
 *
 * @param str Pointer to destination string where memory data would be stored in the form of string
 * @param size size of destination string
 * @param loc pointer to a starting location
 * @param nbytes size in the form of number of bytes
 *
 * @return char : Pointer to output string
 *-------------------------------------------------------------------------------------------- **/
void hexdump(const void *loc, long nbytes);

/** -------------------------------------------------------------------------------------------
 * @brief Converts unsigned integer to hexadecimal string
 *
 * Given unsigned integer, this function gives hexadecimal representation for given
 * number of nibbles (4 nbits constitute or 1 nibble)
 *
 * @param str Pointer to destination string where binary representation would be stored
 * @param size size of destination string
 * @param num input number
 * @param nbits number of bits to form hex nibbles to be represented in string form
 *
 * @return int : string length of binary representation of value
 *-------------------------------------------------------------------------------------------- **/
int uint_to_hexstr(char *str, long size, uint16_t num, uint8_t nbits);
void main(void);
#endif /* UART_H_ */
