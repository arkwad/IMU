/*
 * main.c
 *
 *  Created on: 6 mar 2017
 *      Author: Arek
 */

#include <lsm6ds0.h>
#include <math.h>
#include <stdio.h>
#include "stm32f10x.h"
#include <stdbool.h>
#include "uart.h"
#include "delay.h"




int main(void)
{

	uart_start_periph();
	lsm_start_communication();

	SysTick_Config(SystemCoreClock / 1000);

	printf("Trying to connect to accelerometer...\n");

	if (LSM303D_I_AM == lsm_read_reg(LSM6DS0_WHO_AM_I))
	{
		printf("Found accelerometer: LSM6DS0\n");
	}
	else
	{
		printf("Wrong device respose !\n");
	}
	lsm_write_reg(LSM6DS0_CTRL_REG5_XL, OUT_ACC_ON);	// outputs on
	lsm_write_reg(LSM6DS0_CTRL_REG6_XL, ACC_50_HZ); // 50Hz

	delay_ms(100);

	while (true)
	{

#ifdef true
		int16_t a_x = lsm_read_value(LSM6DS0_OUT_X_XL);
		int16_t a_y = lsm_read_value(LSM6DS0_OUT_Y_XL);
		int16_t a_z = lsm_read_value(LSM6DS0_OUT_Z_XL);

		float x = a_x * 2.0f / 32678.0f;
		float y = a_y * 2.0f / 32678.0f;
		float z = a_z * 2.0f / 32678.0f;
		printf("X = %.2f   Y = %.2f   Z = %.2f\n", x, y, z);

		float alpha = atan2f(z, x);
		printf("alpha = %.2f\n", alpha * 180.0f / M_PI + 90.0f);
#endif
		delay_ms(50);
	}
}
