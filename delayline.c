#ifndef _DELAYLINE_
#define _DELAYLINE_
#include "HardwareInfo.c"
#include <GetSysTimeMs.h>
#include "getAd.c"
#include <SetBuzzer.h>
#include <SetMotor_Code.h>
#include "lineslow1.c"

void delayline(unsigned int Time, unsigned int k)
{
    // extern global var
    extern unsigned char g_Speed;

    unsigned long T1 = 0;
    unsigned char maxIndex = 0;
    unsigned int Speed2 = 0;
    Speed2=g_Speed-10;Time=Time*10;
    
    T1 = GetSysTimeMs();
    while ( GetSysTimeMs()-T1<Time )
    {
        getAd();
        lineslow1(8*k,7*k,5*k,4*k);
    }
    SetBuzzer(_TRACE_1_, 1);
    SetMotor_Code(1, 1, 100);
    SetMotor_Code(2, 1, 100);
}
#endif

