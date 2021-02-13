	AREA Code21,CODE,READONLY
M1 DCB 3,4,5,6,2,7,8,4,9,34,23,43,12,26,37,26,27,39,47,23
	ENTRY
	
 	LDR R1,=M1
 	MOV R2,#20-1
 	LDRB R0,[R1]  ;存放最小值
cmpl
 	LDRB R3,[R1]  ;从第一个数开始比较
 	CMP R0,R3
 	BLE loop     ;如果不比原来小就跳转比较下一个值
 	MOV R0,R3    ;遇见更小的值 更新R0	
loop
	ADD R1,R1,#1 ;以字节为单位
	SUB R2,R2,#1 ;个数减一
	CMP R2,#0    ;20个数比较19次
	BNE cmpl

    ;结束       
	MOV R0,#&18
	LDR R1,=&20026
	SWI 0x123456
 	END
	