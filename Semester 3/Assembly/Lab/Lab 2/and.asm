;Program for making ax 0 using and 
[org 0x0100]

MOV AX, 0x2bae		;
and AX,	0000		; A and 0 = 0

MOV AX,0X4C00		;
INT 0X21		;