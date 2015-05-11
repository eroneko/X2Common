#ifndef _CLEARGOOD_
#define _CLEARGOOD_
#include "HardwareInfo.c"
#include <SetOneServo.h>
#include <SetTenthS.h>
#include "delayline.c"
#include "TurnForCode.c"
#include "delay.c"
#include "delayline1.c"

void cleargood()
{
    SetOneServo(_SERVOCTRL_ST_, 2, 70, 500);
    SetTenthS(5);
    delayline(200, 7);
    SetTenthS(5);
    TurnForCode(7, 90, 2.2);
    SetTenthS(5);
    delay(150, 7);
    SetTenthS(5);
    delayline1(200, 7);
}
#endif

