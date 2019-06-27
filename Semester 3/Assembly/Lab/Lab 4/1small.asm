[org 0x0100]

mov al, [n1]
mov bl, [n2]
cmp al, bl
jg second				;Skip in case its greater
	mov bl, [n3]
	cmp al, bl
	jg second			
	mov dl, al
	jmp exit

second:
mov al, [n2]
mov bl, [n1]
cmp al, bl
jg third				;Skip in case its greater
	mov bl, [n3]
	cmp al, bl
	jg third			
	mov dl, al
	jmp exit

third:
mov al, [n3]
mov dl, al

exit:

mov ax, 0x4c00
int 0x21

n1:	db	10
n2:	db	5
n3:	db	2