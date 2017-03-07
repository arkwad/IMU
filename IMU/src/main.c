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
	lsm_write_reg(LSM6DS0_CTRL_REG4, OUT_ACC_ON);	// outputs on
	lsm_write_reg(LSM6DS0_CTRL_REG1_G, 0x40);	// startat 59.5Hz
	delay_ms(100);

	while (true)
	{

#ifdef true
		int16_t g_x = lsm_read_value(LSM6DS0_OUT_X_L_G);
		int16_t g_y = lsm_read_value(LSM6DS0_OUT_Y_L_G);
		int16_t g_z = lsm_read_value(LSM6DS0_OUT_Z_L_G);

		int16_t a_x = lsm_read_value(LSM6DS0_OUT_X_XL);
		int16_t a_y = lsm_read_value(LSM6DS0_OUT_Y_XL);
		int16_t a_z = lsm_read_value(LSM6DS0_OUT_Z_XL);

		float x = a_x * 2.0f / 32678.0f;
		float y = a_y * 2.0f / 32678.0f;
		float z = a_z * 2.0f / 32678.0f;
		printf("X_ACC = %.2f   Y_ACC = %.2f   Z_ACC = %.2f\n", x, y, z);


		float fg_x = g_x*245.0f/65535.0f;
		float fg_y = g_y*245.0f/65535.0f;
		float fg_z = g_z*245.0f/65535.0f;
		printf("X_G = %.2f   Y_G = %.2f   Z_G = %.2f\n", fg_x, fg_y, fg_z);


		float alpha = atan2f(z, x);
		printf("alpha = %.2f\n", alpha * 180.0f / M_PI + 90.0f);
#endif
		delay_ms(10);
	}
}
