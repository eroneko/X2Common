#ifndef _GOLINEIR_
#define _GOLINEIR_
#include "HardwareInfo.c"
#include "getAd.c"
#include <GetIRDete.h>
#include "LineSlow.c"
#include <SetTraceV2BeepI2C.h>
#include "delayline.c"
#include <SetMotor_Code.h>
#include "slowLineLR.c"
extern unsigned char A1 ;
extern unsigned char A2 ;
extern unsigned char A3 ;
extern unsigned char A4;
extern unsigned char A5 ;
extern unsigned char A6 ;
extern unsigned char A7 ;
extern unsigned char park ;
extern unsigned char PLTime;
extern unsigned char g_lr;

extern unsigned long T1 ;
extern unsigned long T2 ;
extern unsigned long T6 ;
extern unsigned long T7 ;

void GOlineIR(unsigned char IR, unsigned char Count, double k)
{
    // extern global var
    extern unsigned char PLTime;
    extern unsigned char g_Speed;
    extern unsigned int g_TimeOverTime;
    extern unsigned int Trace;

    unsigned char falg = 0;
    unsigned char i = 0;
    unsigned char Speed2 = 0;
    unsigned int TimeOver = 0;
    unsigned int n = 1;
    unsigned int var0 = 0;
    Speed2=g_Speed-10;
    while (1)
    {
        getAd();
        if ( IR==1 )
        {
            var0 = GetIRDete(_IRDETECT_1_);
        }
        else
        {
            if ( IR==2 )
            {
                var0 = GetIRDete(_IRDETECT_2_);
            }
            else
            {
                var0 = GetIRDete(_IRDETECT_3_);
            }
        }
        if ( var0==0 )
        {
            break;
        }
        LineSlow(g_Speed, Speed2, 40, 30);
    }
    T7 = 999999;T2 =999999;;
    while (1)
    {
        if(Count==0) break;
        getAd();
        if ( IR==1 )
        {
            var0 = GetIRDete(_IRDETECT_1_);
        }
        else
        {
            if ( IR==2 )
            {
                var0 = GetIRDete(_IRDETECT_2_);
            }
            else
            {
                var0 = GetIRDete(_IRDETECT_3_);
            }
        }
        if ( var0==1 )
        {
            Count--;
            if(Count==0) falg=1;
        }
        if ( falg )
        {
            SetTraceV2BeepI2C(_TRACEV2_1_, 1);
            if ( i>=Count-1 )
            {
                break;
            }
        }
        if ( n==1 )
        {
            delayline(10, 7);
            n=0;
        }
        slowLineLR(8*k,7*k,5*k,4*k,0);
    }
    SetMotor_Code(1, 1, 70);
    SetMotor_Code(2, 1, 70);
}
#endif

