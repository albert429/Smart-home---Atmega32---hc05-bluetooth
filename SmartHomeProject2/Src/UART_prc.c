/****************************************************/
/*   AUTHOR      : Abdelrahman Hossam               */
/*   Description : UART DRIVER                      */
/*   DATE        : 01 FEB 2022                      */
/*   VERSION     : V01                              */
/****************************************************/

/****************************************************/
/* Library Directives							    */
/****************************************************/
#include"../Include/LIB/STD.h"
#include"../Include/LIB/BIT_MATH.h"

/****************************************************/
/* UART Directives								    */
/****************************************************/
#include"../Include/MCAL/UART/UART_init.h"
#include"../Include/MCAL/UART/UART_prv.h"
#include"../Include/MCAL/UART/UART_cfg.h"



static void (*FuncPtr[3])(void)={NULL,NULL,NULL};

void UART_voidInit(void)
{

	u16 Local_u16BaudRateValue = BAUD_RATE_EQUATION;
	/*  Store the low byte of the UBBR*/
	UART_u8_UBRRL =  (u8) Local_u16BaudRateValue;

	/*  Store the High byte of the UBBR*/
	UART_u8_UBRRH = (u8)((Local_u16BaudRateValue)>>8);

	#if USART_DOUBLE_SPEED==DOUBLE_SPEED_ON
	SET_BIT(UART_u8_UCSRA,UCSRA_U2X_BIT);
	#else
	CLR_BIT(UART_u8_UCSRA,UCSRA_U2X_BIT);
	#endif

	#if CHARACTER_SIZE== CHAR_NINE_BIT
		#define UCSZ2_BIT_VALUE BIT_SET
		#define UCSZ1_BIT_VALUE BIT_SET
		#define UCSZ0_BIT_VALUE BIT_SET
	#elif CHAR_EIGHT_BIT
		#define UCSZ2_BIT_VALUE BIT_CLEARED
		#define UCSZ1_BIT_VALUE BIT_SET
		#define UCSZ0_BIT_VALUE BIT_SET
	#elif CHAR_SEVEN_BIT
		#define UCSZ2_BIT_VALUE BIT_CLEARED
		#define UCSZ1_BIT_VALUE BIT_SET
		#define UCSZ0_BIT_VALUE BIT_CLEARED
	#elif CHAR_SIX_BIT
		#define UCSZ2_BIT_VALUE BIT_CLEARED
		#define UCSZ1_BIT_VALUE BIT_CLEARED
		#define UCSZ0_BIT_VALUE BIT_SET
	#elif CHAR_FIVE_BIT
		#define UCSZ2_BIT_VALUE BIT_CLEARED
		#define UCSZ1_BIT_VALUE BIT_CLEARED
		#define UCSZ0_BIT_VALUE BIT_CLEARED
	#endif

	#if PARITY_MODE==PARITY_DISABLE
		#define UPM1_BIT_VALUE BIT_CLEARED
		#define UPM0_BIT_VALUE BIT_CLEARED
	#elif PARITY_MODE==PARITY_EVEN
		#define UPM1_BIT_VALUE BIT_SET
		#define UPM0_BIT_VALUE BIT_CLEARED
	#elif PARITY_MODE==PARITY_ODD
		#define UPM1_BIT_VALUE BIT_SET
		#define UPM0_BIT_VALUE BIT_SET
	#endif


	UART_u8_UCSRB= CONC_BIT(USART_RX_INTERRUPT_ENABLE,
							USART_TX_INTERRUPT_ENABLE,
							USART_DATA_REGISTER_INTERRUPT_ENABLE,
							ENABLE_RX,
							ENABLE_TX,
							UCSZ2_BIT_VALUE,
							DONOT_CARE_BIT,
							DONOT_CARE_BIT);

	UART_u8_UCSRC= CONC_BIT(UCSRB_REGISTER_SELECT,
						    MODE_OF_OPERATION,
						    UPM1_BIT_VALUE,
						    UPM0_BIT_VALUE,
						    STOP_BITS_MODE,
						    UCSZ1_BIT_VALUE,
						    UCSZ0_BIT_VALUE,
						    CLOCK_POLARITY);

}


