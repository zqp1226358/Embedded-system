/********************************************************************************************* 
* File£º uart_test.c 
* Author: embest 
* Desc£º Uart_Test 
* History:  
*********************************************************************************************/ 
/*------------------------------------------------------------------------------------------*/ 
/*                      include files                        */ 
/*------------------------------------------------------------------------------------------*/ 
//#include "uart_test.h" 
#include "2410addr.h"
#include "2410lib.h"

#define LEDADDR (*(volatile unsigned char*)0x21180000) 
/********************************************************************************************* 
* name:  uart1_test 
* func:  uart test function 
* para:  none 
* ret:  none 
* modify: 
* comment:   
*********************************************************************************************/ 


void uart1_test(void) 
{  
	char cInput[256];  
	UINT8T ucInNo=0;  
	UINT32T g_nKeyPress;  
	char c;  
	uart_printf("\n UART1 Communication Test Example\n");   
	uart_printf(" Please input words, then press Enter:\n");  
	uart_printf(" />");  
	uart_printf(" ");  
	g_nKeyPress = 1;  
	while(g_nKeyPress==1)   
	// only for board test to exit  
	{   
		c=uart_getch();   
		//uart_sendbyte(c);      
		//uart_printf("%c",c);   
		if(c!='\n'){
			cInput[ucInNo++]=c;   
			int sum = 0,i;
			if (c >= '0'&&c <= '9') 
			{ 
				sum = sum + (c - '0'); 
			}
			if (c >= 'A'&&c <= 'Z')
			{
				sum = sum + (c - 'A' + 10); 
			}
			LEDADDR = 0xF0 + sum;
			for(i=0;i<100000;i++); 
		}    	
		else   
		{    
			cInput[ucInNo]='\0';    
			break;   
		}  
	}  
	delay(1000);  
 
 	uart_printf(" \nThe words that you input are: %s\n",cInput);    
	uart_printf(" end.\n");  
}
