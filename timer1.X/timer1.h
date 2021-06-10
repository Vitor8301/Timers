/* 
 * File:   timer0.h
 * Author: sn1011701
 *
 * Created on 31 de Maio de 2019, 15:45
 */

#ifndef TIMER1_H
#define	TIMER1_H

extern unsigned int contador;
void initTimer1( void );
void intt1_1ms( void );
void setT1( long c );
int statusT1( void );
void setT1limite( long d );
int statusT1limite( void );

#endif	/* TIMER0_H */

