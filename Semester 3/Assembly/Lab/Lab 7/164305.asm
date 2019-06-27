;Binary search
[org 0x0100]

jmp start

binary:
push bp
mov bp, sp
mov bx, [bp + 6]
mov si, [bp + 4]
cmp bx,si
ja exit
mov ax, bx
add ax, si
mov cx, 2
div cx
mov di, ax
mov al, [key]
mov ah, [di]
cmp al,ah
ja greater
jb smaller
je return




return:
	mov [bp+8], di
	mov dx, di
	pop bp
	ret 4
	
greater:
	mov bx, di
	add bx, 1
	jmp recall
	
smaller:
	mov si, di
	sub si, 1
	
recall:
sub sp, 2
push bx
push si
call binary
pop dx		;temporarary disposal value
mov [bp + 8],dx
pop bp
ret 4 

start:
mov bx, array
mov si, array
mov ax, [siz]
add si, ax				;Add size of array
sub sp, 2
push bx
push si
call binary
pop dx

mov bx, array
sub dx, bx


exit:

mov ax, 0x4c00
int 0x21

array: db 1,2,3,6,7,9,10,13, 16, 21, 25
siz: dw 10
key: db 6 