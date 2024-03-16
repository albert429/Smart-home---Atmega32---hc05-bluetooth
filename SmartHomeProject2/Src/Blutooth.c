/*
 * Blutooth.c
 *
 * Created: 4/10/2023 12:12:27 AM
 *  Author: Peter
 */ 
///////////////////////////////////////////Includes/////////////////////////////////////////////
#include "../Include/HAL/BLUETOOTH/Blutooth_init.h"
#include "../Include/HAL/BLUETOOTH/Blutooth_cfg.h"

#include "../Include/MCAL/UART/UART_init.h"

////////////////////////////////////Implementations///////////////////////////////////////////////
void H_BLutooth_Init(void)
{
	//M_UART_Init();
}
void H_BLutooth_TRANSMIT(u8 data)
{
	//M_UART_TRANSMIT(data);
}
u8 H_BLutooth_RECEIVE(void)
{
	u8 data = 0 ;
	//data = M_UART_RECEIVE();
	return data;
}
