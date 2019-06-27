[org 0x0100] 
mov ax,0xaaaa
mov cx,3
mov dx,8


l1:
mov bx,ax
and bx,cx
cmp bx,cx 
je skip 

cmp bx,0 
je skip 

xor ax,cx

skip: 
shl cx,2
dec dx
jnz l1

mov ax,0x4c00 
int 0x21