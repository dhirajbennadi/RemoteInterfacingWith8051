/*************************************************
 * @filename : cbfifo.c
 * @author   : Dhiraj Bennadi
 * @compiler : arm
 * @IDE      : Code Composer Studio
 *
 * Identification of any leveraged code : None
 * Applicable Links: None
 */

#include "cbfifo.h"
#include <stdbool.h>

char arr[SIZE_OF_BUFFER];
int rear = -1;
int front = -1;

void enqueue(char val)
{
    if(isBufferFull())
    {
        return;
    }
    else if(isBufferEmpty())
    {
        rear = front = 0;
    }
    else
    {
        rear =  rear + 1 % SIZE_OF_BUFFER;
    }

    arr[rear] = val;

}


int dequeue(void)
{
    char temp = 0;

    if(isBufferEmpty())
    {
        return temp;
    }
    else if(front == rear)
    {
        temp = arr[front];
        front = rear = -1;
    }
    else
    {
        temp = arr[front];
        front = front + 1 % SIZE_OF_BUFFER;
    }

    return temp;
}

bool isBufferEmpty(void)
{
    if(front == -1 && rear == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}


bool isBufferFull(void)
{
    if((rear + 1) % SIZE_OF_BUFFER == front)
    {
        return true;
    }
    else
    {
        return false;
    }
}
