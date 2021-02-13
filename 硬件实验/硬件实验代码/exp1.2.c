/*********************************************************************************************
* File£º led_test.c
* Author: embest
* Desc£º Led_Test
* History:
*********************************************************************************************/
/*------------------------------------------------------------------------------------------*/
/* include files */
/*------------------------------------------------------------------------------------------*/
#include "2410lib.h"
/*------------------------------------------------------------------------------------------*/
/* constant define */
/*------------------------------------------------------------------------------------------*/
#define LEDADDR (*(volatile unsigned char*)0x21180000) // LED Address
/*********************************************************************************************
* name: led1234_on_off
* func: turn on the leds one by one
* para: none
* ret: none
* modify:
* comment:
*********************************************************************************************/
void led1234_on_off(void)
{
int i;


LEDADDR = 0xFE;    //1110
for(i = 0; i < 1000000; i++);
LEDADDR = 0xFF;   //0001
for(i = 0; i < 1000000; i++);

LEDADDR =  0xFD;    //1101
for(i = 0; i < 1000000; i++);
LEDADDR =  0xFF;   //0010
for(i = 0; i < 1000000; i++);

LEDADDR =  0xFB;   //1011
for(i = 0; i < 1000000; i++);
LEDADDR = 0xFF;   //0100
for(i = 0; i < 1000000; i++);

LEDADDR = 0xF7;   //0111
for(i = 0; i < 1000000; i++);
LEDADDR = 0xFF;  //1000
for(i = 0; i < 1000000; i++);
}
/*********************************************************************************************
* name: led1423_on_off
* func: turn on the 1st and 4th leds, than turn off the 1st and 4th leds, 
		than turn on the 2nd and 3rd leds, than turn off the 2nd and 3rd leds
* para: none
* ret: none
* modify:
* comment:
*********************************************************************************************/
void led1423_on_off(void)
{
int i;


LEDADDR =  0xF6;    //0110
for(i = 0; i < 1000000; i++);

LEDADDR = 0xFF;    //1001
for(i = 0; i < 1000000; i++);

LEDADDR =  0xF9;    //1001
for(i = 0; i < 1000000; i++);

LEDADDR =  0xFF;    //0110
for(i = 0; i < 1000000; i++);
}
/*********************************************************************************************
* name: led_test
* func: i/o control test(led)
* para: none
* ret: none
* modify:
* comment:
*********************************************************************************************/
void led_test(void)
{
uart_printf(" Expand I/O (Diode Led) Test Example\n");
uart_printf(" Please Look At The LEDS \n");
led1234_on_off();
led1423_on_off();
delay(2000);
uart_printf(" end.\n");
}
