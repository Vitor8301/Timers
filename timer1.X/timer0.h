/* 
 * File:   timer0.h
 * Author: sn1011701
 *
 * Created on 31 de Maio de 2019, 15:45
 */

#ifndef TIMER0_H
#define	TIMER0_H

void initTimer0();
void intt0_1ms( void );
void setT0( int c );
int statusT0( void );
void setT0limite( int c );
int statusT0limite( void );

#endif	/* TIMER0_H */

