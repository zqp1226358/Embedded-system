	AREA	Third, CODE, READONLY
 		    GLOBAL	start3
 		    ENTRY

start3
			LDR R0,=0xAAAA
			BIC R0,R0,#0xFF
			ORR R0,R0,#0xB
stop        
			MOV R0,#&18
			LDR R1,=&20026
			SWI 0x123456
			END