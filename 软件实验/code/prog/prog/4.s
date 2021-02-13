	AREA	Interrupt, CODE, READONLY
 		    GLOBAL	start4
 		    ENTRY

start4
			MRS R0,CPSR
			BIC R0,R0,#0x40  ;F位清零允许快速中断
			MSR CPSR_c,R0 
			
			MRS R0,CPSR
			ORR R0,R0,#0x40  ;F位置1禁止快速中断
			MSR CPSR_c,R0
			
stop        
			MOV R0,#&18
			LDR R1,=&20026
			SWI 0x123456
			END