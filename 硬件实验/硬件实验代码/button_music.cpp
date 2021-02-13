/********************************************************************************************* 

Do 262 3.8ms
Re 294 3.4ms
Mi 330 3.0ms
Fa 349 2.8ms
So 392 2.6ms
La 440 2.2ms
Si 494 2.0ms

**********************************************************************************************/
/********************************************************************************************* 
* File:  button_test.c 
* Author: embest 
* Descript: Button_Test  
* History:  
* EINT0 --- KEY1   EINT1 --- KEY2 
*********************************************************************************************/ 
 
/*------------------------------------------------------------------------------------------*/ 
/*            include files            */ 
/*------------------------------------------------------------------------------------------*/ 
#include "2410lib.h" 
 
/*------------------------------------------------------------------------------------------*/ 
/*                const define         */ 
/*------------------------------------------------------------------------------------------*/ 
#define rCPLDIntControl  (*(volatile unsigned char*)0x22600000) 
#define rCPLDIntStatus   (*(volatile unsigned char*)0x22200000) 
#define LEDADDR (*(volatile unsigned char*)0x21180000) // LED Address
 
/*------------------------------------------------------------------------------------------*/ 
/*                           function declare                   */ 
/*------------------------------------------------------------------------------------------*/ 
void  __irq int_int(void); 
 
/********************************************************************************************* 
* name:  int_int 
* func:  EXTINT interrupt service routine 
* para:  none 
* ret:  none 
* modify: 
* comment:  
*********************************************************************************************/ 
void  __irq int_int(void) 
{   
	unsigned char Status; 
 
 	Status = rCPLDIntStatus;  
	Status = ~(Status & 0x6); 
 
    if(Status & 0x2)  
	{   
		uart_printf(" Eint0 interrupt occurred.\n");  
		// 1 2 3 4 5 6 7
		int i,j,time,nOut;
		nOut = 0xFF;
		float num[7]={3.8,3.4,3.0,2.8,2.6,2.2,2.0};
		for(i = 0; i < 7; i++){
			nOut = 0xF0 + ~(i+1);
			LEDADDR = nOut;
			time = int(num[i]/2.0*133333.0);
			for(j = 0;j < time; j++);
			nOut = 0x70 + ~(i+1);
			LEDADDR = nOut;
			for(j = 0;j < time; j++);
		}
		
		rCPLDIntControl |= (1<<1);   
		rCPLDIntControl &= ~(1<<1);  
	}  
	else if(Status & 0x4)  
	{   
		uart_printf(" EINT1 interrupt occurred.\n");   
		//star  
		int i,nOut;
		nOut = 0xF0;
		//1 1 5 5 6 6 5 4 4 3 3 2 2 1
		int shu[7] = {523,587,659,698,784,880,988}; 
		int starshu[14]={1,1,5,5,6,6,5,4,4,3,3,2,2,1};
		int star[14] = {523,523,784,784,880,880,784,698,698,659,659,587,587,523}; 
		for(i = 0; i < 14; i++){
			nOut = 0xF0 + ~starshu[i];
			LEDADDR = nOut;
			time = int(133333/2*star[i]);
			for(j = 0;j < time; j++);
			nOut = 0x70 + ~starshu[i];
			LEDADDR = nOut;
			for(j = 0;j < time; j++);
		}
		
		
		rCPLDIntControl |= (1<<2);   
		rCPLDIntControl &= ~(1<<2);  
	} 
 
 	rEINTPEND=(1<<9); 
 
    ClearPending(BIT_EINT8_23); 
} 
 
/********************************************************************************************* 
* name:  int_init 
* func:  Interrupt initialize 
* para:  none 
* ret:  none 
* modify: 
* comment:  
*********************************************************************************************/ 
void int_init(void)                          //  中断初始化函数
{     
	rSRCPND = rSRCPND;                       // Clear all interrupt   清除中断请求标志

    rINTPND = rINTPND;                       // Clear all interrupt   清除挂起寄存器    
	// nIntMode='3';  
	rGPGCON |= (0xf<<0);        
	rGPGCON &= (0xa<<0);                     //设置端口GPG1为INT9，GPG0为INT8 
 
 	rCPLDIntControl = 0xFF;  
	rCPLDIntControl = 0xF9;                  //CPLD控制寄存器中断按键中断
 
 	pISR_EINT8_23=(UINT32T)int_int;          //中断服务子程序入口地址
 
 	rEINTPEND = 0xffffff;                    //清楚外部中断请求标志
	rSRCPND = BIT_EINT8_23;                  // Clear the previous 
	pending states  
	rINTPND = BIT_EINT8_23;       
	
	rEXTINT1 &= ~((0x7<<4)|(0x7<<0));  
	rEXTINT1 |= ((0x2<<4)|(0x2<<0));         //设置中断触发方式
 
 	rEINTMASK &= ~(3<<8);                    //允许外部中断EINT9、EINT8 
	rINTMSK   &= ~(BIT_EINT8_23);            //设置中断屏蔽寄存器允许
} 
 
/********************************************************************************************* 
* name:  int_test 
* func:  Extern interrupt test 
* para:  none 
* ret:  none 
* modify: 
* comment:  
*********************************************************************************************/ 
void int_test(void) 
{  
	uart_printf("\n External Interrupt Test Example\n"); 
 
 	int_init(); 
 
 	while(1); 
} 
