/*
 * HLED_prc.c
 *
 * Created: 3/26/2023 12:15:49 PM
 *  Author: Peter
 */ 

//////////////////////////////////////////////////////INCLUDES///////////////////////////////////////////

#include "../Include/MCAL/DIO/MDIO_init.h"
#include"../Include/HAL/LED/HLED_init.h"
#include"../Include/HAL/LED/HLED_prv.h"
#include"../Include/HAL/LED/HLED_cfg.h"


/////////////////////////////////////////////////IMPLEMENTATION///////////////////////////////////////////////////
void HLED_VoidInit    (u8 Copy_u8LedPin)
{
	switch(Copy_u8LedPin)
	{
		case HLED0_Pin :
		MDIO_VoidSetPinDirection(HLED0_Port , HLED0_Pin , PIN_OUT);
		break;
		
		case HLED1_Pin :
		MDIO_VoidSetPinDirection(HLED1_Port , HLED1_Pin , PIN_OUT);
		break;
		
		case HLED2_Pin :
		MDIO_VoidSetPinDirection(HLED2_Port , HLED2_Pin , PIN_OUT);
		break;
		
		default:
		break;				
	}
}

void HLED_VoidON (u8 Copy_u8LedPin)
{
	switch(Copy_u8LedPin)
	{
		case HLED0_Pin :
		MDIO_VoidSetPinValue(HLED0_Port , HLED0_Pin , PIN_HIGH);
		break;
		
		case HLED1_Pin :
		MDIO_VoidSetPinValue(HLED1_Port , HLED1_Pin , PIN_HIGH);
		break;
		
		case HLED2_Pin :
		MDIO_VoidSetPinValue(HLED2_Port , HLED2_Pin , PIN_HIGH);
		break;
		
		default:
		break;
	}
	
}
void HLED_VoidOFF    (u8 Copy_u8LedPin)
{
	switch(Copy_u8LedPin)
	{
		case HLED0_Pin :
		MDIO_VoidSetPinValue(HLED0_Port , HLED0_Pin , PIN_LOW);
		break;
		
		case HLED1_Pin :
		MDIO_VoidSetPinValue(HLED1_Port , HLED1_Pin , PIN_LOW);
		break;
		
		case HLED2_Pin :
		MDIO_VoidSetPinValue(HLED2_Port , HLED2_Pin , PIN_LOW);
		break;
		
		default:
		break;
	}
}


void HLED_VoidToggle (u8 Copy_u8LedPin)
{
	switch(Copy_u8LedPin)
	{
		case HLED0_Pin :
		MDIO_VoidTogglePin(HLED0_Port , HLED0_Pin);
		break;
		
		case HLED1_Pin :
		MDIO_VoidTogglePin(HLED1_Port , HLED1_Pin);
		break;
		
		case HLED2_Pin :
		MDIO_VoidTogglePin(HLED2_Port , HLED2_Pin);
		break;
		
		default:
		break;
	}
}
