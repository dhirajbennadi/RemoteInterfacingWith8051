/*************************************************
 * @filename : IO_Expander.c
 * @author   : Dhiraj Bennadi
 * @compiler : arm
 * @IDE      : Code Blocks
 *
 * Identification of any leveraged code : Code Referenced
 * from the example given by Prof. Linden Mcclure
 * Applicable Links: None
 */


#include "i2c.h"
#include "IO_Expander.h"


/*
*@Function : IO_Exp_Write()
*@Brief    : Writes value to IO Expander
*Parameters: unsigned char a - Value to be written
*Returns   : None
*/
void IO_Exp_Write(unsigned char a)
{
    //Starting I2C
    StartI2c();

    //Writing device address to address IO Expander
    write_i2c(IO_EXP_DEVICE_ADDR);

    //Writing data
    write_i2c(a);

    //Stopping I2C
    StopI2c();
}


/*
*@Function : IO_Exp_Read()
*@Brief    : Reads the state o IO Expander
*Parameters: unsigned char a - Value to be written
*Returns   : None
*/
unsigned char IO_Exp_Read()
{
    unsigned char data = 0;

    //Starting I2C
    StartI2c();

    //1 is sent for reading
    write_i2c(IO_EXP_DEVICE_ADDR | 1);

    //Reading I2C bus
    data = read_i2c();

    //Sending No acknowledgment bit
    NACK();

    //Stopping I2C
    StopI2c();

    //Returning the data read
    return data;
}
