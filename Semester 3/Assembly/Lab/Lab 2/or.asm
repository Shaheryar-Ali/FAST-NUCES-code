;Program for making ax 0 using or
[org 0x0100]

MOV AX, 0x7432		;
or AX,	0xffff		; A XOR A = 0

MOV AX,0X4C00		;
INT 0X21		;