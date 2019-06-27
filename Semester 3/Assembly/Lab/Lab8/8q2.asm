[org 0x0100]
jmp start

strin:	db	'This is Fast', 0 
lengt:	db	12

clrscr:
push es
push ax
push di

mov ax, 0xb800
mov es, ax
mov di, 0

	nextloc:
	mov word [es:di], 0x0720
	add di, 2
	cmp di, 4000
	jne nextloc
	
pop di
pop ax
pop es
ret


nospace:
push bp
mov bp, sp
mov si, [bp + 6]	;address of string
mov cl, [lengt]	;length of string
mov ax, 0xb800
mov es, ax
mov di, 0
mov ah, 0x07

	modify:
	mov al, [si]
	cmp al, 0
	je exit
	cmp al, 0x20
	je n_print
	mov [es:di], ax
	add di, 2
	n_print:
	add si, 1
	sub cx, 1
	jmp modify
	

exit:
	
pop bp
ret 4

start:
call clrscr
mov bx, strin
push bx
mov ax, [lengt]
push ax
call nospace