[org 0x0100]
;Find element in array
mov cl, [Siz]
mov bx, 0

loop1:
	cmp cl, 0
	je exi1
	mov al, [array + bx]
	add [sum], al
	inc bx
	dec cl
	jmp loop1
	
exi1:
	mov bx, 0
	mov ah, [Key]
	
loop2:
	cmp cl, [Siz]
	je exi2
	mov al, [array + bx]
	cmp ah, al
	je exi2
	inc cl
	inc bx
	jmp loop2

exi2:
cmp cl, [Siz]
je nfound

mov al, [sum]
mov [array + bx], al
jmp exit

nfound:
add bx, 1
mov [array+bx], ah


exit:



mov ax, 0x4c00
int 0x21

array:	db 3, 5,9,10,99,4,1,3,10,8
Key:	db 1
Siz:	db 10
sum:	db 0