#ifndef _SLBZ_
#define _SLBZ_
#include "HardwareInfo.c"
#include <SetOneServo.h>
#include <SetMotor.h>
#include <SetMotor_Code.h>
#include <SetTenthS.h>
#include <SetMotorCode0.h>
#include <GetSysTime.h>
#include <GetMotorCode.h>
#include <SetCentiS.h>
#include <GetColorSensor.h>

void SLBZ(int count, int Speed, int sCode)
{
    unsigned int b2 = 0;
    unsigned int color = 0;
    unsigned int i = 0;
    int temp = 0;
    int code2 = 0;
    int ACode = 0;
    int code1 = 0;
    int speed1 = 0;
    unsigned int k = 3;   //¾ÀÕýÏµÊý
    SetOneServo(_SERVOCTRL_ST_, 4, 110, 90);
    SetOneServo(_SERVOCTRL_ST_, 3, 71, 90);
    for (int _FOR_0_ = 0; _FOR_0_ < count; _FOR_0_++ )
    {
        SetMotor(_MOTOR_left_, 0, 40);
        SetMotor_Code(1, 1, 0);
        SetMotor_Code(2, 1, 0);
        SetTenthS(7);
        SetMotor(_MOTOR_left_, 0, 15);
        i=0;
        SetMotorCode0(1);
        SetMotorCode0(2);
        while (1)
        {
            b2 = GetSysTime();
            code2 = GetMotorCode(2);
            if ( (b2/40)%2==0 )
            {
                SetOneServo(_SERVOCTRL_ST_, 4, 108, 300);
            }
            else
            {
                SetOneServo(_SERVOCTRL_ST_, 4, 111, 300);
            }
            if ( code2>=sCode||code2<=-sCode )
            {
                i++;
                if ( i>2 )
                {
                    break;
                }
                SetMotor_Code(1, 2, 100);
                SetMotor_Code(2, 2, 100);
                SetCentiS(10);
                SetMotor_Code(1, 1, 100);
                SetMotor_Code(2, 1, 100);
                SetCentiS(3);
                SetMotorCode0(1);
                SetMotorCode0(2);
            }
            else
            {
                SetMotor_Code(1, 0, Speed);
                SetMotor_Code(2, 0, Speed);
            }
            color = GetColorSensor(_COLOR_1_, 1, 4);
            if ( color==6 )
            {
                SetMotor_Code(1, 1, 35);
                SetMotor_Code(2, 1, 35);
                SetCentiS(50);
                SetMotor(_MOTOR_left_, 2, 100);
                SetTenthS(3);
                SetMotor(_MOTOR_left_, 0, 100);
                SetTenthS(2);
                SetMotor(_MOTOR_left_, 0, 40);
                SetTenthS(3);
                SetMotor(_MOTOR_left_, 0, 15);
            }
        }
        if ( _FOR_0_<count-1 )
        {
            SetMotor_Code(1, 1, 0);
            SetMotor_Code(2, 1, 0);
            SetOneServo(_SERVOCTRL_ST_, 4, 112, 130);
            SetTenthS(6);
            SetMotorCode0(1);
            SetMotorCode0(2);
            SetMotor_Code(1, 2, Speed);
            SetMotor_Code(2, 2, Speed);
            while (1)
            {
                code2 = GetMotorCode(2);
                if ( code2>=sCode*count+ACode||code2<=-sCode*count-ACode )
                {
                    break;
                }
            }
            SetMotor_Code(1, 1, 0);
            SetMotor_Code(2, 1, 0);
            SetOneServo(_SERVOCTRL_ST_, 4, 104, 300);
        }
        else
        {
            SetMotor_Code(1, 1, 0);
            SetMotor_Code(2, 1, 0);
            SetMotor(_MOTOR_left_, 0, 40);
            SetOneServo(_SERVOCTRL_ST_, 3, 100, 130);
            SetOneServo(_SERVOCTRL_ST_, 4, 50, 130);
            SetTenthS(6);
            SetMotorCode0(1);
            SetMotorCode0(2);
            SetMotor_Code(1, 2, Speed);
            SetMotor_Code(2, 2, Speed);
            while (1)
            {
                code2 = GetMotorCode(2);
                if ( code2>=sCode*count||code2<=-sCode*count )
                {
                    break;
                }
            }
            SetMotor_Code(1, 1, 0);
            SetMotor_Code(2, 1, 0);
        }
    }
}
#endif

