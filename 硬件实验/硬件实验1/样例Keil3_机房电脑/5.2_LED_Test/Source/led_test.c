/*********************************************************************************************
* File��	led_test.c
* Author:	embest
* Desc��	Led_Test
* History:	
*********************************************************************************************/

/*------------------------------------------------------------------------------------------*/
/*                                     include files	                                    */
/*------------------------------------------------------------------------------------------*/
#include "2410lib.h"

/*------------------------------------------------------------------------------------------*/
/*                                     constant define	                                    */
/*------------------------------------------------------------------------------------------*/
#define rCPLDLEDADDR  (*(volatile unsigned char*)0x21180000) 			// LED Address

/*********************************************************************************************
* name:		led_on
* func:		turn on the leds one by one
* para:		none
* ret:		none
* modify:
* comment:		
*********************************************************************************************/
void led_on(void)
{
	int i,nOut;
	nOut = 0xFF;

	rCPLDLEDADDR = nOut & 0xFE;
	for(i = 0; i < 100000; i++);
	rCPLDLEDADDR = nOut & 0xFC;  
	for(i = 0; i < 100000; i++);	
	rCPLDLEDADDR = nOut & 0xF8;   
	for(i = 0; i < 100000; i++);	
	rCPLDLEDADDR = nOut & 0xF0;  
	for(i = 0; i < 100000; i++);

}


/*********************************************************************************************
* name:		led_on_off
* func:		turn on the 4 leds and then turn off the 4 leds 
* para:		none
* ret:		none
* modify:
* comment:		
*********************************************************************************************/

/*********************************************************************************************
* name:		led_test
* func:		i/o control test(led)
* para:		none
* ret:		none
* modify:
* comment:		
*********************************************************************************************/
void led_test(void)
{

	uart_printf("\n Expand I/O (Diode Led) Test Example\n");
	uart_printf(" Please Look At The LEDS \n");

	led_on();
	delay(2000);
	uart_printf(" End.\n");
}
