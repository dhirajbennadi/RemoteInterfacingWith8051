/*************************************************
 * @filename : EEPROM.c
 * @author   : Dhiraj Bennadi
 * @compiler : arm
 * @IDE      : Code Blocks
 *
 * Identification of any leveraged code : Code Referenced
 * from the example given by Prof. Linden Mcclure
 * Applicable Links: None
 */

#include "i2c.h"
#include "EEPROM.h"

#include <at89c51ed2.h>
#include <mcs51reg.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include "supportFunctions.h"
#include <stdbool.h>


/*
*@Function : hexdumpAddress
*@Brief    : Prints the dump of the memory address
*Parameters: int, int
*Returns   : None
*/
void hexdumpAddress(unsigned int address1, unsigned int address2)
{
    int size = address2 - address1;
    int tempBlock;

    printf("hexValueAddress1 = %d\n\r", address1);
    printf("hexValueAddress2 = %d\n\r", address2);

    printf("Size = %d\n\r", size);
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

    printf("Number of lines = %d\n\r", number_of_lines);
    printf("Remaining Bytes = %d\n\r", remaining_bytes);

    for(int i = 0; i < number_of_lines; i++)
    {

      printf("%04x:", address1);

      if(remaining_bytes > 16)
      {
        for(int j = 0 ; j < 16; j++)
        {
          tempBlock = blockValueFromAddress(address1);
          printf("%x ", read_byte_from_eeprom(address1 + j, tempBlock));
          bytes_printed++;
        }
        address1 = address1 + 16;
        remaining_bytes = remaining_bytes - 16;
        printf("\n\r");
      }
      else
      {
        for(int j = 0 ; j < remaining_bytes; j++)
        {
          tempBlock = blockValueFromAddress(address1);
          printf("%x ", read_byte_from_eeprom(address1 + j, tempBlock));
          bytes_printed++;
        }
        address1 = address1 + remaining_bytes;
        remaining_bytes = remaining_bytes - bytes_printed;
        printf("\n\r");
      }
    }
}


/*
*@Function : blockValueFromAddress
*@Brief    : Derives the block from the address value
*Parameters: int
*Returns   : int
*/
int blockValueFromAddress(int hexValue)
{
    int blockValue = 0;

    blockValue = hexValue / 256;

    return blockValue;
}


/*
*@Function : checkAddress
*@Brief    : Checks if the address is within the range
*Parameters: int
*Returns   : bool
*/
bool checkAddress(unsigned int address)
{
    if(address >= 0x00 && address < 0x8000)
    {
        return true;
    }

    return false;
}

/*
*@Function : resetSequence
*@Brief    : Performs the reset sequence for the EEPROM chip
*Parameters: None
*Returns   : None
*/
void resetSequence(void)
{
    int i = 0;
    StartI2c();
    SERIAL_CLK = 0;
    delay(FULL_CYCLE_DELAY);
    for(i = 0; i < 9; i++)
    {
      SERIAL_CLK = 1;
      delay(FULL_CYCLE_DELAY);
      SERIAL_CLK = 0;
      delay(FULL_CYCLE_DELAY);
    }
    StartI2c();
    StopI2c();
}


/*
*@Function : write_byte_to_eeprom
*@Brief    : Writes a Byte to EEPROM Chip
*Parameters: int, char, char
*Returns   : None
*/
void write_byte_to_eeprom(unsigned int addr,unsigned char byte, unsigned char blockValue)
{
    StartI2c();
    write_i2c(CTRL_WRITE_BYTE | (blockValue << 1));
    write_i2c((unsigned char)addr);
    write_i2c(byte);
    StopI2c();
}


/*
*@Function : read_byte_from_eeprom
*@Brief    : Reads a byte from the EEPROM Chip
*Parameters: unsigned int, unsigned char
*Returns   : unsigned char
*/
unsigned char read_byte_from_eeprom(unsigned int addr, unsigned char blockValue)
{
    unsigned char byteRead =0;
    StartI2c();
    write_i2c(CTRL_WRITE_BYTE | (blockValue << 1));
    write_i2c((unsigned char)addr);
    RepeatedStartI2c();
    write_i2c(CTRL_READ_BYTE | (blockValue << 1));
    byteRead = read_i2c();
    SendNackBit();
    StopI2c();
    return byteRead;
}
