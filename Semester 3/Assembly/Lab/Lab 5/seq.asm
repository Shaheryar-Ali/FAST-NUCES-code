;Storing sequence
[org 0x0100]

	mov cx, [count]		;Stores count
	mov bx, sequen		;Stores place in memory which will store sequence
	mov ax, 1

	loopa:
		shl ax, 1
		sub cx, 1
		jnz loopa
		
	
	loopb:
		mov [bx], ax	;Stores element of sequence in memory
		add bx, 1
		shr ax, 1
		jnz loopb		;Works until all bits are shifted
		



mov ax, 0x4c00
int 0x21

sequen:	dw	0
count:	dw  7