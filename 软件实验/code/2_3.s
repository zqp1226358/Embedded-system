	AREA Code21,CODE,READONLY
M1 DCB 3,4,5,6,2,7,8,4,9,34,23,43,12,26,37,26,27,39,47,23
	ENTRY
	
 	LDR R1,=M1
 	MOV R2,#20-1
 	LDRB R0,[R1]  ;�����Сֵ
cmpl
 	LDRB R3,[R1]  ;�ӵ�һ������ʼ�Ƚ�
 	CMP R0,R3
 	BLE loop     ;�������ԭ��С����ת�Ƚ���һ��ֵ
 	MOV R0,R3    ;������С��ֵ ����R0	
loop
	ADD R1,R1,#1 ;���ֽ�Ϊ��λ
	SUB R2,R2,#1 ;������һ
	CMP R2,#0    ;20�����Ƚ�19��
	BNE cmpl

    ;����       
	MOV R0,#&18
	LDR R1,=&20026
	SWI 0x123456
 	END
	