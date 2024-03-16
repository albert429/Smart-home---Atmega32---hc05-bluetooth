/*
 * MDIO_prc.c
 *
 * Created: 3/26/2023 10:07:34 AM
 *  Author: Peter
 */ 

//////////////////////////////////////////////////INCLUDES//////////////////////////////////////////////////////////

#include "../Include/LIB/STD.h"
#include "../Include/LIB/BIT_MATH.h"


#include "../Include/MCAL/DIO/MDIO_init.h"
#include "../Include/MCAL/DIO/MDIO_prv.h"
#include "../Include/MCAL/DIO/MDIO_cfg.h"

//////////////////////////////////////////////////////IMPLEMENTATON//////////////////////////////////////////////////

void  MDIO_VoidSetPinDirection (u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8Dir)
{
	switch(Copy_u8Dir)
	{
		case PIN_IN :
		switch(Copy_u8Port)
		{
			case PORTA :
			CLR_BIT(MDIO_DDRA , Copy_u8Pin);
			break;
			
			case PORTB :
			CLR_BIT(MDIO_DDRB , Copy_u8Pin);
			break;			
			
			case PORTC :
			CLR_BIT(MDIO_DDRC , Copy_u8Pin);
			break;
	
			case PORTD :
			CLR_BIT(MDIO_DDRD , Copy_u8Pin);
			break;
			
			default:
			break;						
		}
		break;
		
		case PIN_OUT :
		switch(Copy_u8Port)
		{
			case PORTA :
			SET_BIT(MDIO_DDRA , Copy_u8Pin);
			break;
			
			case PORTB :
			SET_BIT(MDIO_DDRB , Copy_u8Pin);
			break;
			
			case PORTC :
			SET_BIT(MDIO_DDRC , Copy_u8Pin);
			break;
			
			case PORTD :
			SET_BIT(MDIO_DDRD , Copy_u8Pin);
			break;
			
			default:
			break;
		}
		break;
		
		default:
		break;
	}
}


void  MDIO_VoidSetPinValue(u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8Value)
{
	switch(Copy_u8Value)
	{
		case PIN_LOW :
		switch(Copy_u8Port)
		{
			case PORTA :
			CLR_BIT(MDIO_PORTA , Copy_u8Pin);
			break;
			
			case PORTB :
			CLR_BIT(MDIO_PORTB , Copy_u8Pin);
			break;
			
			case PORTC :
			CLR_BIT(MDIO_PORTC , Copy_u8Pin);
			break;
			
			case PORTD :
			CLR_BIT(MDIO_PORTD , Copy_u8Pin);
			break;
			
			default:
			break;
		}
		break;
		
		case PIN_HIGH :
		switch(Copy_u8Port)
		{
			case PORTA :
			SET_BIT(MDIO_PORTA , Copy_u8Pin);
			break;
			
			case PORTB :
			SET_BIT(MDIO_PORTB , Copy_u8Pin);
			break;
			
			case PORTC :
			SET_BIT(MDIO_PORTC , Copy_u8Pin);
			break;
			
			case PORTD :
			SET_BIT(MDIO_PORTD , Copy_u8Pin);
			break;
			
			default:
			break;
		}
		break;
		
		default:
		break;
	}	
}

u8    MDIO_GetPinValue (u8 Copy_u8Port , u8 Copy_u8Pin)
{
	u8 local_u8Data = 0;
	switch(Copy_u8Port)
	{
		case PORTA :
		local_u8Data = GET_BIT(MDIO_PINA , Copy_u8Pin);
		break;
		
		case PORTB :
		local_u8Data = GET_BIT(MDIO_PINB , Copy_u8Pin);
		break;
		
		case PORTC :
		local_u8Data = GET_BIT(MDIO_PINC , Copy_u8Pin);
		break;
		
		case PORTD :
		local_u8Data = GET_BIT(MDIO_PIND , Copy_u8Pin);
		break;	
		
		default:
		break;					
	}
	return local_u8Data;
}

void  MDIO_VoidSetPortDirecton (u8 Copy_u8Port , u8 Copy_u8Dir)
{
	switch(Copy_u8Port)
	{
		case PORTA :
		MDIO_DDRA = Copy_u8Dir;
		break;
		
		case PORTB :
		MDIO_DDRB = Copy_u8Dir;
		break;
		
		case PORTC :
		MDIO_DDRC = Copy_u8Dir;
		break;
		
		case PORTD :
		MDIO_DDRD = Copy_u8Dir;
		break;
		
		default:
		break;
	}	
}

void  MDIO_VoidSetPortValue (u8 Copy_u8Port , u8 Copy_u8Val)
{
	switch(Copy_u8Port)
	{
		case PORTA :
		MDIO_PORTA = Copy_u8Val;
		break;
		
		case PORTB :
		MDIO_PORTB = Copy_u8Val;
		break;
		
		case PORTC :
		MDIO_PORTC = Copy_u8Val;
		break;
		
		case PORTD :
		MDIO_PORTC = Copy_u8Val;
		break;
		
		default:
		break;
	}
	
}

u8 MDIO_u8GetPortValue (u8 Copy_u8Port)
{
	u8 local_u8Data = 0;
	
	switch(Copy_u8Port)
	{
		case PORTA :
		local_u8Data = MDIO_PINA;
		break;
		
		case PORTB :
		local_u8Data = MDIO_PINB;
		break;
			
		case PORTC :
		local_u8Data = MDIO_PINC;
		break;
		
		case PORTD :
		local_u8Data = MDIO_PIND;
		break;
		
		default:
		break;	
	}
	return local_u8Data;
}

void  MDIO_VoidTogglePin (u8 Copy_u8Port , u8 Copy_u8Pin)
{
	switch(Copy_u8Port)
	{
		case PORTA :
		Toggle_BIT(MDIO_PORTA , Copy_u8Pin);
		break;
		
		case PORTB :
		Toggle_BIT(MDIO_PORTB , Copy_u8Pin);
		break;
		
		case PORTC :
		Toggle_BIT(MDIO_PORTC , Copy_u8Pin);
		break;
		
		case PORTD :
		Toggle_BIT(MDIO_PORTD , Copy_u8Pin);
		break;
		
		default:
		break;						
	}
}

void  MDIO_VoidTogglePort (u8 Copy_u8Port)
{
	switch(Copy_u8Port)
	{
		case PORTA :
		MDIO_PORTA ^= TOGGLE_PORT;
		break;
		
		case PORTB :
		MDIO_PORTB ^= TOGGLE_PORT;
		break;

		case PORTC :
		MDIO_PORTC ^= TOGGLE_PORT;
		break;
		
		case PORTD :
		MDIO_PORTD ^= TOGGLE_PORT;
		break;	
		
		default:
		break;			
	}
}


void  MDIO_VoidSetPullupResistor  (u8 Copy_u8Port , u8 Copy_u8Pin) 
{
	switch(Copy_u8Port)
	{
		case PORTA :
		SET_BIT(MDIO_PORTA , Copy_u8Pin);
		break;
		
		case PORTB :
		SET_BIT(MDIO_PORTB , Copy_u8Pin);
		break;
		
		case PORTC :
		SET_BIT(MDIO_PORTC , Copy_u8Pin);
		break;
		
		case PORTD :
		SET_BIT(MDIO_PORTD , Copy_u8Pin);
		break;						
		
		default:
		break;
	}
}
