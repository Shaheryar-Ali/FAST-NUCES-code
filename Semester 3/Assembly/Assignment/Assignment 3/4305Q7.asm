[org 0x0100]

	mov ax, 0x733a
	mov cx, 0
	mov bx, 0
	mov dx, ax
	
	count1:				;counter for 1 bits in bx
		cmp ax, 0
		je out1
		shr ax, 1
		jnc skip1
			add cx, 1
		skip1:
			jmp count1	
			
	out1:
	
	cmp dx, 1
	jbe skip			;to prevent counting in bx in case ax was already 1 or 0 from start
		add bx, 1
	skip:
	mov ax, cx
	mov cx, 0
	cmp ax, 1
	ja	count1
	
	

mov ax, 0x4c00
int 0x21