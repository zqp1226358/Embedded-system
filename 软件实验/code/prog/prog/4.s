	AREA	Interrupt, CODE, READONLY
 		    GLOBAL	start4
 		    ENTRY

start4
			MRS R0,CPSR
			BIC R0,R0,#0x40  ;Fλ������������ж�
			MSR CPSR_c,R0 
			
			MRS R0,CPSR
			ORR R0,R0,#0x40  ;Fλ��1��ֹ�����ж�
			MSR CPSR_c,R0
			
stop        
			MOV R0,#&18
			LDR R1,=&20026
			SWI 0x123456
			END