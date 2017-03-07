/*
 * lsm303d.c
 *
 *  Created on: 6 mar 2017
 *      Author: Arek
 */

#include <lsm6ds0.h>
#include "i2c.h"



/** interface functions definition  **/
void lsm_start_communication(void)
{
	i2c_run_periph(I2C1);
}

void lsm_write (register_t reg, const void* data, uint8_t size)
{
	const uint8_t* buffer = (uint8_t*)data;

	i2c_send_data((uint8_t)reg, buffer, size);
}

void lsm_read(register_t reg, void* data, uint8_t size)
{
	uint8_t* buffer = (uint8_t *)data;
	i2c_receive_data((uint8_t)reg, buffer, size);
}

void lsm_write_reg(register_t reg, uint8_t value)
{
	lsm_write(reg, &value, sizeof(value));
}

uint8_t lsm_read_reg(uint8_t reg)
{
	uint8_t value = 0;
	lsm_read(reg, &value, sizeof(value));
	return value;
}

int16_t lsm_read_value(uint8_t reg)
{
	int16_t value = 0;
	lsm_read(reg, &value, sizeof(value));
	return value;
}
