#ifndef _THROWFIRE_
#define _THROWFIRE_
#include "HardwareInfo.c"
#include <SetOneServo.h>
#include <SetNS.h>
#include "delayline.c"
#include <SetTenthS.h>
#include "gotocode.c"

void throwfire()
{
    unsigned int angle3 = 0;
    unsigned int angle2 = 0;
    SetOneServo(_SERVOCTRL_ST_, 2, angle2, 500);
    SetNS(1);
    delayline(180, 6);
    SetTenthS(5);
    gotocode(6, -6);
    SetOneServo(_SERVOCTRL_ST_, 3, angle3, 40);
    SetTenthS(10);
}
#endif

