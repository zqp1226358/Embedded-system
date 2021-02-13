/*********************************************************************************************
* File:		button_test.c
* Author:	embest
* Descript: Button_Test 
* History:	
*			EINT0 --- KEY1   EINT1 --- KEY2
*********************************************************************************************/

/*------------------------------------------------------------------------------------------*/
/*	 								include files						 				    */
/*------------------------------------------------------------------------------------------*/
#include "2410lib.h"

/*------------------------------------------------------------------------------------------*/
/*	 								const define						 				    */
/*------------------------------------------------------------------------------------------*/
#define rCPLDIntControl  (*(volatile unsigned char*)0x22600000)
#define rCPLDIntStatus   (*(volatile unsigned char*)0x22200000)

/*------------------------------------------------------------------------------------------*/
/*                                     function declare                                     */
/*------------------------------------------------------------------------------------------*/
void  __irq int_int(void);

/*********************************************************************************************
* name:		int_int
* func:		EXTINT interrupt service routine
* para:		none
* ret:		none
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
		rCPLDIntControl |= (1<<1);
		rCPLDIntControl &= ~(1<<1);
	}
	else if(Status & 0x4)
	{
		uart_printf(" EINT1 interrupt occurred.\n");
		rCPLDIntControl |= (1<<2);
		rCPLDIntControl &= ~(1<<2);
	}

	rEINTPEND=(1<<9);

    ClearPending(BIT_EINT8_23);
}

/*********************************************************************************************
* name:		int_init
* func:		Interrupt initialize
* para:		none
* ret:		none
* modify:
* comment:	
*********************************************************************************************/
void int_init(void)
{
    rSRCPND = rSRCPND;                							// Clear all interrupt
    rINTPND = rINTPND;                							// Clear all interrupt
    
	// nIntMode='3';
	rGPGCON |= (0xf<<0);			
    rGPGCON &= (0xa<<0);		

	rCPLDIntControl = 0xFF;
	rCPLDIntControl = 0xF9;

	pISR_EINT8_23=(UINT32T)int_int; 

	rEINTPEND = 0xffffff;
	rSRCPND = BIT_EINT8_23;										// Clear the previous pending states
	rINTPND = BIT_EINT8_23;
    
	rEXTINT1 &= ~((0x7<<4)|(0x7<<0));
	rEXTINT1 |= ((0x2<<4)|(0x2<<0));

	rEINTMASK &= ~(3<<8);
	rINTMSK   &= ~(BIT_EINT8_23);
}

/*********************************************************************************************
* name:		int_test
* func:		Extern interrupt test
* para:		none
* ret:		none
* modify:
* comment:	
*********************************************************************************************/
void int_test(void)
{

	uart_printf("\n External Interrupt Test Example\n");

	int_init();

	while(1);
}

