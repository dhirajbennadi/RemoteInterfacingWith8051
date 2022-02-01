/*
 */

#include <at89c51ed2.h>       //also includes 8052.h and 8051.h
#include <mcs51reg.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

#include "sdcc_syntax_example.h"

#define NUMBER_OF_BUFFERS 30
#define NUMBER_OF_NEW_BUFFERS 20


//uint8_t check_state_variable(unsigned char param1);
bool checkBufferSizeConditions(int userEnteredSize);
bool StoreCharacter(unsigned char value, uint8_t *buffer, uint16_t location);
void hexdump(unsigned char *ptr, int size);
void printBufferStatistics(uint8_t index);

void updateBufferStatistics(uint8_t bufferNumber, uint16_t *bufferStartAddress,
                            uint16_t bufferSize);

void updateBufferStatisticsForBuffer0(void);
void clearBuffer0(void);

void clearAllBuffers(void);

typedef struct bufferStatistics_t{
    uint8_t bufferNumber;
    uint16_t *bufferStartAddress;
    uint16_t *bufferEndAddress;
    uint16_t bufferSize;
    uint16_t bufferFilledSize;
    uint16_t bufferRemainingSize;
    bool bufferActive;
}bufferStatistics;


bufferStatistics HeapBufferStatistics[NUMBER_OF_BUFFERS];

