	AREA fun,CODE,READONLY
	IMPORT g
	ENTRY
	
	MOV R0,#1
	ADD R1,R0,R0
	ADD R2,R1,R0
	ADD R3,R2,R0
	ADD R4,R3,R0
	ADD R5,R4,R0
	STR R4,[SP,#-4]!
	STR R5,[SP,#-4]!
	BL g
	ADD SP,SP,#4
	ADD SP,SP,#4
	
	END