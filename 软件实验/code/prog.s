	AREA  First, CODE, READONLY
 		GLOBAL	start1
 		ENTRY 		
 		
start1	
 		MOV  R0, #1  
		CMP  R0, #0    ;R0=0转移到标号L0处
		BEQ  L0
		CMP  R0, #1    ;R0=1转移到标号L1处  
		BEQ  L1
		CMP  R0, #2    ;R0=2转移到标号L2处
		BEQ  L2
		B OVER         ;否则不转移程序结束
		
L0      MOV R0,#7
        B OVER      
L1      MOV R0,#6
		B OVER
L2      MOV R0,#8
		B OVER
OVER       
		MOV R0,#&18
		LDR R1,=&20026
		SWI 0x123456
 		END
