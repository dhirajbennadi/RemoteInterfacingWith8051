/****************************************************************************
 * @file cbfifo.h : 
 * @brief : a fixed-size FIFO implemented via a circular buffer
 * 
 * @author : Rajat Chaple
 ****************************************************************************/

#ifndef _CBFIFO_H_
#define _CBFIFO_H_

#include <stdlib.h>  // for size_t
#include <stdint.h>
#include <stdbool.h>

#define CBFIFO_SIZE (1024) //bytes

typedef struct cbfifo_s cbfifo_t;


/** ------------------------------------------------------------------------------
 *  @brief       Enqueues data onto the FIFO, up to the limit of the available FIFO
 *               capacity.
 * 
 * @param buf :  Pointer to the data
 * @param nbyte :Max number of bytes to enqueue
 * @return int : The number of bytes actually enqueued, which could be 0. In case
 *               of an error, returns -1.
 ---------------------------------------------------------------------------------**/
size_t cbfifo_enqueue(cbfifo_t* cbfifo, void *buf, size_t nbyte);


/** ------------------------------------------------------------------------------
 *  @brief        Attempts to remove ("dequeue") up to nbyte bytes of data from the
 *                FIFO. Removed data will be copied into the buffer pointed to by buf.
 * 
 * @param buf :   Destination for the dequeued data
 * @param nbyte : Bytes of data requested
 * @return int :  The number of bytes actually copied, which will be between 0 and
 *                nbyte. 
 * description :  If the FIFO's current length is 24
 *                bytes, and the caller requests 30 bytes, cbfifo_dequeue should
 *                return the 24 bytes it has, and the new FIFO length will be 0. If
 *                the FIFO is empty (current length is 0 bytes), a request to dequeue
 *                any number of bytes will result in a return of 0 from
 *                cbfifo_dequeue.
 *                  
 ---------------------------------------------------------------------------------**/
size_t cbfifo_dequeue(cbfifo_t* cbfifo, void *buf, size_t nbyte);


/** ------------------------------------------------------------------------------
 *  @brief Returns the number of bytes currently on the FIFO. 
 * 
 * @param  :  none
 * @return  : Number of bytes currently available to be dequeued from the FIFO
 ---------------------------------------------------------------------------------**/
size_t cbfifo_length(cbfifo_t* cbfifo);

/** ------------------------------------------------------------------------------
 *  @brief Returns  Returns the FIFO's capacity
 * 
 * @param  :  none
 * @return  : The capacity, in bytes, for the FIFO
 ---------------------------------------------------------------------------------**/
size_t cbfifo_capacity(cbfifo_t* cbfifo);


#endif // _CBFIFO_H_
