#ifndef _TURNLEFT_
#define _TURNLEFT_
#include "HardwareInfo.c"
#include "TurnFun.c"

void TurnLeft()
{
    TurnFun(-50, 100, 3, 20, 0);
}
#endif

