#ifndef _TURNFUNH_
#define _TURNFUNH_
#include "HardwareInfo.c"
#include <SetMotor_Code.h>
#include <SetCentiS.h>
#include "getAd1.c"
#include <GetSysTimeMs.h>

void TurnFunH(int Left, int Right, unsigned char sensor, unsigned char PreTime, unsigned char breakTime)
{
    unsigned char s1 = 0;
    unsigned char s2 = 0;
    unsigned long T1 = 0;
    unsigned long T2 = 0;
    
    extern unsigned char A1 ;
    extern unsigned char A2 ;
    extern unsigned char A3 ;
    extern unsigned char A4;
    extern unsigned char A5 ;
    extern unsigned char A6 ;
    extern unsigned char A7 ;
    
    
    if ( Left<0 )
    {
        s1=2 ;Left=-Left;;
    }
    if ( Right<0 )
    {
        s2=2;Right=-Right;
    }
    if(Left==0) s1=1;if(Right==0) s2=1;;
    SetMotor_Code(1, s1, Left);
    SetMotor_Code(2, s2, Right);
    SetCentiS(PreTime);
    while (1)
    {
        A1=0;A2=0;A3=0;A4=0;A5=0;A6=0;A7=0;
        getAd1();
        if ( sensor==1 )
        {
            if ( A1 )
            {
                break;
            }
        }
        else
        {
            if ( sensor==2 )
            {
                if ( A2 )
                {
                    break;
                }
            }
            else
            {
                if ( sensor==3 )
                {
                    if ( A3 )
                    {
                        break;
                    }
                }
                else
                {
                    if ( sensor==4 )
                    {
                        if ( A4 )
                        {
                            break;
                        }
                    }
                    else
                    {
                        if ( sensor==5 )
                        {
                            if ( A5 )
                            {
                                break;
                            }
                        }
                        else
                        {
                            if ( sensor==6 )
                            {
                                if ( A6 )
                                {
                                    break;
                                }
                            }
                            else
                            {
                                if ( A7 )
                                {
                                    break;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    T1 = GetSysTimeMs();
    if ( breakTime<0 )
    {
        breakTime=-breakTime;;
        SetCentiS(breakTime);
        SetCentiS(breakTime);
    }
    else
    {
        if(s1==0) s1=2 ;else if(s1==2) s1=0;;
        if(s2==0) s2=2;else if(s2==2) s2=0;;
        SetMotor_Code(1, s1, Left);
        SetMotor_Code(2, s2, Right);
        SetCentiS(breakTime);
    }
    SetMotor_Code(1, 1, Left);
    SetMotor_Code(2, 1, Right);
}
#endif

