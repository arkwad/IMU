/*
 * main.c
 *
 *  Created on: 6 mar 2017
 *      Author: Arek
 */



#include <math.h>
#include <stdio.h>
#include "stm32f10x.h"
#include <stdbool.h>
#include "lsm303d.h"
#include "uart.h"
#include "delay.h"




int main(void)
{

	uart_start_periph();
	lsm_start_communication();

	SysTick_Config(SystemCoreClock / 1000);

	printf("Trying to connect to accelerometer...\n");

	uint8_t who_am_i = lsm_read_reg(LSM303D_WHO_AM_I);

	if (LSM303D_DEV_ID == lsm_read_reg(LSM303D_WHO_AM_I))
	{
		printf("Found accelerometer: LSM303D\n");
	}
	else
	{
		printf("Wrong device respose (0x%02X)\n", who_am_i);
	}

	lsm_write_reg(LSM303D_CTRL5, 0x80|0x10);	// TEMP_EN | M_ODR2 (50Hz)
	lsm_write_reg(LSM303D_CTRL1, 0x40|0x07);	// AODR2 (25Hz) | AXEN | AYEN | AZEN

	delay_ms(100);

	while (true)
	{
		int16_t a_x = lsm_read_value(LSM303D_OUT_X_A);
		int16_t a_y = lsm_read_value(LSM303D_OUT_Y_A);
		int16_t a_z = lsm_read_value(LSM303D_OUT_Z_A);

		float x = a_x * 2.0f / 32678.0f;
		float y = a_y * 2.0f / 32678.0f;
		float z = a_z * 2.0f / 32678.0f;
		//printf("X = %.2f   Y = %.2f   Z = %.2f\n", x, y, z);

		float alpha = atan2f(z, x);
		printf("alpha = %.2f\n", alpha * 180.0f / M_PI + 90.0f);

		delay_ms(200);
	}
}
