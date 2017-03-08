/*
 * lsm303d.h
 *
 *  Created on: 6 mar 2017
 *      Author: Arek
 */

#ifndef LSM6DS0_H_
#define LSM6DS0_H_
#include "stm32f10x.h"
#include <stdint.h>

/*** defines of all available registers  ***/
#define LSM6DS0_ACT_THS					0x04
#define LSM6DS0_ACT_DUR					0x05
#define LSM6DS0_INT_GEN_CFG_XL			0x06
#define LSM6DS0_INT_GEN_THS_X_XL 		0x07
#define LSM6DS0_INT_GEN_THS_Y_XL		0x08
#define LSM6DS0_INT_GEN_THS_Z_XL		0x09
#define LSM6DS0_INT_GEN_DUR_XL			0x0A
#define LSM6DS0_REFERENCE_G				0x0B
#define LSM6DS0_INT_CTRL				0x0C

#define LSM6DS0_WHO_AM_I				0x0F

#define LSM6DS0_CTRL_REG1_G				0x10
#define LSM6DS0_CTRL_REG2_G				0x11
#define LSM6DS0_CTRL_REG3_G				0x12
#define LSM6DS0_ORIENT_CFG_G			0x13
#define LSM6DS0_INT_GEN_SRC_G			0x14
#define LSM6DS0_OUT_TEMP_L				0x15
#define LSM6DS0_OUT_TEMP_H				0x16
#define LSM6DS0_STATUS_REG				0x17
#define LSM6DS0_OUT_X_L_G				0x18
#define LSM6DS0_OUT_X_H_G				0x19
#define LSM6DS0_OUT_Y_L_G				0x1A
#define LSM6DS0_OUT_Y_H_G				0x1B
#define LSM6DS0_OUT_Z_L_G				0x1C
#define LSM6DS0_OUT_Z_H_G				0x1D
#define LSM6DS0_CTRL_REG4				0x1E
#define LSM6DS0_CTRL_REG5_XL			0x1F
#define LSM6DS0_CTRL_REG6_XL			0x20
#define LSM6DS0_CTRL_REG7_XL			0x21
#define LSM6DS0_CTRL_REG8				0x22
#define LSM6DS0_CTRL_REG9				0x23
#define LSM6DS0_CTRL_REG10				0x24
#define LSM6DS0_INT_GEN_SRC_XL			0x26
#define LSM6DS0_STATUS_REG2				0x27
#define LSM6DS0_OUT_X_XL				0x28
#define LSM6DS0_OUT_X_H_XL				0x29
#define LSM6DS0_OUT_Y_XL				0x2A
#define LSM6DS0_OUT_Y_H_XL				0x2B
#define LSM6DS0_OUT_Z_XL				0x2C
#define LSM6DS0_OUT_Z_H_XL				0x2D
#define LSM6DS0_FIFO_CTRL				0x2E
#define LSM6DS0_FIFO_SRC				0x2F
#define LSM6DS0_INT_GEN_CFG_G			0x30
#define LSM6DS0_INT_GEN_THS_XH_G		0x31
#define LSM6DS0_INT_GEN_THS_XL_G		0x32
#define LSM6DS0_INT_GEN_THS_YH_G		0x33
#define LSM6DS0_INT_GEN_THS_YL_G		0x34
#define LSM6DS0_INT_GEN_THS_ZH_G		0x35
#define LSM6DS0_INT_GEN_THS_ZL_G		0x36
#define LSM6DS0_INT_GEN_DUR_G			0x37

#define LSM303D_ADDR				 	0xd6//0x3A
#define LSM303D_I_AM				 	0x68//0x49

/*** defines of some necessary options ***/

// speed of accelerometer sampling
#define ACC_OFF 		0x00
#define ACC_10_HZ		0x20
#define ACC_50_HZ		0x40
#define ACC_119_HZ		0x60
#define ACC_238_HZ		0x80
#define ACC_476_HZ		0xC0
#define ACC_952_HZ		0xE0
// accelerometer outputs settings
#define OUT_ACC_ON      0x38
#define OUT_ACC_OFF     0x00

/*** typedefs definition ***/
typedef uint8_t register_t;
typedef uint32_t event_t;
/*** end of typedefs definition ***/


// configuration of i2c interface
#define I2C_PORT I2C1
//#define I2C_PORT I2C2

extern void lsm_start_communication(void);
extern void lsm_write(register_t reg, const void* data, uint8_t size);
extern void lsm_read(register_t reg, void* data, uint8_t size);

extern void lsm_write_reg(register_t reg, uint8_t value);
extern uint8_t lsm_read_reg(register_t reg);
extern int16_t lsm_read_value(register_t reg);

#endif /* LSM6DS0_H_ */
