#ifndef _TURNFORCODE_
#define _TURNFORCODE_
#include "HardwareInfo.c"
#include <SetMotorCode0.h>
#include <SetMotor_Code.h>
#include <GetMotorCode.h>

void TurnForCode(double k, double toAngle, double dcode)
{
    unsigned int s1 = 0;
    unsigned int s2 = 0;
    double code = 0;
    unsigned int speed = 0;
    if ( toAngle>=0 )
    {
        SetMotorCode0(2);
        speed=10*k;
        SetMotor_Code(1, 0, speed);
        SetMotor_Code(2, 2, speed);
        while (1)
        {
            code = GetMotorCode(2);
            if ( (code/dcode)<=-toAngle||(code/dcode)>=toAngle )
            {
                break;
            }
        }
        SetMotor_Code(1, 1, speed);
        SetMotor_Code(2, 1, speed);
    }
    else
    {
        toAngle=-toAngle;
        SetMotorCode0(2);
        speed=10*k;
        SetMotor_Code(1, 2, speed);
        SetMotor_Code(2, 0, speed);
        while (1)
        {
            code = GetMotorCode(2);
            if ( (code/dcode)<=-toAngle||(code/dcode)>=toAngle )
            {
                break;
            }
        }
        SetMotor_Code(1, 1, speed);
        SetMotor_Code(2, 1, speed);
    }
}
#endif

