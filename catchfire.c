#ifndef _CATCHFIRE_
#define _CATCHFIRE_
#include "HardwareInfo.c"
#include "CSH.c"
#include <SetTenthS.h>
#include "delayline.c"
#include <SetOneServo.h>

void catchfire()
{
    unsigned int angle3 = 0;
    angle3=5;
    CSH();
    SetTenthS(5);
    delayline(150, 6);
    SetOneServo(_SERVOCTRL_ST_, 3, angle3, 500);
    SetTenthS(10);
}
#endif

