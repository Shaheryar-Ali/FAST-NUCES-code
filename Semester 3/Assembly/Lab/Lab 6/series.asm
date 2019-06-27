[org 0x0100]
	
start:
	mov cx, [n]				;Stores previous counter
	mov bx, [l]
	cmp cx, bx
	jge exit				;condition for checking remaining loops
	mov bx, [r]				;It will continuously retain value of r
	add cx, 1
	mov [n], cx				;Storing the current counter in memory
	mov ax, bx				; r ^ 1

exp:
	sub cx, 1
	jz store				
	mul bx					
	jmp exp


store:
	mov cx, [n]
	div cx
	mov si, [ans]
	add ax, si
	mov [ans], ax
	jmp start
	
exit:

mov ax, 0x4c00
int 0x21

r	:	dw 2
l	:	dw 8
ans :	dw 0
n	:	dw 0