[org 0x0100]


mov ax, 0xb800
mov es, ax
mov ax, 160
mov si, 12
mul si
mov si,ax
add si,80

mov cx, [size]
mov bx, string
mov ah, 0x7A

l1:
mov al, [bx]
mov [es:si], ax
add bx, 1
add si, 2
loop l1



mov ax, 0x4c00
int 21h
string: db 'omer'
size: dw 4