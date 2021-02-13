	AREA	Shineng, CODE, READONLY
 		    GLOBAL	start2
 		    ENTRY

start2
			MRS R0,CPSR
			BIC R0,R0,#0x80
			MSR CPSR_c,R0 
			
			MRS R0,CPSR
			ORR R0,R0,#0x80
			MSR CPSR_c,R0
			
			END