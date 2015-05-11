#ifndef _THROW_
#define _THROW_
#include "HardwareInfo.c"
#include <SetTenthS.h>
#include "open.c"
#include "GoLineSlowTime.c"
#include <SetMotor_Code.h>
#include <SetCentiS.h>

extern unsigned int AT1;
extern unsigned int AT2;

void throw()
{
    unsigned int angle1 = 0;
    unsigned int angle2 = 0;
    unsigned int sp = 80;
    SetTenthS(5);
    open();
    GoLineSlowTime(sp);
    SetMotor_Code(1, 1, 100);
    SetMotor_Code(2, 1, 100);
    SetCentiS(30);
}
#endif

