#ifndef _AROUND_
#define _AROUND_
#include "HardwareInfo.c"
#include "TurnFun.c"
#include <SetLCDBack.h>
extern unsigned char A1 ;
extern unsigned char A2 ;
extern unsigned char A3 ;
extern unsigned char A4;
extern unsigned char A5 ;
extern unsigned char A6 ;
extern unsigned char A7 ;

void around(int CS)
{
    unsigned int CSS = 0;
    CSS=CS*2;
    while ( CSS-- )
    {
        TurnFun(70, -70, 7, 0, 0);
        SetLCDBack(1);
        TurnFun(70, -70, 4, 0, 0);
        SetLCDBack(0);
    }
}
#endif

