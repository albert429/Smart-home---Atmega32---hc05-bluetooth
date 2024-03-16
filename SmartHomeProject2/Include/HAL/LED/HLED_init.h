/*
 * HLED_init.h
 *
 * Created: 3/26/2023 12:15:27 PM
 *  Author: Peter
 */ 


#ifndef HLED_INIT_H_
#define HLED_INIT_H_
///////////////////////////////////////////////INCLUDES//////////////////////////////////////////////////
#include "../../LIB/STD.h"
#include "../../LIB/BIT_MATH.h"
#include "HLED_cfg.h"


/////////////////////////////////////////////////Protypes///////////////////////////////////////////////////
void HLED_VoidInit   (u8 Copy_u8LedPin);
void HLED_VoidON     (u8 Copy_u8LedPin);
void HLED_VoidOFF    (u8 Copy_u8LedPin);
void HLED_VoidToggle (u8 Copy_u8LedPin);



#endif /* HLED_INIT_H_ */