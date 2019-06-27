mov bx, n1 
mov cx, [bx]
mov dx, [n2]
add cx,dx

mov al,[n3]
sub cl,al
mov [n3],cl

mov al, [n4]
add [n3], al
sub byte[n3],10

mov ax, 0x4c00 		; terminate program
int 0x21

n1 :dw  5
n2: dw  10
n3: db  6
n4: db  30
