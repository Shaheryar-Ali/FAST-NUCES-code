;Program for shifting bit in each pair
[org 0x0100]

	mov ax, [d]
	mov dx, 0
	
	mov bx, ax
	and bx, 0x5555
	shl bx, 1
	add dx, bx
	
	mov bx, ax
	and bx, 0xAAAA
	shr bx, 1
	add dx, bx
	
	mov ax, dx;

mov ax, 0x4c00
int 0x21

d : dw 0x14e9