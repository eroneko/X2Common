#ifndef _JMSUB1_
#define _JMSUB1_
#include "HardwareInfo.c"
#include <SetLCDRectangle.h>
#include <SetLCDString.h>
#include <SetLCD3Char.h>
#include <SetInBeep.h>
#include <SetCentiS.h>
#include <SetAllServo.h>
#include <SetOneServo.h>

static select =8,oldselect=8;

extern int a[8];

extern int x,y;

int JMSub1(int S1, int S2, int S3, int S4, int S5, int S6, int S7, int S8)
{
    
    
    
    int S[8]={S1,S2,S3,S4,S5,S6,S7,S8};
    //int a[8]={3,1,2,6,7,5,8,4};
    int Point[8][4]={
                            {20,60,70,110},
                            {80,60,130,110},
                            {160,60,210,110},
                            {60,5,105,50},
                            {5,5,50,50},
                            {170,5,215,50},
                            {5,120,50,165},
                            {60,120,105,165},
                          };
    
    
    
    //SetLCDRectangle(PointJiaJian[0][0], PointJiaJian[0][1],PointJiaJian[0][2],PointJiaJian[0][3], 1, YELLOW);
    //SetLCDRectangle(PointJiaJian[1][0], PointJiaJian[1][1],PointJiaJian[1][2],PointJiaJian[1][3], 1, YELLOW);
    if ( x>0&&y>0 )
    {
        
        
        if(x>=Point[0][0]&&x<=Point[0][2]&&y>=Point[0][1]&&y<=Point[0][3])
        {
        if(select!=0)
        oldselect=select;
        select=0;
        
            SetInBeep(1);
            SetCentiS(10);
            SetInBeep(0);
        }
        
        if(x>=Point[1][0]&&x<=Point[1][2]&&y>=Point[1][1]&&y<=Point[1][3])
        {
        if(select!=1)
        oldselect=select;
        select=1;
        
            SetInBeep(1);
            SetCentiS(10);
            SetInBeep(0);
        }
        
        if(x>=Point[2][0]&&x<=Point[2][2]&&y>=Point[2][1]&&y<=Point[2][3])
        {
        if(select!=2)
        oldselect=select;
        select=2;
        
            SetInBeep(1);
            SetCentiS(10);
            SetInBeep(0);
        }
        
        if(x>=Point[3][0]&&x<=Point[3][2]&&y>=Point[3][1]&&y<=Point[3][3])
        {
        if(select!=3)
        oldselect=select;
        select=3;
        
            SetInBeep(1);
            SetCentiS(10);
            SetInBeep(0);
        }
        
        if(x>=Point[4][0]&&x<=Point[4][2]&&y>=Point[4][1]&&y<=Point[4][3])
        {
        if(select!=4)
        oldselect=select;
        select=4;
        
            SetInBeep(1);
            SetCentiS(10);
            SetInBeep(0);
        }
        
        if(x>=Point[5][0]&&x<=Point[5][2]&&y>=Point[5][1]&&y<=Point[5][3])
        {
        if(select!=5)
        oldselect=select;
        select=5;
        
            SetInBeep(1);
            SetCentiS(10);
            SetInBeep(0);
        }
        
        if(x>=Point[6][0]&&x<=Point[6][2]&&y>=Point[6][1]&&y<=Point[6][3])
        {
        if(select!=6)
        oldselect=select;
        select=6;
        
            SetInBeep(1);
            SetCentiS(10);
            SetInBeep(0);
        }
        
        if(x>=Point[7][0]&&x<=Point[7][2]&&y>=Point[7][1]&&y<=Point[7][3])
        {
        if(select!=7)
        oldselect=select;
        select=7;
        
            SetInBeep(1);
            SetCentiS(10);
            SetInBeep(0);
        }
        
        
        
        
        
            
    }
    
    long fk=123;   
    
       
       if(select==8)
       {
    
          SetLCD3Char(Point[0][0]+3, Point[0][1]+23, S[0], YELLOW, BLACK);  
    	  SetLCD3Char(Point[1][0]+3, Point[1][1]+23, S[1], YELLOW, BLACK); 
    	   SetLCD3Char(Point[2][0]+3, Point[2][1]+23, S[2], YELLOW, BLACK);
    	   SetLCD3Char(Point[3][0]+3, Point[3][1]+23, S[3], YELLOW, BLACK);
    	   SetLCD3Char(Point[4][0]+3, Point[4][1]+23, S[4], YELLOW, BLACK);
    	   SetLCD3Char(Point[5][0]+3, Point[5][1]+23, S[5], YELLOW, BLACK);
    	   SetLCD3Char(Point[6][0]+3, Point[6][1]+23, S[6], YELLOW, BLACK);
    	     SetLCD3Char(Point[7][0]+3, Point[7][1]+23, S[7], YELLOW, BLACK);
    	     
    	    
    	        SetLCD3Char(Point[0][0]+3, Point[0][1]+3, a[0], RED, BLACK);
    	      SetLCD3Char(Point[1][0]+3, Point[1][1]+3, a[1], RED, BLACK);
    	      SetLCD3Char(Point[2][0]+3, Point[2][1]+3, a[2], RED, BLACK);
    	      SetLCD3Char(Point[3][0]+3, Point[3][1]+3, a[3], RED, BLACK);
    	      SetLCD3Char(Point[4][0]+3, Point[4][1]+3, a[4], RED, BLACK);
    	       SetLCD3Char(Point[5][0]+3, Point[5][1]+3, a[5], RED, BLACK);
    	           SetLCD3Char(Point[6][0]+3, Point[6][1]+3, a[6], RED, BLACK);
    	       SetLCD3Char(Point[7][0]+3, Point[7][1]+3, a[7], RED, BLACK);
    	       
    	      
    	      
    	     SetLCDString(Point[0][0]+16, Point[0][1]+2, "S", RED, BLACK);
    	     SetLCDString(Point[1][0]+16, Point[1][1]+2, "S", RED, BLACK);
    	     SetLCDString(Point[2][0]+16, Point[2][1]+2, "S", RED, BLACK);
    	      SetLCDString(Point[3][0]+16, Point[3][1]+2, "S", RED, BLACK);
    	       SetLCDString(Point[4][0]+16, Point[4][1]+2, "S", RED, BLACK);
    	    SetLCDString(Point[5][0]+16, Point[5][1]+2, "S", RED, BLACK);
    	     SetLCDString(Point[6][0]+16, Point[6][1]+2, "S", RED, BLACK);
    	     SetLCDString(Point[7][0]+16, Point[7][1]+2, "S", RED, BLACK);
    	     
    	         SetLCDRectangle(Point[0][0], Point[0][1], Point[0][2], Point[0][3], 3, fk);
    
     SetLCDRectangle(Point[1][0], Point[1][1], Point[1][2], Point[1][3], 3, fk);
        
    
        SetLCDRectangle(Point[2][0], Point[2][1], Point[2][2], Point[2][3], 3, fk);
        
           
     
        SetLCDRectangle(Point[3][0], Point[3][1], Point[3][2], Point[3][3], 3, fk);
        
    
        SetLCDRectangle(Point[4][0], Point[4][1], Point[4][2], Point[4][3], 3, fk);
        
    
        SetLCDRectangle(Point[5][0], Point[5][1], Point[5][2], Point[5][3], 3, fk);
    
        
        SetLCDRectangle(Point[6][0], Point[6][1], Point[6][2], Point[6][3], 3, fk);
    
    
        SetLCDRectangle(Point[7][0], Point[7][1], Point[7][2], Point[7][3], 3, fk);
    
    	     select=0;
    	     oldselect=1;
       }
       
    
    
    SetLCDRectangle(Point[select][0], Point[select][1], Point[select][2], Point[select][3], 3, GREEN);
    SetLCDRectangle(Point[oldselect][0], Point[oldselect][1], Point[oldselect][2], Point[oldselect][3], 3, fk);
    SetLCD3Char(Point[select][0]+3, Point[select][1]+23, S[select], YELLOW, BLACK);
    
    SetOneServo(_SERVOCTRL_ST_, a[select], S[select], 0);
        
        
    return select;
}
#endif

