[org 0x0100]
jmp start

star:	db	'*'

printstr:
push bp
mov bp, sp


mov ax, 0xb800
mov es, ax
mov di, 0
mov bx, [bp + 4]
mov ah, 0x07
mov si, 158				; si is right corner
mov al, [bx]

nextchar:
mov [es:di], ax
mov [es:si], ax

mov cx , 0xffff
l1:
loop l1
mov cx , 0xffff
l2:
loop l2

mov word [es:di], 0x0720
mov word [es:si], 0x0720
add di, 164
add si, 156
cmp di, si
jl nextchar

reverchar:
sub si, 156
sub di, 164

mov [es:di], ax
mov [es:si], ax

mov cx , 0xffff
l3:
loop l3
mov cx , 0xffff
l4:
loop l4

mov word [es:di], 0x0720
mov word [es:si], 0x0720

cmp di, 158
ja reverchar

jmp nextchar

pop bp 
ret 2




start:
mov bx, star
push bx
mov ax, 0
call printstr

mov ax, 0x4c00
int 0x21