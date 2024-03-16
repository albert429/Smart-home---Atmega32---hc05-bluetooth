/*
 * main
 *
 *  Created on: Jul 23, 2023
 *      Author: user
 */

#include "../Include/MCAL/UART/UART_init.h"
#include "../Include/MCAL/DIO/MDIO_init.h"
#include "../Include/LIB/STD.h"
#include "../Include/LIB/BIT_MATH.h"
#include "string.h"
#define F_CPU   8000000UL
#include <util/delay.h>

void main(void)
{

	/*buzzer*/
	MDIO_VoidSetPinDirection(PORTA , PIN2 , PIN_OUT);
	/*led buzer*/
	MDIO_VoidSetPinDirection(PORTA , PIN3 , PIN_OUT);
	/*light*/
	MDIO_VoidSetPinDirection(PORTA , PIN4 , PIN_OUT);
	/*motor*/
	MDIO_VoidSetPinDirection(PORTA , PIN0 , PIN_OUT);
	MDIO_VoidSetPinDirection(PORTA , PIN1 , PIN_OUT);


	UART_voidInit();

   /*usersand passwords in system*/
	u8 user_1[]="user01";
	u8 user_2[]="user02";
	u8 user_3[]="user03";
	u8 user_4[]="user04";
	u8 user_5[]="user05";
	u8 user_6[]="user06";
	u8 user_7[]="user07";
	u8 user_8[]="user08";
	u8 user_9[]="user09";
	u8 user_10[]="user10";

	u8 p1[]= "1111";
	u8 p2[]= "2222";
	u8 p3[]= "3333";
	u8 p4[]= "4444";
	u8 p5[]= "5555";
	u8 p6[]= "6666";
	u8 p7[]= "7777";
	u8 p8[]= "8888";
	u8 p9[]= "9999";
	u8 p10[]="1010";


	/*flag to check*/
	u8 user_num=0;
	u8 pass_num=0;
	u8 user_found = 0;

	/*welcome message and welcome pass*/
	u8 welcome_message[]="Hello Enter User";
	u8 Enter_Pass[]="Enter Password";

	u8 error[]="User Not Found";

	u8 user_Enter[7];
	u8 pas_Enter[5];

	u8 i;
	u8 test ;
	u8 receive;
	u8 error_counter = 0;
	u8 choice = 0;

	/*to delay the code for start communication and to not forget welcome message*/
	UART_u8READByteSynchBlocking();
	UART_u8READByteSynchBlocking();


	while(1)
	{
		/*
		 M_UART_TX_String(welcome_message);
		 UART_voidSendByteSynchNonBlocking('\0');


		  for(int i = 0 ; i<7 ; i++)
		  {
			  receive = UART_u8READByteSynchBlocking();
			  user_Enter[i]=receive;

		  }


         to show user
		  M_UART_TX_String(user_Enter);
		  UART_voidSendByteSynchNonBlocking('\0');

		  //to compare
		  test = strcmp(user_Enter , user_1);
		  if(test == 0)
		  {
			 M_UART_TX_String(Enter_Pass);
			 UART_voidSendByteSynchNonBlocking('\0');

			  for(int i = 0 ; i<5 ; i++)
			  {
				  receive = UART_u8READByteSynchBlocking();
				  pas_Enter[i]=receive;

			  }

			  M_UART_TX_String(pas_Enter);
			  UART_voidSendByteSynchNonBlocking('\0');

			 // to compare
			  test = strcmp(pas_Enter , p1);
			  if(test==0)
			  {
				  M_UART_TX_String("Welcome in Home");
				   UART_voidSendByteSynchNonBlocking('\0');
			  }

		  }

		  else
		  {
			  M_UART_TX_String(error);
			  UART_voidSendByteSynchNonBlocking('\0');
		  }
      */


		 M_UART_TX_String(welcome_message);
		 UART_voidSendByteSynchNonBlocking('\0');

		  for(i = 0 ; i < 7 ; i++)
		  {
			  //to store string from uart in user_enter
			  receive = UART_u8READByteSynchBlocking();
			  user_Enter[i]=receive;
		  }

//		 receive = UART_u8READByteSynchBlocking();
//		 i=0;
//		 while(receive != 0)
//		 {
//			 //to store string from uart in user_enter
//			 user_Enter[i]=receive;
//			 receive = UART_u8READByteSynchBlocking();
//			 i++;
//		 }
//		 M_UART_TX_String(user_Enter);


		 M_UART_TX_String(Enter_Pass);
		 UART_voidSendByteSynchNonBlocking('\0');

		  for(int i = 0 ; i<5 ; i++)
		  {
			  // to store password in pasenter
			  receive = UART_u8READByteSynchBlocking();
			  pas_Enter[i]=receive;
		  }
//		  M_UART_TX_String(pas_Enter);

         /*
		 receive = UART_u8READByteSynchBlocking();
		 i=0;
		 while(receive != 0)
		 {
			 //to store string from uart in user_enter
			 pas_Enter[i]=receive;
			 receive = UART_u8READByteSynchBlocking();
			 i++;
		 }
		 */


		  /*to check user is valid or not*/
		  if(strcmp(user_Enter , user_1) == 0)
		  {
			  user_num = 1;
		  }

		  else if(strcmp(user_Enter , user_2) == 0)
		  {
			  user_num = 2;
		  }

		  else if(strcmp(user_Enter , user_3) == 0)
		  {
			  user_num = 3;
		  }

		  else if(strcmp(user_Enter , user_4) == 0)
		  {
			  user_num = 4;
		  }

		  else if(strcmp(user_Enter , user_5) == 0)
		  {
			  user_num = 5;
		  }

		  else if(strcmp(user_Enter , user_6) == 0)
		  {
			  user_num = 6;
		  }

		  else if(strcmp(user_Enter , user_7) == 0)
		  {
			  user_num = 7;
		  }

		  else if(strcmp(user_Enter , user_8) == 0)
		  {
			  user_num = 8;
		  }
		  else if(strcmp(user_Enter , user_9) == 0)
		  {
			  user_num = 9;
		  }
		  else if(strcmp(user_Enter , user_10) == 0)
		  {
			  user_num = 10;
		  }
		  else
		  {
			  user_num = 0 ;
		  }



		  /*to check password is valid or not*/
		  if(strcmp(pas_Enter , p1) == 0)
		  {
			  pass_num = 1;
		  }

		  else if(strcmp(pas_Enter , p2) == 0)
		  {
			  pass_num = 2;
		  }

		  else if(strcmp(pas_Enter , p3) == 0)
		  {
			  pass_num = 3;
		  }

		  else if(strcmp(pas_Enter , p4) == 0)
		  {
			  pass_num = 4;
		  }

		  else if(strcmp(pas_Enter , p5) == 0)
		  {
			  pass_num = 5;
		  }

		  else if(strcmp(pas_Enter , p6) == 0)
		  {
			  pass_num = 6;
		  }

		  else if(strcmp(pas_Enter , p7) == 0)
		  {
			  pass_num = 7;
		  }

		  else if(strcmp(pas_Enter , p8) == 0)
		  {
			  pass_num = 8;
		  }
		  else if(strcmp(pas_Enter , p9) == 0)
		  {
			  pass_num = 9;
		  }
		  else if(strcmp(pas_Enter , p10) == 0)
		  {
			  pass_num = 10;
		  }
		  else
		  {
			  pass_num = 0 ;
		  }



		  if(user_num == 0 ||  pass_num == 0 || user_num != pass_num)
		  {
			  M_UART_TX_String(error);
			 UART_voidSendByteSynchNonBlocking('\0');
			  error_counter ++;
			  if(error_counter == 3)
			  {
				  M_UART_TX_String("You are a  Thief");
				  UART_voidSendByteSynchNonBlocking('\0');
				  MDIO_VoidSetPinValue(PORTA , PIN2 , PIN_HIGH);
				  MDIO_VoidSetPinValue(PORTA , PIN3 , PIN_HIGH);

			  }
		  }

		  else
		  {
			  error_counter = 0 ;
			  MDIO_VoidSetPinValue(PORTA , PIN2 , PIN_LOW);
			  MDIO_VoidSetPinValue(PORTA , PIN3 , PIN_LOW);
			  M_UART_TX_String("Welcome In your Home");
			  UART_voidSendByteSynchNonBlocking('\0');
			  user_found = 1;
		  }

		  while(user_found)
		  {
			  M_UART_TX_String("This Is Your choices");
			  UART_voidSendByteSynchNonBlocking('\0');

			  M_UART_TX_String("D-> To open Door");
			  UART_voidSendByteSynchNonBlocking('\0');

			  M_UART_TX_String("L-> To Open Led");
			  UART_voidSendByteSynchNonBlocking('\0');

			  M_UART_TX_String("F-> To Off Led");
			  UART_voidSendByteSynchNonBlocking('\0');

			  M_UART_TX_String("E-> Log Out");
			  UART_voidSendByteSynchNonBlocking('\0');


			  choice = UART_u8READByteSynchBlocking();

			  switch(choice)
			  {
			  case 'D' :
				  MDIO_VoidSetPinValue(PORTA , PIN0 , PIN_LOW);
				  MDIO_VoidSetPinValue(PORTA , PIN1 , PIN_HIGH);
				  _delay_ms(2000);
				  MDIO_VoidSetPinValue(PORTA , PIN0 , PIN_LOW);
				  MDIO_VoidSetPinValue(PORTA , PIN1 , PIN_LOW);
				  _delay_ms(5000);
				  MDIO_VoidSetPinValue(PORTA , PIN0 , PIN_HIGH);
				  MDIO_VoidSetPinValue(PORTA , PIN1 , PIN_LOW);
				  _delay_ms(2000);
				  MDIO_VoidSetPinValue(PORTA , PIN0 , PIN_LOW);
				  MDIO_VoidSetPinValue(PORTA , PIN1 , PIN_LOW);
				  break;

			  case 'L' :
				  MDIO_VoidSetPinValue(PORTA , PIN4 , PIN_HIGH);
				  break;

			  case 'F' :
				  MDIO_VoidSetPinValue(PORTA , PIN4 , PIN_LOW);
				  break;

			  case 'E' :
				  user_found = 0;
				  UART_u8READByteSynchBlocking();
				  break;

			  default:
				  M_UART_TX_String("Enter right choice");
				  UART_voidSendByteSynchNonBlocking('\0');
				  break;
			  }

		  }



	}

}



