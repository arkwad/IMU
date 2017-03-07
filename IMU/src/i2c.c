/*
 * i2c.c
 *
 *  Created on: 6 mar 2017
 *      Author: Arek
 */
#include "lsm303d.h"
#include "i2c.h"
#include "stm32f10x.h"




/*** static functions definitions ***/
void static wait_until_ev_occur(event_t event)
{
	while (SUCCESS != I2C_CheckEvent(I2C_PORT, event));
}
void static prepare_dev_to_communication(uint8_t address)
{
	I2C_GenerateSTART(I2C_PORT, ENABLE);  // generate STAR signal via i2c
	wait_until_ev_occur( I2C_EVENT_MASTER_MODE_SELECT );

	I2C_Send7bitAddress(I2C_PORT, LSM303D_ADDR, I2C_Direction_Transmitter); // send address of dev and set master as transmitter
	wait_until_ev_occur( I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED );

	I2C_SendData(I2C_PORT, 0x80 | address);  // send address of register we want to use
	wait_until_ev_occur( I2C_EVENT_MASTER_BYTE_TRANSMITTING);
}
/*** end of static functions definitions ***/



/*** interface functions ***/
void i2c_run_periph(I2C_TypeDef * slot)
{

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_I2C1, ENABLE);

	GPIO_InitTypeDef gpio;
	I2C_InitTypeDef i2c;

	GPIO_StructInit(&gpio);
	gpio.GPIO_Pin = GPIO_Pin_6|GPIO_Pin_7; // SCL, SDA
	gpio.GPIO_Mode = GPIO_Mode_AF_OD;
	gpio.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &gpio);


	I2C_StructInit(&i2c);
	i2c.I2C_Mode = I2C_Mode_I2C;
	i2c.I2C_ClockSpeed = 100000;
	I2C_Init(I2C1, &i2c);
	I2C_Cmd(I2C1, ENABLE);

}
void i2c_send_data(uint8_t address,const uint8_t * data, uint8_t data_length )
{
	uint8_t i;
	prepare_dev_to_communication(address);

	for (i = 0; i <= data_length - 1 ; i++)
	{
		I2C_SendData(I2C_PORT, data[i]);
		wait_until_ev_occur( I2C_EVENT_MASTER_BYTE_TRANSMITTING );
	}

	I2C_GenerateSTOP(I2C_PORT, ENABLE);
}

void i2c_receive_data(uint8_t address,uint8_t * data, uint8_t data_length )
{
	uint8_t i;

	prepare_dev_to_communication(address);


	I2C_GenerateSTART(I2C_PORT, ENABLE);
	wait_until_ev_occur(I2C_EVENT_MASTER_MODE_SELECT);

	I2C_AcknowledgeConfig(I2C_PORT, ENABLE);
	I2C_Send7bitAddress(I2C_PORT, LSM303D_ADDR, I2C_Direction_Receiver);
	wait_until_ev_occur( I2C_EVENT_MASTER_RECEIVER_MODE_SELECTED );

	for (i = 0; i < data_length - 1; i++)
	{
		wait_until_ev_occur( I2C_EVENT_MASTER_BYTE_RECEIVED );
	    data[i] = I2C_ReceiveData(I2C_PORT);
	}

	I2C_AcknowledgeConfig(I2C_PORT, DISABLE);
    I2C_GenerateSTOP(I2C_PORT, ENABLE);
    wait_until_ev_occur( I2C_EVENT_MASTER_BYTE_RECEIVED );
    data[i] = I2C_ReceiveData(I2C_PORT); //?

}



