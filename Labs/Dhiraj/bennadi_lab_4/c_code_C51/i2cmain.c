/*************************************************
 * @filename : main.c
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
#include "EEPROM.h"
#include "IO_Expander.h"

#define LED_PIN0 P1_0
#define LED_PIN1 P1_1
/*
*@Function : PinInterrupt
*@Brief    : ISR routine
*Parameters: None
*Returns   : None
*/
void PinInterrupt(void)__interrupt(0)
{
    LED_PIN1 ^= 1;
    LED_PIN0 ^= 1;
}

/*
*@Function : main function
*@Brief    : Program entry point
*Parameters: None
*Returns   : None
*/
void main(void)
{
    char option;
    unsigned char rxbyte=0;
    uint8_t IO_status = 0;

    unsigned int hexValueAddress;
    unsigned int hexValueData;
    unsigned char userInputAddress[4];
    unsigned char userInputData[3];
    unsigned char hexDumpAddress1[4];
    unsigned char hexDumpAddress2[4];
    unsigned int hexValueAddress1;
    unsigned int hexValueAddress2;
    unsigned char blockValue = 0;
    bool isAddrValid = false;
    SERIAL_DATA = 0;
    SERIAL_CLK = 0;
    InitI2c();

    while(1)
    {
        printf("Enter the option to select\n\r");
        printf("Enter 1 to write to the EEPROM\n\r");
        printf("Enter 2 to read from the EEPROM\n\r");
        printf("Enter 3 to print the HexDump of the EEPROM\n\r");
        printf("Enter 4 to reset the EEPROM\n\r");
        printf("Enter 5 to select pin to be made high\n\r");
        printf("Enter 6 to read the status of IO Expander\n\r");
        printf("Enter 7 to Invert the status of IO Expander\n\r");
        option = getchar();


        switch(option)
        {
        case '1':
            printf("Option Selected to write to EEPROM\n\r");
            printf("Enter Address\n\r");
            getstr(userInputAddress);
            hexValueAddress = (int)strtol(userInputAddress, NULL, 16);

            isAddrValid = checkAddress(hexValueAddress);
            if(isAddrValid)
            {
            blockValue = blockValueFromAddress(hexValueAddress);
            printf("Block Value = %d\n\r", blockValue);
            printf("Enter Data\n\r");
            getstr(userInputData);
            hexValueData = (int)strtol(userInputData, NULL, 16);
            write_byte_to_eeprom(hexValueAddress , hexValueData , blockValue);
            }
            else
            {
                printf("Invalid Address Entered\n\r");
            }

            break;

        case '2':
            printf("Option Selected to read from EEPROM\n\r");
            printf("Enter Address\n\r");
            getstr(userInputAddress);
            hexValueAddress = (int)strtol(userInputAddress, NULL, 16);
            isAddrValid = checkAddress(hexValueAddress);
            if(isAddrValid)
            {
                blockValue = blockValueFromAddress(hexValueAddress);
                printf("Block Value = %d\n\r", blockValue);
                rxbyte = read_byte_from_eeprom(hexValueAddress , blockValue);
                printf("Value Read from EEPROM = %x\n\r", rxbyte);
            }
            else
            {
               printf("Invalid Address Entered\n\r");
            }
            break;

        case '3':
            printf("Option Selected to print the HexDump of the EEPROM\n\r");
            printf("Enter Address 1 \n\r");
            getstr(hexDumpAddress1);
            hexValueAddress1 = (int)strtol(hexDumpAddress1, NULL, 16);

            isAddrValid = checkAddress(hexValueAddress1);

            if(isAddrValid)
            {
                printf("Enter Address 2\n\r");
                getstr(hexDumpAddress2);
                hexValueAddress2 = (int)strtol(hexDumpAddress2, NULL, 16);

                isAddrValid = checkAddress(hexValueAddress2);

                if(isAddrValid)
                {
                    hexdumpAddress(hexValueAddress1 , hexValueAddress2);
                }
                else
                {
                    printf("Invalid Address 2 Entered\n\r");
                }

            }
            else
            {
                printf("Invalid Address 1 Entered\n\r");
            }


            break;

        case '4':
            printf("Option selected to reset EEPROM\n\r");
            resetSequence();
            break;

        case '5':
            printf("\n\rEnter Pin to made as high [0-7]:\n\r");
            option = getchar();
            putchar(option);

            if(option == '0')
                IO_Exp_Write(P0_IOEXP);
            else if(option == '1')
                IO_Exp_Write(P1_IOEXP);
            else if(option == '2')
                IO_Exp_Write(P2_IOEXP);
            else if(option == '3')
                IO_Exp_Write(P3_IOEXP);
            else if(option == '4')
                IO_Exp_Write(P4_IOEXP);
            else if(option == '5')
                IO_Exp_Write(P5_IOEXP);
            else if(option == '6')
                IO_Exp_Write(P6_IOEXP);
            else if(option == '7')
                IO_Exp_Write(P7_IOEXP);
        break;


        case '6':
            printf("Reading Pin Status\n\r");
            IO_status = IO_Exp_Read();
            printf("Current State : %x\n\r",IO_status);
        break;

        case '7':
            printf("Inverting Pins\n\r");
            IO_status =  IO_Exp_Read();
            IO_Exp_Write(~IO_status);
        break;


        default:
            break;
        }
    }


}


