/*************************************************
 * @filename : i2c.c
 * @author   : Dhiraj Bennadi
 * @compiler : arm
 * @IDE      : Code Blocks
 *
 * Identification of any leveraged code : Code Referenced
 * from the example given by Prof. Linden Mcclure
 * Applicable Links: None
 */


#include <at89c51ed2.h>
#include <mcs51reg.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include "supportFunctions.h"
#include <stdbool.h>

#include "i2c.h"

/*
*@Function : delay
*@Brief    : Provides a software delay
*Parameters: unsigned int
*Returns   : None
*/
void delay(unsigned int delayCount)
{
    unsigned int index;
    int unusedTicks = delayCount / 15;
    for(index = 0; index < unusedTicks; index++)
	{
		;
	}

}

/*
*@Function : InitI2c
*@Brief    : Initializes the I2C Lines
*Parameters: None
*Returns   : None
*/
void InitI2c(void)
{
    SERIAL_DATA =1;
    SERIAL_CLK =1;
}
/*
*@Function : StartI2c
*@Brief    : Sends a Start on the bus
*Parameters: None
*Returns   : void
*/
void StartI2c(void)
{
    SERIAL_DATA  = 1;
    SERIAL_CLK  = 1;
    delay(FULL_CYCLE_DELAY);
    SERIAL_DATA  = 0;
    delay(FULL_CYCLE_DELAY);
}

/*
*@Function : RepeatedStartI2c
*@Brief    : Sends a Repeated Start on the bus
*Parameters: None
*Returns   : void
*/
void RepeatedStartI2c()
{
    SERIAL_CLK  = 0;
    delay(FULL_CYCLE_DELAY/2);
    SERIAL_DATA  = 1;
    delay(FULL_CYCLE_DELAY/2);
    SERIAL_CLK  = 1;
    delay(FULL_CYCLE_DELAY/2);
    SERIAL_DATA  = 0;
}

/*
*@Function : StopI2c
*@Brief    : Sends a Stop Byte on the I2C Bus
*Parameters: None
*Returns   : void
*/
void StopI2c(void)
{
    SERIAL_CLK  = 0;
    delay(FULL_CYCLE_DELAY/2);
    SERIAL_DATA  = 0;
    delay(FULL_CYCLE_DELAY/2);
    SERIAL_CLK  = 1;
    delay(FULL_CYCLE_DELAY/2);
    SERIAL_DATA  = 1;

}

/*
*@Function : SendAckBit
*@Brief    : Sends a ACk on the I2C Bus
*Parameters: None
*Returns   : void
*/
void SendAckBit()
{
    SERIAL_CLK  = 0;
    delay(FULL_CYCLE_DELAY/2);
    SERIAL_DATA  = 0;
    delay(FULL_CYCLE_DELAY/2);
    SERIAL_CLK  = 1;

}

/*
*@Function : SendNackBit
*@Brief    : Sends a NACk on the I2C Bus
*Parameters: None
*Returns   : void
*/
void SendNackBit(void)
{
    SERIAL_CLK  = 0;
    delay(FULL_CYCLE_DELAY/2);
    SERIAL_DATA  = 1;
    delay(FULL_CYCLE_DELAY/2);
    SERIAL_CLK  = 1;
    delay(FULL_CYCLE_DELAY);

}

/*
*@Function : write_i2c
*@Brief    : Writes a byte on the I2C Bus
*Parameters: unsigned char
*Returns   : __bit
*/
__bit write_i2c(unsigned char byte)
{
    unsigned char i;
    for(i=0; i<8; i++)
    {
        SERIAL_CLK  = 0;
        delay(FULL_CYCLE_DELAY);
        if((byte<<i)&0x80)
            SERIAL_DATA  = 1;
        else
            SERIAL_DATA  = 0;
        delay(FULL_CYCLE_DELAY/2);

        SERIAL_CLK  = 1;
        delay(FULL_CYCLE_DELAY);

    }

    SERIAL_CLK  = 0;
    SERIAL_DATA  = 0;
    delay(FULL_CYCLE_DELAY/2);
    SERIAL_CLK  = 1;
    delay(FULL_CYCLE_DELAY);

    return SERIAL_DATA;
}

/*
*@Function : read_i2c
*@Brief    : Reads a byte from the I2C Bus
*Parameters: None
*Returns   : unsigned char
*/
unsigned char read_i2c(void)
{
    unsigned char index;
	unsigned char dataRead = 0;
	unsigned char receivedData = 0;
    for(index = 0; index <8; index++)
    {
        SERIAL_CLK  = 0;
        SERIAL_DATA  = 1;
        delay(FULL_CYCLE_DELAY);
        SERIAL_CLK  = 1;
        delay(FULL_CYCLE_DELAY/2);
        dataRead = SERIAL_DATA;
        receivedData = receivedData|(dataRead << 7 - index);
        delay(FULL_CYCLE_DELAY);
    }
    return receivedData;
}

/*
*@Function : NACK()
*@Brief    : This function NACK over the bus
*Parameters: None
*Returns   : None
*/
void NACK()
{
    SERIAL_CLK = 0;
    delay(FULL_CYCLE_DELAY>>1);
    SERIAL_DATA = 1;
    delay(FULL_CYCLE_DELAY>>1);
    SERIAL_CLK = 1;
    delay(FULL_CYCLE_DELAY);
}
