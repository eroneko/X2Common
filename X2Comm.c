#include "HardwareInfo.c"
#include "JMLib.c"
#include <SetMotorPower.h>
#include "JMSub2.c"
#include <SetMotor_Code.h>
#include <SetNS.h>


int   BitTest(unsigned   char   ch,   int   bit)   
  {   
  return   ch   &   (0x01   <<   bit)   ?   1   :   0;   
  }   

unsigned char A1 = 0;
unsigned char A2 = 0;
unsigned char A3 = 0;
unsigned char A4= 0;
unsigned char A5 = 0;
unsigned char A6 = 0;
unsigned char A7 = 0;

unsigned char park = 0;
unsigned char g_flag = 0;
unsigned long T7 = 99999;
unsigned long T1 = 0;
unsigned long T6 = 0;
unsigned long T2 = 99999;
unsigned char g_lr=0;


int DD;//出厂设置变量
unsigned char g_Big = 30;   //无须更改
unsigned char state = 0;   //无须更改



unsigned char A11 = 0;
unsigned char A22 = 0;
unsigned char A33 = 0;
unsigned char A44= 0;
unsigned char A55 = 0;
unsigned char A66= 0;
unsigned char A77 = 0;



// define global var
unsigned char g_Small = 15;
unsigned int Trace = 0;
unsigned char g_TurnSpeed = 60;
unsigned char PLTime = 5;
unsigned char g_Speed = 90;
unsigned int g_TimeOverTime = 10;
unsigned int now = 0;
unsigned int pre = 0;
double dcode = 0;

int main(void)
{
    X2RCU_Init();
    int b4 = 0;
    int b2 = 0;
    unsigned int var0 = 0;
    int var1 = 0;
    int T = 0;
    SetMotorPower(100, 100, 100, 100);
    JMSub2();
    SetMotor_Code(1, 0, 60);
    SetMotor_Code(2, 0, 60);
    SetNS(1);
    SetMotor_Code(1, 0, 60);
    SetMotor_Code(2, 2, 60);
    SetNS(1);
    SetMotor_Code(1, 2, 60);
    SetMotor_Code(2, 0, 60);
    SetNS(1);
    SetMotor_Code(1, 1, 0);
    SetMotor_Code(2, 1, 0);
    while(1);
}

