;Program to find quotient and remainder
[org 0x0100]
	mov dl, [num1]
	mov dh, [num2]
	mov al, 0
	
divi:
	cmp dl,dh
	jl res
	
	sub dl,dh
	add al,1
	jmp divi
	
res:
	mov ah, dl
	
	mov ax,0x4c00
	int 0x21
	
num1 : db 29
num2 : db 5