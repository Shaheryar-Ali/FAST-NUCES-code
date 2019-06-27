;Program for shifting nibble in each byte
[org 0x0100]

	mov ax, [d]
	mov dx, 0
	
	mov bx, ax
	and bx, 0x0f0f
	shl bx, 4
	add dx, bx
	
	mov bx, ax
	and bx, 0xf0f0
	shr bx, 4
	add dx, bx
	
	mov ax, dx;

mov ax, 0x4c00
int 0x21

d : dw 0xC3F0