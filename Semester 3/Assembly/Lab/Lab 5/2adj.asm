;For checking adjacent bits

[org 0x0100]

	mov bx, [num1]
	mov cx,	0
	
start:
	cmp cx, 16
	je	comp
	add cx, 1
	
	shr bx, 1
	jc next				;In case we get first one
	jnc start

	next:
		shr bx, 1
		jc succ			;In case we find second as well
		jnc start
		
succ:
	mov ax, 1
	jmp exita
	
comp:
	mov ax, 0
	
exita:




mov ax, 0x4c00
int 0x21

num1	:	dw	133