void main(void)
{

    __xdata uint8_t* buffer0 = NULL;
    uint16_t buffer0locationptr = 0;
    __xdata uint8_t* buffer1 = NULL;
    unsigned char size_user1[5];
    int total_size = 0;
    uint8_t flag1;
    flag1 = 0;
    uint8_t flag2 = 0;
    unsigned char bufferNumberString[5];
    uint8_t buffer_number;

    unsigned char optionCharacterString[5];
    unsigned char optionCharacter;
    unsigned char stateVariable;
    int value;

    unsigned char newBufferSizeString[4];
    uint16_t newBufferSize = 0;
    __xdata uint8_t* newBuffer[NUMBER_OF_NEW_BUFFERS];
    uint8_t newBufferCount = 0;

    uint8_t bufferNumberToBeDeleted = 0;
    unsigned char bufferNumberToBeDeletedString[5];
    bool isCharacterStored = false;
    bool userBufferSizeCheck = false;


    do{
        if(flag1 == 0)
        {
            putstr("Enter the size between 48 - 4800 bytes to allocate buffers\n\r");
            getstr(size_user1);
            total_size = atoi(size_user1);
            printf("Size Entered = %d\n\r",total_size);

            userBufferSizeCheck = checkBufferSizeConditions(total_size);

            if(userBufferSizeCheck == true)
            {
                buffer0 = (uint8_t*)malloc(total_size);
                buffer1 = (uint8_t*)malloc(total_size);

                if((buffer0 != NULL) && (buffer1 != NULL))
                {
                    flag1 = 1;
                    updateBufferStatistics(0,buffer0,total_size);
                    updateBufferStatistics(1,buffer1,total_size);
                    printf("Size of buffer0 is %d at location %p\n\r", total_size , buffer0);
                    printf("Size of buffer1 is %d at location %p\n\r", total_size , buffer1);
                }
                else
                {
                    if(buffer0 != NULL)
                    {
                        free(buffer0);
                    }

                    if(buffer1 != NULL)
                    {
                        free(buffer1);
                    }
                    putstr("Buffer 0 not initialized\n\r");
                    putstr("Buffer 1 not initialized\n\r");
                }
            }

        }
        else
        {

            putstr("Enter the options to execute commands\n\r");

            getstr(optionCharacterString);

            if(optionCharacterString[0] >= 0x61 && optionCharacterString[0] < 0x7B)
            {
                puts("Storage Character entered\n\r");
                isCharacterStored = StoreCharacter(optionCharacterString[0] , buffer0 , buffer0locationptr);

                if(isCharacterStored == true)
                {
                    buffer0locationptr++;
                    updateBufferStatisticsForBuffer0();
                    isCharacterStored = false;
                }

                printf("Storage Character = %c\n\r", optionCharacterString[0]);
            }
            else if(optionCharacterString[0] == 0x2B)
            {
                puts("+ symbol received\n\r");
                puts("Enter the number of bytes between 30 to 300\n\r");
                getstr(newBufferSizeString);

                newBufferSize = atoi(newBufferSizeString);

                if(newBufferCount < NUMBER_OF_NEW_BUFFERS)
                {
                    newBuffer[newBufferCount] = malloc(newBufferSize);

                    if(newBuffer[newBufferCount] != NULL)
                    {
                        printf("New Buffer Initialized with size = %d bytes at location = %p\n\r", newBufferSize, newBuffer[newBufferCount]);
                        HeapBufferStatistics[newBufferCount + 2].bufferActive = true;
                        updateBufferStatistics(newBufferCount + 2, newBuffer[newBufferCount],newBufferSize);
                        newBufferCount++;
                    }
                }
                else
                {
                    printf("Number of new buffer allocation limit reached\n\r");
                }

            }
            else if(optionCharacterString[0] == 0x2D)
            {

               puts("- symbol received\n\r");
               printf_small("Enter the number of the buffer to be deleted\n\r");
               getstr(bufferNumberToBeDeletedString);

               bufferNumberToBeDeleted = atoi(bufferNumberToBeDeletedString);

               //HandleDeletingBuffer(bufferNumberToBeDeleted);
               if(bufferNumberToBeDeleted == 0)
               {
                   printf("Invalid Buffer Number\n\r");
               }

               for(int i = 1; i < NUMBER_OF_NEW_BUFFERS; i++)
               {

                   if(bufferNumberToBeDeleted == i)
                   {
                       //free(newBuffer[i]);
                       free(HeapBufferStatistics[i].bufferStartAddress);
                       HeapBufferStatistics[i].bufferActive = false;
                   }
               }


            }
            else if(optionCharacterString[0] == 0x3F)
            {
               puts("? symbol received\n\r");

               for(uint8_t i = 0; i < NUMBER_OF_BUFFERS; i++)
               {
                   printBufferStatistics(i);
               }
               clearBuffer0();
               buffer0locationptr = 0;


            }
            else if(optionCharacterString[0] == 0x3D)
            {

                printf("= symbol received\n\r");
                hexdump(buffer0, HeapBufferStatistics[0].bufferSize);

            }
            else if(optionCharacterString[0] == 0x40)
            {
                puts("@ symbol received\n\r");
                puts("Freeing all allocated buffers\n\r");

                for(int index = 0; index < NUMBER_OF_BUFFERS; index++)
                {
                    if(HeapBufferStatistics[index].bufferActive == true)
                    {
                        free(HeapBufferStatistics[index].bufferStartAddress);
                    }
                }
                clearBuffer0();
                clearAllBuffers();
                flag1 = 0;
                newBufferCount = 0;
            }
            else
            {
                puts("Command symbol received\n\r");
                printf("Command Character = %c\n\r", optionCharacterString[0]);
            }

        }

    }while(1);



}



bool StoreCharacter(unsigned char value, uint8_t *buffer, uint16_t location)
{
    bool ret_val = false;
    if(location < HeapBufferStatistics[0].bufferSize)
    {
      buffer[location] = value;
      ret_val = true;
    }

    return ret_val;
}



void printBufferStatistics(uint8_t index)
{
    if(HeapBufferStatistics[index].bufferActive)
    {

    printf("Buffer Number = %d\n\r", HeapBufferStatistics[index].bufferNumber);
    printf("Buffer Start Address = %p\n\r", HeapBufferStatistics[index].bufferStartAddress);
    printf("Buffer End Address = %p\n\r", HeapBufferStatistics[index].bufferEndAddress);
    printf("Buffer Size = %d\n\r", HeapBufferStatistics[index].bufferSize);
    printf("Buffer Storage Characters = %d\n\r", HeapBufferStatistics[index].bufferFilledSize);
    printf("Buffer Free Space Remaining = %d\n\r", HeapBufferStatistics[index].bufferRemainingSize);
    printf("****\n\r");
    }
}