void UART_voidSendByteSynchNonBlocking (u8 copy_u8Byte)
{
	u32 Local_u32TimeOut =0 ;
	while (GET_BIT(UART_u8_UCSRA,UCSRA_UDRIE_BIT)==FLAG_DOWN)
	{
		Local_u32TimeOut++;
		if (Local_u32TimeOut==TIME_OUT)
		{
			break;
		}
	}

	if (Local_u32TimeOut!=TIME_OUT)
	{
		Local_u32TimeOut=0;
		/* Set byte to be transmitted */
		UART_u8_UDR= copy_u8Byte;
		/* check the bit5 (UDRE) is a flag bit to figure that if the UDR register empty or not */
		while(GET_BIT(UART_u8_UCSRA,UCSRA_UDRIE_BIT)==FLAG_DOWN)
		{
			Local_u32TimeOut++;
			if (Local_u32TimeOut==TIME_OUT)
			{
				break;
			}
		}
		//clear the transmit interrupt flag
		SET_BIT(UART_u8_UCSRA,UCSRA_TXCIE_BIT);
	}

}

void UART_voidSendByteSynchBlocking (u8 copy_u8Byte)
{
		while (GET_BIT(UART_u8_UCSRA,UCSRA_UDRIE_BIT)==FLAG_DOWN);
		/* Set byte to be transmitted */
		UART_u8_UDR= copy_u8Byte;
		/* check the bit5 (UDRE) is a flag bit to figure that if the UDR register empty or not */
		while(GET_BIT(UART_u8_UCSRA,UCSRA_UDRIE_BIT)==FLAG_DOWN);
		//clear the transmit interrupt flag
		SET_BIT(UART_u8_UCSRA,UCSRA_TXCIE_BIT);

}


void UART_voidSendByteAsynch(u8 copy_u8Byte)
{
	/* Set byte to be transmitted */
	UART_u8_UDR= copy_u8Byte;
}


u8 UART_u8READByteSynchBlocking (void)
{
	while(GET_BIT(UART_u8_UCSRA,UCSRA_RXCIE_BIT)==FLAG_DOWN);
	return UART_u8_UDR;
}

u8 UART_u8READByteSynchNonBlocking (void)
{
	u32 Local_u32TimeOut =0 ;
	u8  Loval_u8Value=VALUE_RETURN_NO_RECIEVED_DATA;
	while (GET_BIT(UART_u8_UCSRA,UCSRA_RXCIE_BIT)==FLAG_DOWN)
	{
		Local_u32TimeOut++;
		if (Local_u32TimeOut==TIME_OUT)
		{
			break;
		}
	}
	if (Local_u32TimeOut!=TIME_OUT)
	{
		Loval_u8Value=UART_u8_UDR;
	}
	return Loval_u8Value;
}



u8 UART_u8READByteAsynch (void)
{
	return UART_u8_UDR;
}

void UART_voidSetCallBack(u8 copy_u8InterruptType, void (*copy_PtrFunc)(void))
{
	if ((copy_u8InterruptType <= USART_UDRE_INTERRUPT)&&(copy_PtrFunc !=NULL))
	{
		FuncPtr[copy_u8InterruptType]=copy_PtrFunc;
	}
}


void __vector_13(void)    __attribute__((signal));
void __vector_13(void)
{
	if (FuncPtr[USART_RX_INTERRUPT] != NULL)
		{
		FuncPtr[USART_RX_INTERRUPT]();
		}
}

void __vector_14(void)    __attribute__((signal));
void __vector_14(void)
{
	if (FuncPtr[USART_UDRE_INTERRUPT] != NULL)
		{
			FuncPtr[USART_UDRE_INTERRUPT]();
		}
}

void __vector_15(void)    __attribute__((signal));
void __vector_15(void)
{
	if (FuncPtr[USART_TX_INTERRUPT] != NULL)
		{
			FuncPtr[USART_TX_INTERRUPT]();
		}
}



void M_UART_TX_String(u8 *str)
{
	u8 i = 0;
	while(str[i] != '\0')
	{
		UART_voidSendByteSynchNonBlocking(str[i]);
		i++;
	}
}


