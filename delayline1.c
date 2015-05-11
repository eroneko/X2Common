#ifndef _DELAYLINE1_
#define _DELAYLINE1_
#include "HardwareInfo.c"
#include <GetSysTimeMs.h>
#include "getAd1.c"
#include <SetBuzzer.h>
#include <SetMotor_Code.h>
#include "lineslow2.c"

void delayline1(unsigned int Time, unsigned int k)
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
        getAd1();
        lineslow2(10*k,7*k,5*k,4*k);
    }
    SetBuzzer(_TRACE_1_, 1);
    SetMotor_Code(1, 1, 70);
    SetMotor_Code(2, 1, 70);
}
#endif