void updateBufferStatistics(uint8_t bufferNumber, uint16_t *bufferStartAddress,
                            uint16_t bufferSize)
{

    HeapBufferStatistics[bufferNumber].bufferNumber = bufferNumber;
    HeapBufferStatistics[bufferNumber].bufferStartAddress = bufferStartAddress;
    HeapBufferStatistics[bufferNumber].bufferEndAddress = bufferStartAddress + (bufferSize / 2);
    HeapBufferStatistics[bufferNumber].bufferSize = bufferSize;
    HeapBufferStatistics[bufferNumber].bufferActive = true;

    printf("Buffer Size Received as parameter = %d\n\r", bufferSize);

}

void updateBufferStatisticsForBuffer0(void)
{
    HeapBufferStatistics[0].bufferFilledSize++;
    HeapBufferStatistics[0].bufferRemainingSize = HeapBufferStatistics[0].bufferSize
                - HeapBufferStatistics[0].bufferFilledSize;

}

void hexdump(unsigned char *ptr, int size)
{
    int number_of_lines = 0;
    int remaining_bytes = size;
    int bytes_printed = 0;

    if(size % 16 == 0)
    {
      number_of_lines = size / 16;
    }
    else
    {
      number_of_lines = size / 16;
      number_of_lines++;
    }

    for(int i = 0; i < number_of_lines; i++)
    {
      printf("%p :", ptr);

      if(remaining_bytes > 16)
      {
        for(int j = 0 ; j < 16; j++)
        {
          printf("%x ", ptr[j]);
          bytes_printed++;
        }
        ptr = ptr + 16;
        remaining_bytes = remaining_bytes - 16;
        printf("\n\r");
      }
      else
      {
        for(int j = 0 ; j < remaining_bytes; j++)
        {
          printf("%x ", ptr[j]);
          bytes_printed++;
        }
        ptr = ptr + remaining_bytes;
        remaining_bytes = remaining_bytes - bytes_printed;
        printf("\n\r");
      }
    }
}


void clearBuffer0(void)
{
    int i = 0;

    for(i = 0 ; i < HeapBufferStatistics[0].bufferSize; i++)
    {
        HeapBufferStatistics[0].bufferStartAddress[i] = 0;
    }

    HeapBufferStatistics[0].bufferFilledSize = 0;
    HeapBufferStatistics[0].bufferRemainingSize = HeapBufferStatistics[0].bufferSize;
}


void HandleDeletingBuffer(uint8_t bufferNumberToBeDeleted)
{

    if(bufferNumberToBeDeleted == 0)
    {
        printf("Invalid buffer number\n\r");
    }
}


bool checkBufferSizeConditions(int userEnteredSize)
{
    bool ret_val = true;

    if(userEnteredSize < 48)
    {
        putstr("Size is less than 48 bytes\n\r");
        ret_val = false;

    }

    if(userEnteredSize > 4800)
    {
        putstr("Size is greater than 4800 bytes\n\r");
        ret_val = false;
    }

    return ret_val;

}


void clearAllBuffers(void)
{
    int i = 0;

    for(i = 0 ; i < NUMBER_OF_BUFFERS; i++)
    {
        HeapBufferStatistics[i].bufferStartAddress = NULL;
        HeapBufferStatistics[i].bufferFilledSize = 0;
        HeapBufferStatistics[i].bufferRemainingSize;
        HeapBufferStatistics[i].bufferEndAddress = NULL;
        HeapBufferStatistics[i].bufferActive = false;
        HeapBufferStatistics[i].bufferNumber = 0;
        HeapBufferStatistics[i].bufferSize = 0;
    }


    HeapBufferStatistics[0].bufferRemainingSize = HeapBufferStatistics[0].bufferSize;
}
