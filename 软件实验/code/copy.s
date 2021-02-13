	AREA Scopy,CODE,READONLY
	EXPORT strswap
	
strswap
	LDRB R2,[R0]
	LDRB R3,[R1]
	STRB R2,[R1],#1
	STRB R3,[R0],#1
	CMP R2,#0
	BNE strswap
	MOV PC,LR
	END