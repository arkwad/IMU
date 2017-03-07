/*
 * lsm303d.h
 *
 *  Created on: 6 mar 2017
 *      Author: Arek
 */

#ifndef LSM303D_H_
#define LSM303D_H_
#include "stm32f10x.h"
#include <stdint.h>

#define LSM303D_TEMP_OUT			0x05
#define LSM303D_STATUS_M			0x07
#define LSM303D_OUT_X_M				0x08
#define LSM303D_OUT_Y_M				0x0a
#define LSM303D_OUT_Z_M				0x0c
#define LSM303D_WHO_AM_I			0x0f
#define LSM303D_CTRL0				0x1f
#define LSM303D_CTRL1				0x20
#define LSM303D_CTRL2				0x21
#define LSM303D_CTRL3				0x22
#define LSM303D_CTRL4				0x23
#define LSM303D_CTRL5				0x24
#define LSM303D_CTRL6				0x25
#define LSM303D_CTRL7				0x26
#define LSM303D_STATUS				0x27
#define LSM303D_OUT_X_A				0x28
#define LSM303D_OUT_Y_A				0x2a
#define LSM303D_OUT_Z_A				0x2c


#define LSM303D_ADDR				0x3a
#define LSM303D_DEV_ID				0x49
/*** typedefs definition ***/
typedef uint8_t Register_t;
typedef uint32_t event_t;
/*** end of typedefs definition ***/

// configuration of i2c interface
#define I2C_PORT I2C1
//#define I2C_PORT I2C2

extern void lsm_start_communication(void);
extern void lsm_write(Register_t reg, const void* data, uint8_t size);
extern void lsm_read(Register_t reg, void* data, uint8_t size);

extern void lsm_write_reg(Register_t reg, uint8_t value);
extern uint8_t lsm_read_reg(Register_t reg);
extern int16_t lsm_read_value(Register_t reg);

#endif /* LSM303D_H_ */
