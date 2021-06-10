/*
 * File:   timer0.c
 * Author: sn1011701
 *
 * Created on 31 de Maio de 2019, 15:42
 */

#include <xc.h>
#include <pic16f887.h>
#include "config.h"
#include "timer1.h"

unsigned int contador;
int t1final = 0;
int t1cont = 0;

void __interrupt() irq(void)
{
    if( PIE1bits.TMR1IE && PIR1bits.TMR1IF )
    {
        PIR1bits.TMR1IF = 0;
        intt1_1ms();
    }
}

void intt1_1ms( void )
{
    TMR1H = ((65536-1000)>>8) & 0x00FF;
    TMR1L =  (65536-1000)     & 0x00FF;
    if( ++t1cont >= t1final )
    {
        t1cont = 0;
    }
}

void setT1( long c )
{
    t1cont = c;
}

int statusT1( void )
{
    return( t1cont );
}

void setT1limite( long d )
{
    t1final = d;
}

int statusT1limite( void )
{
    return( t1final );
}

void initTimer1( void )
{
    INTCONbits.GIE = 0;
    T1CONbits.TMR1CS = 0;
    T1CONbits.T1CKPS1 = 0;
    T1CONbits.T1CKPS0 = 0;
    T1CONbits.TMR1GE = 0;

    setT1limite( 1000 );
    
    T1CONbits.TMR1ON = 1;
    INTCONbits.PEIE = 1;
    PIE1bits.TMR1IE =1;
    INTCONbits.GIE = 1;
}

