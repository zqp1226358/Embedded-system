	AREA  First, CODE, READONLY
 		GLOBAL	start1
 		ENTRY 		
 		
start1	
 		MOV  R0, #1  
		CMP  R0, #0    ;R0=0ת�Ƶ����L0��
		BEQ  L0
		CMP  R0, #1    ;R0=1ת�Ƶ����L1��  
		BEQ  L1
		CMP  R0, #2    ;R0=2ת�Ƶ����L2��
		BEQ  L2
		B OVER         ;����ת�Ƴ������
		
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
