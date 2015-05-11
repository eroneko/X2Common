#ifndef _JMSUB2_
#define _JMSUB2_
#include "HardwareInfo.c"
#include <SetMotor.h>
#include <SetTouchToScreenCoordinate.h>
#include <SetLCDSolidCircle.h>
#include <SetLCDString.h>
#include <GetTouchScreenX.h>
#include <GetTouchScreenY.h>
#include <SetLCDBack.h>
#include <GetButton1.h>
#include <SetTenthS.h>
#include <SetLCDClear.h>
#include <GetButton2.h>
#include <GetButton3.h>
#include <SetCentiS.h>
#include <GetSysTime.h>
#include <SetInBeep.h>
#include <GetData.h>
#include <SetData.h>
#include "JMSub1.c"

//int a[8]={2,1,3,6,7,5,8,4};
int a[8]={2,1,7,4,6,8,5,3};

int x,y;

void JMSub2()
{
    unsigned int SC = 0;
    unsigned int B1 = 0;
    unsigned int B2 = 0;
    unsigned long T1 = 0;
    unsigned long T2 = 0;
    unsigned int B3 = 0;
    unsigned int touchT = 0;
    SetMotor(_MOTOR_left_, 2, 30);
    while ( GetTouchScreenX()>0||GetTouchScreenY()>0||GetButton3() )
    {
    }
    if(!GetData(30)&&!GetData(31)&&!GetData(32)&&!GetData(33)&&!GetData(34)&&!GetData(35)&&!GetData(36)&&!GetData(37))
    {SetData(30,55);SetData(31,45);SetData(32,0);SetData(33,104);SetData(34,164);SetData(35,30);SetData(36,113);SetData(37,69);}
    
    int S[8]={GetData(30),GetData(31),GetData(32),GetData(33),GetData(34),GetData(35),GetData(36),GetData(37)};
    
    
    int PointJiaJian[2][4]={
                            {120,125,165,160},
                            {170,125,215,160},
                          };
    
    
    
    
    SetOneServo(_SERVOCTRL_ST_, a[0], S[0], 400);
    SetOneServo(_SERVOCTRL_ST_, a[2], S[2], 400);
    SetOneServo(_SERVOCTRL_ST_, a[3], S[3], 400);
    
    SetOneServo(_SERVOCTRL_ST_, a[6], S[6], 800);
    SetTenthS(3);
    SetOneServo(_SERVOCTRL_ST_, a[1], S[1], 800);
    
    
    SetOneServo(_SERVOCTRL_ST_, a[4], S[4], 800);
    SetOneServo(_SERVOCTRL_ST_, a[5], S[5], 800);
    
    SetOneServo(_SERVOCTRL_ST_, a[7], S[7], 800);
    
    SetTouchToScreenCoordinate();
    SetLCDSolidCircle(120, 85, 40, 2016);
    SetLCDString(113, 77, "GO", 65535, BLACK);
    SetLCDSolidCircle(185, 35, 30, 63519);
    SetLCDString(172, 24, "TEST", 65535, BLACK);
    while (1)
    {
        x = GetTouchScreenX();
        y = GetTouchScreenY();
        if ( x>80&&x<160&&y>60||GetButton3() )
        {
            touchT=1;
            SetLCDBack(0);
            break;
        }
        else
        {
            if ( x>160&&y<55 )
            {
                touchT=2;
                break;
            }
        }
        B1 = GetButton1();
    }
    if ( touchT==2 )
    {
        while ( GetTouchScreenX()>0||GetTouchScreenY()>0 )
        {
        }
        SetTenthS(5);
        SetLCDClear(BLACK);
        SetLCDString(PointJiaJian[0][0]+12, PointJiaJian[0][1]+10,"-" , CYAN, BLACK);
        SetLCDString(PointJiaJian[1][0]+12, PointJiaJian[1][1]+10,"+" , CYAN, BLACK);
        
        
        while (1)
        {
            B1 = GetButton1();
            B2 = GetButton2();
            B3 = GetButton3();
            x = GetTouchScreenX();
            y = GetTouchScreenY();
            SC = JMSub1(S[0], S[1], S[2], S[3], S[4], S[5], S[6], S[7]);
            
            
            if ( x>0&&y>0 )
            {
                if(x>=PointJiaJian[0][0]&&x<=PointJiaJian[0][2]&&y>=PointJiaJian[0][1]&&y<=PointJiaJian[0][3])
                {
                    B1=1;
                }
                
                
                if(x>=PointJiaJian[1][0]&&x<=PointJiaJian[1][2]&&y>=PointJiaJian[1][1]&&y<=PointJiaJian[1][3])
                {
                   B2=1;
                }
                
            }
            if ( B2 )
            {
                S[SC]++;if(S[SC]>180) S[SC]=180;;
                SetCentiS(20);
                B2 = GetButton2();
                x = GetTouchScreenX();
                y = GetTouchScreenY();
                
                if(x>=PointJiaJian[1][0]&&x<=PointJiaJian[1][2]&&y>=PointJiaJian[1][1]&&y<=PointJiaJian[1][3])
                {
                   B2=1;
                }
                
                while ( B2 )
                {
                    B2 = GetButton2();
                    x = GetTouchScreenX();
                    y = GetTouchScreenY();
                    
                    if(x>=PointJiaJian[1][0]&&x<=PointJiaJian[1][2]&&y>=PointJiaJian[1][1]&&y<=PointJiaJian[1][3])
                    {
                       B2=1;
                    }
                    
                    SC = JMSub1(S[0], S[1], S[2], S[3], S[4], S[5], S[6], S[7]);;
                    S[SC]+=1 ;if(S[SC]>180) S[SC]=180;;
                }
                T1 = GetSysTime();
            }
            else
            {
                T1=0;;
            }
            if ( B1 )
            {
                S[SC]-- ;if(S[SC]<0) S[SC]=0;;
                SetCentiS(20);
                B1 = GetButton1();
                x = GetTouchScreenX();
                y = GetTouchScreenY();
                if(x>=PointJiaJian[0][0]&&x<=PointJiaJian[0][2]&&y>=PointJiaJian[0][1]&&y<=PointJiaJian[0][3])
                {
                    B1=1;
                }
                
                while ( B1 )
                {
                    B1 = GetButton1();
                    x = GetTouchScreenX();
                    y = GetTouchScreenY();
                    if(x>=PointJiaJian[0][0]&&x<=PointJiaJian[0][2]&&y>=PointJiaJian[0][1]&&y<=PointJiaJian[0][3])
                    {
                        B1=1;
                    }
                    
                    SC = JMSub1(S[0], S[1], S[2], S[3], S[4], S[5], S[6], S[7]);;
                    S[SC]-=1 ;if(S[SC]<0) S[SC]=0;;
                }
                T1 = GetSysTime();
            }
            else
            {
                T1=0;;
            }
            if ( B3 )
            {
                SetLCDBack(0);
                SetData(30,S[0]);
                
                SetData(31,S[1]);
                
                SetData(32,S[2]);
                
                SetData(33,S[3]);
                
                SetData(34,S[4]);
                
                SetData(35,S[5]);
                
                SetData(36,S[6]);
                
                SetData(37,S[7]);
                SetCentiS(90);
                SetInBeep(1);
                SetCentiS(10);
                SetInBeep(0);
                SetLCDBack(1);
            }
        }
    }
    SetLCDBack(0);
    SetMotor(_MOTOR_left_, 1, 0);
}
#endif

