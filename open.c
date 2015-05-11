#ifndef _OPEN_
#define _OPEN_
#include "HardwareInfo.c"
#include <SetOneServo.h>
#include <SetNS.h>

void open()
{
    unsigned int angle1 = 0;
    unsigned int angle5 = 0;
    angle1=115;
    angle5=69;
    SetOneServo(_SERVOCTRL_ST_, 1, angle1, 20);
    SetOneServo(_SERVOCTRL_ST_, 5, angle5, 20);
    SetNS(1);
}
#endif

