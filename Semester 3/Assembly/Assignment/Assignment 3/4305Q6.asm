;From to compliment certain bit
[org 0x0100]

	mov bx, 0x5694
	mov ax, 6
	mov cx, 0

	loop1:
		cmp ax,0
		je out1
		sub ax, 1
		shl dx, 1
		jnz loop1
			add dx, 1			;It will run in first iteration to put 1 in dx
		jmp loop1

	out1:
	
	and bx, dx

mov ax, 0x4c00
int 0x21

