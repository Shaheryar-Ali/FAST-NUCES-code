[org 0x0100]
jmp start

Generate_code:
push bp
mov bp, sp
mov ax, [bp + 4]	;Since ah is 0 so there wont be any error

c1:
mov bx, ax			;This will be used for storing result of xor
and bx, 0x0001

mov cx, ax			;For d2
and cx, 0x0002
shr cx, 1
xor bx, cx

mov cx, ax			;For d4
and cx, 0x0008
shr cx, 3
xor bx, cx

mov cx, ax			;For d5
and cx, 0x0010
shr cx, 4
xor bx, cx

mov cx, ax			;For d7
and cx, 0x0080
shr cx, 6
xor bx, cx

mov dx, bx			;Storing final result of c1

c2:
mov bx, ax			;This will be used for storing result of xor
and bx, 0x0001

mov cx, ax			;For d3
and cx, 0x0004
shr cx, 2
xor bx, cx

mov cx, ax			;For d4
and cx, 0x0008
shr cx, 3
xor bx, cx

mov cx, ax			;For d6
and cx, 0x0020
shr cx, 5
xor bx, cx

mov cx, ax			;For d7
and cx, 0x0080
shr cx, 6
xor bx, cx

shl bx, 1
add dx, bx			;Storing result of c2

c3:
mov bx, ax			;For d2 in bx
and bx, 0x0002
shr 1

mov cx, ax			;For d3
and cx, 0x0004
shr cx, 2
xor bx, cx

mov cx, ax			;For d4
and cx, 0x0008
shr cx, 3
xor bx, cx

mov cx, ax			;For d8
and cx, 0x0080
shr cx, 7
xor bx, cx


shl bx, 2
add dx, bx			;Storing c3

c4:

mov bx, ax			;For d5
and bx, 0x0010
shr cx, 4

mov cx, ax			;For d6
and cx, 0x0020
shr cx, 5
xor bx, cx

mov cx, ax			;For d7
and cx, 0x0080
shr cx, 6
xor bx, cx

mov cx, ax			;For d8
and cx, 0x0080
shr cx, 7
xor bx, cx



shl bx, 3
add dx, bx			;Storing c4

mov [bp + 6], dx
pop bp
ret 2

Embed_code:
push bp
mov bp, sp
mov dx, [bp + 4]
mov ax, [bp + 6]
mov cx, ax				;used for storing result

shl cx, 4
and cx, 0x0f00

mov bx, dx
and bx, 0x0008
shl bx, 4

add cx, bx

mov bx, ax
and bx, 0x000e
shl bx, 3

add cx, bx

mov bx, dx
and bx, 0x0004
shl bx, 1

add cx, bx

mov bx, ax
and bx, 0x0001
shl 2

add cx, bx

mov bx, dx
and bx, 0x0003

add cx, bx

mov [bp+8], cx
pop bp
ret 4







start:
mov ax, [data]
sub sp, 2			;making space for return
push ax
call Generate_code
pop dx
mov [code], dx

mov ax, [data]		;just to be sure
sub sp, 2
push ax
push dx
call Embed_code
pop cx
mov [result] , cx



mov ax, 0x4c00
int 0x21

data:	dw 57
code:	dw 00
result: dw 0