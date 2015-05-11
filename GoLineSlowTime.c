#ifndef _GOLINESLOWTIME_
#define _GOLINESLOWTIME_
#include "HardwareInfo.c"
#include <GetSysTimeMs.h>
#include "getAd.c"
#include "LineSlow.c"
#include <SetBuzzer.h>
#include <SetMotor_Code.h>

extern unsigned char A1 ;
extern unsigned char A2 ;
extern unsigned char A3 ;
extern unsigned char A4;
extern unsigned char A5 ;
extern unsigned char A6 ;
extern unsigned char A7 ;
extern unsigned char park ;
extern unsigned char PLTime;

void GoLineSlowTime(unsigned int Time)
{
    // extern global var
    extern unsigned char g_Speed;

    unsigned long T1 = 0;
    unsigned char maxIndex = 0;
    unsigned int Speed2 = 0;
    unsigned int n = 1;
    Speed2=g_Speed-10;Time=Time*10;
    
    T1 = GetSysTimeMs();
    while ( GetSysTimeMs()-T1<Time )
    {
        getAd();
        LineSlow(g_Speed, Speed2, 50, 40);
    }
    SetBuzzer(_TRACE_1_, 1);
    SetMotor_Code(1, 1, 100);
    SetMotor_Code(2, 1, 100);
}
#endif

