#ifndef _SETSERVO_ONECH_
#define _SETSERVO_ONECH_
#include "HardwareInfo.c"
#include <SetOneServo.h>

void SetServo_OneCH(int Channel, unsigned int angle, unsigned int time)
{
    unsigned int realChannel = 0;
    if(Channel==1)
    realChannel=1;
    if(Channel==2)
    realChannel=5;
    if(Channel==3)
    realChannel=2;
    if(Channel==4)
    realChannel=6;
    if(Channel==5)
    realChannel=3;
    if(Channel==6)
    realChannel=7;
    if(Channel==7)
    realChannel=4;
    if(Channel==8)
    realChannel=8;
    SetOneServo(_SERVOCTRL_1_, realChannel, angle, time);
}
#endif

