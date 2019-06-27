;Program to catculate one bits in bx and compliment that many bits in ax

[org 0x0100]

	mov cx, 0
	mov dx, 0
	mov ax, 0x1234
	mov bx, 0x1a32

	count1:				;counter for 1 bits in bx
		cmp bx, 0
		je out1
		shr bx, 1
		jnc skip1
			add cx, 1
		skip1:
			jmp count1	

	out1:					;Serves as escape for loop 1 and check for loop 2
	
		cmp cx, 0
		je out2
		
		shl dx, 1
		add dx, 1
		sub cx, 1
		jmp out1			
	out2:
	
	xor ax, dx
	
mov ax, 0x4c00
int 0x21