	AREA Jump,CODE,READONLY
NUM EQU 4   ;��ת���е��ӳ������
	ENTRY

START
	MOV R0,#0 ;���ò�����ѡ������ĸ��ӳ���
	MOV R1,#3 ;R1Ϊ�ӳ���Ҫ�õĲ���
	MOV R2,#2 ;R2Ϊ�ӳ���Ҫ�õĲ���

	CMP R0,#NUM    ;�ж�R0�Ƿ�����Ч�ķ�Χ��
	MOVHS PC,LR    ;���������Χ���򷵻�
	ADR R3,JTable  ;��ȡ��ת��Ļ���ַ
	LDR PC,[R3,R0,LSL #2];����R0��ֵ��ת����Ӧ���ӳ���
STOP
	MOV R0,#0x18
	LDR R1,=&20026
	SWI 0x123456
JTable
	DCD SUB0       ;��R0=0ִ��SUB0
	DCD SUB1       ;��R0=1ִ��SUB1
	DCD SUB2       ;��R0=2ִ��SUB2
	DCD SUB3       ;��R0=3ִ��SUB3
SUB0               ;�ӳ���SUB0ִ�мӷ�����
	ADD R0,R1,R2
	MOV PC,LR
SUB1               ;�ӳ���SUB1ִ�м�������
	SUB R0,R1,R2
	MOV PC,LR
SUB2               ;�ӳ���SUB2ִ�г˷�����
	MUL R0,R1,R2
	MOV PC,LR
SUB3               ;�ӳ���SUB3ִ�д��Ͳ���
	MOV R0,#4
	MOV PC,LR
END