/*
 * MDIO_init.h
 *
 * Created: 3/26/2023 10:06:54 AM
 *  Author: Peter
 */ 


#ifndef MDIO_INIT_H_
#define MDIO_INIT_H_

////////////////////////////////////////INCLUDES////////////////////////
#include "../../LIB/STD.h"

///////////////**********//////////PORTS//////////////////////////////
#define PORTA    0
#define PORTB    1
#define PORTC    2
#define PORTD    3


///////////////////////// PINS ///////////////////////////////////////////
#define PIN0     0
#define PIN1     1
#define PIN2     2
#define PIN3     3
#define PIN4     4
#define PIN5     5
#define PIN6     6
#define PIN7     7
////////////////////////////////PORT DIRECTIONS ///////////////////////////
#define PORT_IN    0
#define PORT_OUT   1
///////////////////////////////////PORT VALUES/////////////////////////////
#define PORT_LOW    0
#define PORT_HIGH   1
/////////////////////////////////PIN DIRECTIONS////////////////////////////
#define PIN_IN    0
#define PIN_OUT   1
/////////////////////////////PIN VALUES//////////////////////////////////////
#define PIN_LOW    0
#define PIN_HIGH   1
/////////////////////////////////TOOGLE PORt/////////////////////////////////////
#define  TOGGLE_PORT   0xff




////////////////////////////////////////////////////////////PROTOTYPE///////////////////
void  MDIO_VoidSetPinDirection    (u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8Dir);
void  MDIO_VoidSetPinValue        (u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8Value);
u8    MDIO_GetPinValue            (u8 Copy_u8Port , u8 Copy_u8Pin);
void  MDIO_VoidTogglePin          (u8 Copy_u8Port , u8 Copy_u8Pin);

void  MDIO_VoidSetPortDirecton       (u8 Copy_u8Port , u8 Copy_u8Dir);
void  MDIO_VoidSetPortValue          (u8 Copy_u8Port , u8 Copy_u8Val);
u8    MDIO_u8GetPortValue           (u8 Copy_u8Port);
void  MDIO_VoidTogglePort            (u8 Copy_u8Port);


void  MDIO_VoidSetPullupResistor  (u8 Copy_u8Port , u8 Copy_u8Pin) ;





#endif /* MDIO_INIT_H_ */
