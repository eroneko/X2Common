#ifndef _TURNRIGHT_
#define _TURNRIGHT_
#include "HardwareInfo.c"
#include "TurnFun.c"

void TurnRight()
{
    TurnFun(90, -40, 5, 20, 0);
}
#endif

