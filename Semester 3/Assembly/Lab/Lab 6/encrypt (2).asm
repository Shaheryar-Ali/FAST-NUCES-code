[org 0x0100]

round1:
	mov dx, [key]
	mov ax, [key + 2]
	mov cx, [maska]
	mov bx, [maska + 2]
	
	xor dx, cx
	xor ax, bx		;compliment of bit
	
	shl ax, 1
	rcl dx, 1
	jnc skip1
		add ax, 1
skip1:
	mov [key], dx
	mov [key+2], ax		;Just storing key to be safe
	
	mov cx, [text]
	mov bx, [text + 2]
	
	add cx, dx			;we will dumb the carry
	add bx, ax
	jnc skip2
		add cx, 1
skip2:					;complete round 1
	mov [text], cx
	mov [text + 2], bx		;Stores new text
	
round2:
	mov dx,[key]
	mov ax, [key + 2]			;using them just to be safe
	mov cx, [maska]
	mov bx, [maska + 2]
	
	shl bx, 1
	rcl cx, 1
	mov [maska], cx
	mov [maska + 2], bx			;updating mask
	
	xor dx, cx
	xor ax, bx		;compliment of bit
	
	shr dx, 1
	rcr ax, 1
	jnc skip3
		add dx, 0x8000
skip3:
	mov [key], dx
	mov [key + 2], ax			;right rotated

	mov cx, [text]
	mov bx, [text + 2]			;retreiving text from round 1
	
	add cx, dx			;we will dumb the carry
	add bx, ax
	jnc skip4
		add cx, 1
skip4:					;complete round 1
	mov [text], cx
	mov [text + 2], bx		;Stores new text
	
round3:
	mov dx,[key]
	mov ax, [key + 2]			;using them just to be safe
	mov cx, [maska]
	mov bx, [maska + 2]
	
	shl bx, 1
	rcl cx, 1
	mov [maska], cx
	mov [maska + 2], bx			;updating mask

	xor dx, cx
	xor ax, bx		;compliment of bit

	
	shl ax, 1
	rcl dx, 1
	jnc skip5
		add ax, 1
skip5:
	mov [key], dx
	mov [key+2], ax		;Just storing key to be safe
	
	mov cx, [text]
	mov bx, [text + 2]
	
	add cx, dx			;we will dumb the carry
	add bx, ax
	jnc skip6
		add cx, 1
skip6:					;complete round 3
	mov [text], cx
	mov [text + 2], bx		;Stores new text

round4:
	mov dx,[key]
	mov ax, [key + 2]			;using them just to be safe
	mov cx, [maska]
	mov bx, [maska + 2]
	
	shl bx, 1
	rcl cx, 1
	mov [maska], cx
	mov [maska + 2], bx			;updating mask
	
	xor dx, cx
	xor ax, bx		;compliment of bit
	
	shr dx, 1
	rcr ax, 1
	jnc skip7
		add dx, 0x8000
skip7:
	mov [key], dx
	mov [key + 2], ax			;right rotated

	mov cx, [text]
	mov bx, [text + 2]			;retreiving text from round 1
	
	add cx, dx			;we will dumb the carry
	add bx, ax
	jnc skip8
		add cx, 1
skip8:					;complete round 1
	mov [text], cx
	mov [text + 2], bx		;Stores new text


	
mov ax, 0x4c00
int 0x21

text:	dw 0x15D3, 0xc257
key:	dw 0x23cd, 0xe689
maska:	dw 0xAAAA, 0xAAAA 