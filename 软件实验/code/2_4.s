	AREA Jump,CODE,READONLY
NUM EQU 4   ;跳转表中的子程序个数
	ENTRY

START
	MOV R0,#0 ;设置参数，选择调用哪个子程序
	MOV R1,#3 ;R1为子程序要用的参数
	MOV R2,#2 ;R2为子程序要用的参数

	CMP R0,#NUM    ;判断R0是否在有效的范围内
	MOVHS PC,LR    ;如果超出范围程序返回
	ADR R3,JTable  ;读取跳转表的基地址
	LDR PC,[R3,R0,LSL #2];根据R0的值跳转到相应的子程序
STOP
	MOV R0,#0x18
	LDR R1,=&20026
	SWI 0x123456
JTable
	DCD SUB0       ;当R0=0执行SUB0
	DCD SUB1       ;当R0=1执行SUB1
	DCD SUB2       ;当R0=2执行SUB2
	DCD SUB3       ;当R0=3执行SUB3
SUB0               ;子程序SUB0执行加法操作
	ADD R0,R1,R2
	MOV PC,LR
SUB1               ;子程序SUB1执行减法操作
	SUB R0,R1,R2
	MOV PC,LR
SUB2               ;子程序SUB2执行乘法操作
	MUL R0,R1,R2
	MOV PC,LR
SUB3               ;子程序SUB3执行传送操作
	MOV R0,#4
	MOV PC,LR
END