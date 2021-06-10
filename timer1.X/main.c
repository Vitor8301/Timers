/*
 * File:   main.c
 * Author: sn1011701
 *
 * Created on 3 de Junho de 2019, 16:39
 */

#include <xc.h>
#include "config.h"
#include "delay.h"
#include "lcd.h"
#include "leds.h"
#include "timer1.h"

void main(void) 
{
    dispLCD_init();
    initLEDs();
    initTimer1();
    statusled1();
    
    setT1( 1000 );
    setT1limite( 1000 );
    
    dispLCD(0,0,"Contador:       ");
    
    while( 1 )
    {
        dispLCD_num(0,10,contador, 5 );
        
//        if( statusT1() >= ( statusT1limite()/2 ) )
//            led1( 1 );
//        else
//            led1( 0 );
    }
}
