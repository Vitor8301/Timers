#include <xc.h>

void initLEDs( void )
{
    RCSTAbits.SPEN = 0;
    PORTCbits.RC7 = 0;
    TRISCbits.TRISC7 = 0;
}

void led1( unsigned char b )
{
    PORTCbits.RC7 = b;
}
char statusled1( void )
{
    return( PORTCbits.RC7 );
}
