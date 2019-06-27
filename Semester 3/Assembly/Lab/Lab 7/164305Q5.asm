
[org 0x0100]

jmp start

palindrome:
push bp
mov bp, sp
mov bx, [bp + 6]
mov si, [bp + 4]
cmp bx, si
jae true
mov al, [bx]
mov ah, [si]
cmp al, ah
jne false
je recall

pop dx
mov [bp+8], dx
pop bp
ret 4

recall:
add bx, 1
sub si, 1
sub sp, 2
push bx
push si
call palindrome
pop dx		;temporarary disposal value
mov [bp + 8],dx
pop bp
ret 4

false:
mov dx, 1
mov [bp+8], dx
pop bp
ret 4


true:
mov dx, 1
mov [bp+8], dx
pop bp
ret 4



start:

mov ax, [size]
mov bx, array
mov si, array
add si, ax
sub si, 1

sub sp, 2
push bx			;For start index
push si			;For end index
call palindrome
pop dx

mov ax, 0x4c00
int 0x21


array:db 1, 2, 5, 2, 1
size:dw 5