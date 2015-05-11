#ifndef _DS_
#define _DS_
#include "HardwareInfo.c"
#include "setdown.c"
#include <SetMotorCode0.h>
#include <SetMotor_Code.h>
#include <GetMotorCode.h>
#include <GetColorSensor.h>
#include "getup.c"
#include <SetTenthS.h>

void ds(unsigned int speed, double toAngle, double dcode)
{
    unsigned int s1 = 0;
    unsigned int s2 = 0;
    double code = 0;
    unsigned int b4 = 0;
    unsigned int flag = 0;
    //Enter you Hint
    setdown();
    SetMotorCode0(2);
    SetMotor_Code(1, 0, speed);
    SetMotor_Code(2, 2, speed);
    while (1)
    {
        code = GetMotorCode(2);
        if ( (code/dcode)>=toAngle )
        {
            break;
        }
        if ( (code/dcode)<=-toAngle )
        {
            flag=1;
            break;
        }
        b4 = GetColorSensor(_COLOR_1_, 1, 4);
        if ( b4==3 )
        {
            getup();
            SetMotor_Code(1, 0, speed);
            SetMotor_Code(2, 2, speed);
        }
    }
    SetMotor_Code(1, 1, speed);
    SetMotor_Code(2, 1, speed);
    SetTenthS(2);
    SetMotor_Code(1, 2, speed);
    SetMotor_Code(2, 0, speed);
    while (1)
    {
        code = GetMotorCode(2);
        if ( ((code/dcode)<=-toAngle&&flag==0)||((code/dcode)>=toAngle&&flag==1) )
        {
            break;
        }
        b4 = GetColorSensor(_COLOR_1_, 1, 4);
        if ( b4==3 )
        {
            getup();
            SetMotor_Code(1, 2, speed);
            SetMotor_Code(2, 0, speed);
        }
    }
    SetMotor_Code(1, 0, speed);
    SetMotor_Code(2, 2, speed);
    while (1)
    {
        code = GetMotorCode(2);
        if ( ((code/dcode)>=0&&flag==0)||((code/dcode)<=0&&flag==1) )
        {
            break;
        }
        b4 = GetColorSensor(_COLOR_1_, 1, 4);
        if ( b4==3 )
        {
            getup();
            SetMotor_Code(1, 0, speed);
            SetMotor_Code(2, 2, speed);
        }
    }
    SetMotor_Code(1, 1, speed);
    SetMotor_Code(2, 1, speed);
}
#endif

