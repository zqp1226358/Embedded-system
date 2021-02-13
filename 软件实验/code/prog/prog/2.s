	AREA	Second, CODE, READONLY
 		    GLOBAL	start2
 		    ENTRY

start2
			MOV R0,#1
			MOV R1,#2
			MOV R2,#3
			MOV R3,#4
			MUL R4,R0,R1
			MUL R4,R2,R4
			MUL R4,R3,R4
stop        
			MOV R0,#&18
			LDR R1,=&20026
			SWI 0x123456
			END