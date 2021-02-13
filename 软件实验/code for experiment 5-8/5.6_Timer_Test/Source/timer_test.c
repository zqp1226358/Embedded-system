/*********************************************************************************************
* File£º	timer_test.c
* Author:	embest
* Desc£º	Timer_Test
* History:	
*			
*********************************************************************************************/
/*------------------------------------------------------------------------------------------*/
/*                                     include files	                                    */
/*------------------------------------------------------------------------------------------*/
#include "2410lib.h"

/*------------------------------------------------------------------------------------------*/
/*               global varibles and interrupte service routine declare                     */
/*------------------------------------------------------------------------------------------*/
void __irq watchdog_int(void);
static volatile INT8T f_ucSecondNo;

/*------------------------------------------------------------------------------------------*/
/*                                     function code	                                    */
/*------------------------------------------------------------------------------------------*/
/*********************************************************************************************
* name:		watchdog_test
* func:		watchdog timer test function
* para:		none
* ret:		none
* modify:
* comment:		
*********************************************************************************************/
void timer_test(void)
{
	uart_printf("\n WatchDog Timer Test Example\n");
	uart_printf(" 10 seconds:\n");
	f_ucSecondNo = 0;
	ClearPending(BIT_WDT);							// clear interrupt pending bit
	pISR_WDT = (unsigned)watchdog_int;				// Initialize WDT interrupt handler entry
	rWTCON = ((PCLK/1000000-1)<<8)|(3<<3)|(1<<2);	//(0<<5)|	// 1M,1/128, enable interrupt
	rWTDAT = 7812;									// 1M/128=7812
	rWTCNT = 7812;
	rWTCON |=(1<<5);
	
	rINTMOD &= ~(BIT_WDT);
	rINTMSK &= ~(BIT_WDT);
	while((f_ucSecondNo)<11);
	
	rINTMSK |= BIT_WDT;								// mask watchdog timer interrupt
	uart_printf(" End.\n"); 
}

/*********************************************************************************************
* name:		watchdog_int
* func:		watchdog interrupt service routine
* para:		none
* ret:		none
* modify:
* comment:		
*********************************************************************************************/
void __irq watchdog_int(void)
{   
	ClearPending(BIT_WDT);
	f_ucSecondNo++;	
	if(f_ucSecondNo<11)
		uart_printf(" %ds ",f_ucSecondNo);
	else
		uart_printf("\n O.K.\n");
}
