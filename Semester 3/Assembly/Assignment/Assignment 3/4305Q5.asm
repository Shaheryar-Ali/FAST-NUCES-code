;Program for picking number starting from certain byte
[org 0x0100]

	mov cl, [num]
	mov dx, 0

	pick:					;For deciding which byte from buffer should be picked
		cmp cl, 8
		jl out1
		add dx, 1
		sub cl, 8
		jmp pick
		
	out1:
		
		mov bx, buffer
		add bx, dx			;getting required byte from buffer
		mov ah, [bx]		;current byte
		mov al, [bx+1]		;storing next byte 
		
	pick2:
		cmp cl, 0
		jz stop
		shl ax, 1
		sub cl, 1
		jmp pick2
		
stop:
	mov al, 0				;So only ah is left with solution
		

		
mov ax, 0x4c00
int 0x21

buffer: db 0xc0, 0x06, 0xc1, 0x89, 0xe7, 0xa1, 0x1b, 0xe3, 0xef, 0x81, 0xdd, 0x0d, 0xb8, 0xf6, 0x92, 0x9c 
num:	db 0x5c