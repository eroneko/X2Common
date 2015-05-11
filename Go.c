#ifndef _GO_
#define _GO_
#include "HardwareInfo.c"
#include "SetMotorCode.c"
#include <SetMotor_Code.h>
#include <GetMotorCode.h>

void Go(int code, int speed)
{
    int m1 = 0;
    int m2 = 0;
    int s2 = 0;
    int m1c = 0;
    int m2c = 0;
    double N = 1;   //速度调整系数，马达差值越大，可适当减少这个数值
    unsigned int ts = 0;
    SetMotorCode(_M1_);
    SetMotorCode(_M2_);
    if ( speed>=0 )
    {
        SetMotor_Code(1, 0, speed);
        SetMotor_Code(2, 0, speed);
    }
    else
    {
        ts=-speed;
        SetMotor_Code(1, 2, speed);
        SetMotor_Code(2, 2, speed);
    }
    while (1)
    {
        m1 = GetMotorCode(1);
        m2 = GetMotorCode(2);
        m1c=abs(m1);m2c=abs(m2);
        if ( m1c>=m2c )
        {
            if ( speed>0 )
            {
                s2=speed+(m1c-m2c)/N;
            }
            else
            {
                s2=speed-(m1c-m2c)/N;
            }
        }
        else
        {
            if ( speed>0 )
            {
                s2=speed-(m2c-m1c)/N;
            }
            else
            {
                s2=speed+(m2c-m1c)/N;
            }
        }
        if(s2>100) s2=100;if(s2<-100) s2=-100;
        if ( s2>=0 )
        {
            SetMotor_Code(2, 0, s2);
        }
        else
        {
            ts=-s2;
            SetMotor_Code(2, 0, ts);
        }
        if ( m1c>=code )
        {
            break;
        }
    }
    SetMotor_Code(1, 1, 0);
    SetMotor_Code(2, 1, 0);
}
#endif

