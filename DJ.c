#ifndef _DJ_
#define _DJ_
#include "HardwareInfo.c"
#include "CSH.c"
#include "delayline.c"
extern unsigned int 	ADJ3;
extern unsigned int 	PADJ5;
extern unsigned int 	NADJ5;

void DJ()
{
    unsigned int angle3 = 0;
    unsigned int pangle5 = 0;
    unsigned int nangle5 = 0;
    CSH();
    delayline(180, 7);
}
#endif

