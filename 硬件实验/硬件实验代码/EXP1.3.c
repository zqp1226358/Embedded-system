/********************************************************************************************
*  1on, 2on, 3on, 4on, 1234off, 4on, 4off and 3on, 3off and 2on, 2off and 1on, 1off
*********************************************************************************************/

/*********************************************************************************************
* File�� led_test.c
* Author: embest
* Desc�� Led_Test
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
* name: led_on
* func: turn on the leds one by one
* para: none
* ret: none
* modify:
* comment:
*********************************************************************************************/
void led_on(void)
{
int i,nOut;
nOut = 0xFF;
LEDADDR = nOut & 0xFE;
for(i = 0; i < 100000; i++);
LEDADDR = nOut & 0xFC;
for(i = 0; i < 100000; i++);
LEDADDR = nOut & 0xF8;
for(i = 0; i < 100000; i++);
LEDADDR = nOut & 0xF0;
for(i = 0; i < 100000; i++);
}
/*********************************************************************************************
* name: led_off
* func: 4on, 4off and 3on, 3off and 2on, 2off and 1on, 1off
* para: none
* ret: none
* modify:
* comment:
*********************************************************************************************/
void led_on_off(void)
{
int i,nOut;

LEDADDR = 0xF7;    //0111
for(i = 0; i < 100000; i++);
LEDADDR = 0xFB;    //1011
for(i = 0; i < 100000; i++);
LEDADDR = 0xFD;    //1101
for(i = 0; i < 100000; i++);
LEDADDR = 0xFE;    //1110
for(i = 0; i < 100000; i++);
LEDADDR = 0xFF;   //1111
for(i = 0; i < 100000; i++);
}

/*********************************************************************************************
* name: led_on_off
* func: turn off the 4 leds
* para: none
* ret: none
* modify:
* comment:
*********************************************************************************************/
void led1234_off(void)
{
int i;
LEDADDR = 0xFF;     //1111
for(i = 0; i < 100000; i++);
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
led_on();
led1234_off();
led_on_off();
delay(2000);
uart_printf(" end.\n");
}
