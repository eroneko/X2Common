#ifndef _DELAYLINEGO_
#define _DELAYLINEGO_
#include "HardwareInfo.c"
#include "getAd.c"
#include "LineSlow.c"
#include <SetTraceV2BeepI2C.h>
#include "delayline.c"
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
extern unsigned char g_lr;

extern unsigned long T1 ;
extern unsigned long T2 ;
extern unsigned long T6 ;
extern unsigned long T7 ;

void delayLineGo(unsigned char Sensor, unsigned char Count, double k)
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
    Speed2=g_Speed-10;
    while (1)
    {
        getAd();
        if ( A1==0&&A7==0 )
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
        if ( Sensor==1 )
        {
            if ( A1==1 )
            {
                falg=1;
            }
        }
        else
        {
            if ( Sensor==7 )
            {
                if ( A7==1 )
                {
                    falg=1;
                }
            }
            else
            {
                if ( abs(T1-T7)<PLTime )
                {
                    falg=1;
                }
                else
                {
                    if ( Sensor==26&&A2==1&&A6==1 )
                    {
                        falg=1;
                    }
                }
            }
        }
        if ( falg )
        {
            SetTraceV2BeepI2C(_TRACEV2_1_, 1);
            if ( i>=Count-1 )
            {
                break;
            }
            if ( (A1==0&&A7==0&&Sensor!=1&&Sensor!=7)||(Sensor==1&&A1==0)||(Sensor==7&&A7==0) )
            {
                TimeOver++;
                if ( TimeOver>g_TimeOverTime )
                {
                    TimeOver=0;
                    i++;T7=999999;T1=0;falg=0;T6=0;T2=999999;
                }
            }
        }
        if ( n==1 )
        {
            delayline(10, 7);
            n=0;
        }
        lineslow1(8*k,7*k,5*k,4*k);
    }
    SetMotor_Code(1, 1, 70);
    SetMotor_Code(2, 1, 70);
}
#endif

