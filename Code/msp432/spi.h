/*****************************************************************************************
 * @file spi.h :
 * @brief : This file contains defines, includes, and function prototypes for spi.c
 *
 * @author : Dhiraj Bennadi
 * @date : Nov 24 2021
 *
 ******************************************************************************************/

#ifndef SPI_H_
#define SPI_H_

#include <stdint.h>

/** ------------------------------------------------------------------------------
 *  @brief      Initializes SPI  to work at specified

 * @param buf :  none
 *
 * @return none
 ---------------------------------------------------------------------------------**/
void init_spi(void);

/*----------------------------------------------------------------------------
 * transmit over SPI
 * (refer spi.h for additional details)
 * @Resource : This function is written with the help of example code provided
 * in assignment document
 ----------------------------------------------------------------------------*/
void spi_tx(uint16_t data);

#endif /* SPI_H_ */
