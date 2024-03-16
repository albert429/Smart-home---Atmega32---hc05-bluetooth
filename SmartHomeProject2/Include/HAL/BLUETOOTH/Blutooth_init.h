/*
 * Blutooth_init.h
 *
 * Created: 4/10/2023 12:11:54 AM
 *  Author: Peter
 */ 


#ifndef BLUTOOTH_INIT_H_
#define BLUTOOTH_INIT_H_
///////////////////////////////////////////Includes/////////////////////////////////////////////

#include "../../LIB/STD.h"
////////////////////////////////////Protypes///////////////////////////////////////////////////


void H_BLutooth_Init(void);
void H_BLutooth_TRANSMIT(u8 data);
u8 H_BLutooth_RECEIVE(void);


#endif /* BLUTOOTH_INIT_H_ */
