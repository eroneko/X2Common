#ifndef _SETDOWN_
#define _SETDOWN_
#include "HardwareInfo.c"
#include <SetMotor_Code.h>
#include <SetOneServo.h>
#include <SetTenthS.h>

void setdown()
{
    SetMotor_Code(1, 1, 35);
    SetMotor_Code(2, 1, 35);
    SetOneServo(_SERVOCTRL_ST_, 2, 142, 0);
    SetOneServo(_SERVOCTRL_ST_, 1, 35, 0);
    SetOneServo(_SERVOCTRL_ST_, 3, 180, 0);
    SetOneServo(_SERVOCTRL_ST_, 6, 110, 0);
    SetOneServo(_SERVOCTRL_ST_, 8, 24, 0);
    SetTenthS(10);
}
#endif

