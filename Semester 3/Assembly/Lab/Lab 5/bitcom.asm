;bit by bit comparison

[org 0x0100]

	mov cx, 0
	mov ax, [num1]
	mov bx, [num2]
start:
	cmp cx, 16		;To make sure it only check 16 bits
	je succ
	add cx, 1
	
	shr ax,1		;Transfers lsb to cf
	jnc set0		;In case cf is 0
	jc set1			;In case cf is 1
	
	set0:
		shr bx, 1		;Shifts lsb in cf so we can compare
		jnc start		;In case they match repeat the love
		jc	exit		;In case of mismatch, exit
		
	set1:
		shr bx, 1		;Shifts lsb in cf so we can compare
		jc start		;In case they match repeat the love
		jnc	exit		;In case of mismatch, exit
		
succ:
	mov dx, 0x000a
	jmp enda
	
exit:
	mov dx, 0x000f

enda:

mov ax, 0x4c00
int 0x21

num1:	dw 250
num2:	dw 250