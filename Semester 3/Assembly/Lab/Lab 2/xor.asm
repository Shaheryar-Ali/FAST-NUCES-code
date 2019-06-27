;Program for making ax 0 using xor only
[org 0x0100]

MOV AX, 0x2345		;
xor AX,	AX		; A XOR A = 0

MOV AX,0X4C00		;
INT 0X21		;