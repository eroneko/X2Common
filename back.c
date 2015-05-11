#ifndef _BACK_
#define _BACK_
#include "HardwareInfo.c"
#include "TurnFun.c"
#include <SetTenthS.h>
#include <SetMotor_Code.h>

void back()
{
    TurnFun(70, -70, 7, 0, 0);
    TurnFun(70, -70, 4, 0, 0);
    SetTenthS(5);
    SetMotor_Code(1, 1, 100);
    SetMotor_Code(2, 1, 100);
}
#endif

