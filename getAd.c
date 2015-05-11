#ifndef _GETAD_
#define _GETAD_
#include "HardwareInfo.c"
#include <GetTraceV2I2C.h>
#include <GetSysTime.h>

int   BitTest(unsigned   char   ch,   int   bit) ;

void getAd()
{
    // extern global var
    extern unsigned char g_Small;
    extern unsigned int Trace;

    unsigned int var0 = 0;
    unsigned int var1 = 0;
    unsigned int var2 = 0;
    unsigned int var3 = 0;
    unsigned int var4 = 0;
    unsigned int var5 = 0;
    unsigned int var6 = 0;
    extern unsigned char state;
    static unsigned int var7;
    Trace = GetTraceV2I2C(_TRACEV2_1_, 9);
    extern unsigned char A1 ;
    extern unsigned char A2 ;
    extern unsigned char A3 ;
    extern unsigned char A4;
    extern unsigned char A5 ;
    extern unsigned char A6 ;
    extern unsigned char A7 ;
    extern unsigned char park ;
    
    extern unsigned long T1 ;
    extern unsigned long T2 ;
    extern unsigned long T6 ;
    extern unsigned long T7 ;
    static a=0;
    
    A1=0;A2=0;A3=0;A4=0;A5=0;A6=0;A7=0;
        if ( Trace!=var7)
        {
        if(Trace==255) return;
    a++;
    
    var7=Trace;
            return;
        }
    
    A1=BitTest(Trace,0);
    A2=BitTest(Trace,1);
    A3=BitTest(Trace,2);
    A4=BitTest(Trace,3);
    A5=BitTest(Trace,4);
    A6=BitTest(Trace,5);
    A7=BitTest(Trace,6);
    if(A1==1)
    T1=GetSysTime();
    if(A2==1)
    T2=GetSysTime();
    if(A6==1)
    T6=GetSysTime();
    if(A7==1)
    T7=GetSysTime();
    /*
    A2=0;A3=0;
    if(var0<900)
    A1=1;
    else
    A1=0;
    
    if(var1<900)
    A2=1;
    else
    A2=0;
    
    if(var2<900)
    A3=1;
    else
    A3=0;
    
    if(var3<900)
    A4=1;
    else
    A4=0;
    
    if(var4<900)
    A5=1;
    else
    A5=0;
    
    if(var5<900)
    A6=1;
    else
    A6=0;
    
    if(var6<900)
    A7=1;
    else
    A7=0;
    */
}
#endif

