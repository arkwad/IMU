/*
 * i2c.h
 *
 *  Created on: 6 mar 2017
 *      Author: Arek
 */

#ifndef I2C_H_
#define I2C_H_

#include "lsm303d.h"

void i2c_run_periph(I2C_TypeDef * slot);
void i2c_send_data(uint8_t address, const uint8_t * data, uint8_t data_length );
void i2c_receive_data(uint8_t address,uint8_t * data, uint8_t data_length );

#endif /* I2C_H_ */
