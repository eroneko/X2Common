#ifndef _CSH_
#define _CSH_
#include "HardwareInfo.c"
#include <SetOneServo.h>
#include <SetCentiS.h>

void CSH()
{
    unsigned int angle1 = 15;
    unsigned int angle2 = 130;
    unsigned int angle3 = 28;
    unsigned int angle6 = 127;
    unsigned int angle5 = 155;
    unsigned int speed = 700;
    SetOneServo(_SERVOCTRL_ST_, 1, angle1, speed);
    SetOneServo(_SERVOCTRL_ST_, 5, angle5, speed);
    SetOneServo(_SERVOCTRL_ST_, 6, angle6, speed);
    SetOneServo(_SERVOCTRL_ST_, 2, angle2, speed);
    SetOneServo(_SERVOCTRL_ST_, 3, angle3, speed);
    SetCentiS(100);
}
#endif

