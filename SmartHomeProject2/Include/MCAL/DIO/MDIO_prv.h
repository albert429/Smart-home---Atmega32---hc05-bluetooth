/*
 * MDIO_prv.h
 *
 * Created: 3/26/2023 10:06:31 AM
 *  Author: Peter
 */ 


#ifndef MDIO_PRV_H_
#define MDIO_PRV_H_


//////////////////////////////////////DIO REGISTERS////////////////////////////////////

#define MDIO_DDRA  (*(volatile u8*)(0x3A))
#define MDIO_PORTA (*(volatile u8*)(0x3B))
#define MDIO_PINA  (*(volatile u8*)(0x39))

#define MDIO_DDRB  (*(volatile u8*)(0x37))
#define MDIO_PORTB (*(volatile u8*)(0x38))
#define MDIO_PINB  (*(volatile u8*)(0x36))

#define MDIO_DDRC  (*(volatile u8*)(0x34))
#define MDIO_PORTC (*(volatile u8*)(0x35))
#define MDIO_PINC (*(volatile u8*)(0x33))

#define MDIO_DDRD  (*(volatile u8*)(0x31))
#define MDIO_PORTD (*(volatile u8*)(0x32))
#define MDIO_PIND  (*(volatile u8*)(0x30))


#endif /* MDIO_PRV_H_ */