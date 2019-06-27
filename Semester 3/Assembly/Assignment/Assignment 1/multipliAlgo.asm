[org 0x0100]


mov ax, 4
mov bx, 3
mov cx, 4


l1:
shr bx,1
jnc NotaddToResult

add [result],ax


NotaddToResult
shl ax,1
dec cx
jnz l1

mov ax, 0x4c00
int 21h

result: dw 0