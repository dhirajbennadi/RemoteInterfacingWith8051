/*
 * temp.h
 *
 *  Created on: Oct 22, 2021
 *      Author: Rajat
 */

#ifndef TEMP_H_
#define TEMP_H_


/***defines**/

typedef enum temp_unit_e{
    TEMP_CELCIUS,
    TEMP_FAHRENHEIT
}temp_unit_t;

/*----------------------------------------------------------------------------
 * initializes ADC
 ----------------------------------------------------------------------------*/
void init_temp(void);

/*----------------------------------------------------------------------------
 * Initiates temp measurement
 ----------------------------------------------------------------------------*/
void start_temp_measurement(void);

/*----------------------------------------------------------------------------
 * retrieves temp measurement
 ----------------------------------------------------------------------------*/
float get_temp(void);

#endif /* TEMP_H_ */
