;invert bits
[org 0x0100]

MOV AX, 0x2345		;
not AX			;

MOV AX,0X4C00		;
INT 0X21		;