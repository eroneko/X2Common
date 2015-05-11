#ifndef _DELAY_
#define _DELAY_
#include "HardwareInfo.c"
#include <SetMotor_Code.h>
#include <SetCentiS.h>

void delay(long time, unsigned int k)
{
    unsigned int speed = 40;
    if ( time>=0 )
    {
        speed=7*k;
        SetMotor_Code(1, 0, speed);
        SetMotor_Code(2, 0, speed);
        SetCentiS(time);
        SetMotor_Code(1, 1, 100);
        SetMotor_Code(2, 1, 100);
    }
    else
    {
        time=-time;speed=7*k;
        SetMotor_Code(1, 2, speed);
        SetMotor_Code(2, 2, speed);
        SetCentiS(time);
        SetMotor_Code(1, 1, 100);
        SetMotor_Code(2, 1, 100);
    }
}
#endif

