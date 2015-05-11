#ifndef _GETBOOK_
#define _GETBOOK_
#include "HardwareInfo.c"
#include <SetOneServo.h>
#include <SetTenthS.h>

void getBook()
{
    SetOneServo(_SERVOCTRL_ST_, 2, 150, 400);
    SetTenthS(10);
    SetOneServo(_SERVOCTRL_ST_, 2, 123, 400);
    SetTenthS(20);
}
#endif

