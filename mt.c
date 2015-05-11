#ifndef _MT_
#define _MT_
#include "HardwareInfo.c"

void mt(int Left, int Right)
{
    extern unsigned int G_M1SPEED;
    
    extern unsigned int G_M2SPEED;
    
    G_M1SPEED=Left;
    G_M2SPEED=Right;
}
#endif

