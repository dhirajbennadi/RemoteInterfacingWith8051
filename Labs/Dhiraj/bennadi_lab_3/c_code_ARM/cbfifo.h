/*************************************************
 * @filename : cbfifo.h
 * @author   : Dhiraj Bennadi
 * @compiler : arm
 * @IDE      : Code Composer Studio
 *
 * Identification of any leveraged code : None
 * Applicable Links: None
 */

#ifndef CBFIFO_H_
#define CBFIFO_H_

#include <stdbool.h>

#define SIZE_OF_BUFFER (1000)

void enqueue(char val);
int dequeue(void);
bool isBufferEmpty(void);
bool isBufferFull(void);

extern char arr[SIZE_OF_BUFFER];

#endif /* CBFIFO_H_ */
