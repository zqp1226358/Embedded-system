	AREA Code21,CODE,READONLY
M1 DCD 1,2,3,4
M2 DCD 9,8,7,6
	ENTRY
	
	LDR R0,=M1
	LDR R1,=M2
	
	LDMIA R0!,{R2-R5}
	STMIA R1!,{R2-R5}
 	
STOP
	MOV R0,#0x18
	LDR R1,=&20026
	SWI 0x123456
	
	
	
	
	