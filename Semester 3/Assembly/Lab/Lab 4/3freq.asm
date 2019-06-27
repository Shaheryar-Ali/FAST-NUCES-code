[org 0x0100]

mov bx, 0

mov ch, [siz]

loop_out:
	cmp ch, 0
	je exit
	mov cl, [siz]
	mov al, [arr+ bx]	;Stores the element we are checking
	mov ah,	0			;Counter for number of occurence, it will become 1 at least when we check for same index 
	mov si, 0
	loop_in:
		cmp cl, 0
		je skip2
		cmp al, [arr + si]
		jne skip1
		add ah, 1
		skip1:
		add si, 1
		sub cl, 1
		jmp loop_in
	skip2:
	cmp ah, [max_c]
	jb skip3
	mov [max_c], ah
	mov [max_n], al
	skip3:
	add bx, 1
	sub ch, 1
	jmp loop_out

	
exit:
	
mov ax, 0x4c00
int 0x21

arr:	db	1,1,2,2,2,3,1
siz:	db	7
max_c:	db	0
max_n:	db	0