#ifndef _GOTOCODE_
#define _GOTOCODE_
#include "HardwareInfo.c"
#include <SetMotorCode0.h>
#include <SetMotor_Code.h>
#include <GetMotorCode.h>

void gotocode(int speed, double distance)
{
    double code = 0;
    double dcode = 15;
    int ts = 0;
    int m1 = 0;
    int m2 = 0;
    int s2 = 0;
    int m1c = 0;
    int m2c = 0;
    unsigned int N = 2;
    unsigned int m12 = 0;
    unsigned long T = 0;
    if ( distance>=0 )
    {
        SetMotorCode0(2);
        SetMotor_Code(1, 0, speed);
        SetMotor_Code(2, 0, speed);
        while (1)
        {
            code = GetMotorCode(2);
            if ( (code/dcode)>=distance||(code/dcode)<=-distance )
            {
                break;
            }
        }
        SetMotor_Code(1, 1, speed);
        SetMotor_Code(2, 1, speed);
    }
    else
    {
        distance=-distance;
        SetMotorCode0(2);
        SetMotor_Code(1, 2, speed);
        SetMotor_Code(2, 2, speed);
        while (1)
        {
            code = GetMotorCode(2);
            if ( (code/dcode)<=-distance||(code/dcode)>=distance )
            {
                break;
            }
        }
        SetMotor_Code(1, 1, speed);
        SetMotor_Code(2, 1, speed);
    }
}
#endif

