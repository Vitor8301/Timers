/*
 * File:   timers.c
 * Author: sn1011701
 *
 * Created on 9 de Junho de 2021, 13:46
 */


#include <xc.h>
//#pragma interrupt irq

unsigned int contador;

int t1seg;

void timers_init( void )
{
    OPTION_REGbits.T0CS = 0;
    OPTION_REGbits.PSA = 1;
    TMR0 = 256-100;
    INTCONbits.TMR0IE = 1;
    INTCONbits.GIE = 1;
    contador = 0;
    t1seg = 10000;
}

void __interrupt() isr (void)
{
    INTCONbits.GIE = 0;
    if( INTCONbits.T0IF )
    {
        INTCONbits.T0IF = 0;
        TMR0 = 256-100;
        --t1seg;
        if( !t1seg )
        {
            contador++;
            t1seg = 10000;
        }
    }
    INTCONbits.GIE = 1;
}
