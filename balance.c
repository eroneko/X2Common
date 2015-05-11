#ifndef _BALANCE_
#define _BALANCE_
#include <SetOneServo.h>
#include <SetTenthS.h>
#include <SetThousandthS.h>
#include "HardwareInfo.c"

#include <SetTenthS.h>
#include "delay.c"
#include <SetNS.h>
#include <SetServo.h>
#include <SetTenthS.h>

void balance()
{
    unsigned int angle6 = 0;
    angle6=30;																				;
    
    SetOneServo(_SERVOCTRL_ST_, 6, angle6, 40);
    SetTenthS(5);
    delay(-10, 10);
    SetTenthS(5);
}
#endif

