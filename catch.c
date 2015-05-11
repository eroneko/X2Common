#ifndef _CATCH_
#define _CATCH_
#include "HardwareInfo.c"
#include <SetOneServo.h>
#include <SetTenthS.h>

void catch()
{
    unsigned int angle1 = 0;
    unsigned int angle5 = 0;
    SetOneServo(_SERVOCTRL_ST_, 3, 160, 0);
    SetTenthS(5);
    SetOneServo(_SERVOCTRL_ST_, 2, 100, 0);
    SetOneServo(_SERVOCTRL_ST_, 1, 50, 0);
    SetTenthS(7);
    SetOneServo(_SERVOCTRL_ST_, 2, 60, 300);
    SetTenthS(1);
    SetOneServo(_SERVOCTRL_ST_, 1, 90, 200);
    SetTenthS(1);
    SetOneServo(_SERVOCTRL_ST_, 3, 0, 0);
}
#endif

