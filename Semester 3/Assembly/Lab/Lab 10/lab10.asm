[org 0x0100]

jmp start

myisr21:

push di
push si
push dx
push cx
push bx
push ax
push bp
mov bp, sp
push ds
push es

mov bx, [oldisr]
mov [es: 21h * 4], bx

mov bx, [oldisr + 2]		
mov [es:21h * 4 + 2], bx					;Hooked input

call clrscr
mov ax, [bp + 2]

cmp al, 100
call date






pop es
pop ds
pop bp
pop ax
pop bx
pop cx
pop dx
pop si
pop di

clrscr:
push es
push ax
push cx
push di

mov ax, 0xb800
mov es, ax
xor di, di
mov ax, 0x0720
mov cx, 2000

cld
rep stosw

pop di
pop cx
pop ax
pop es

ret							;End of date function

date:

push di
push si
push dx
push cx
push bx
push ax
push bp
mov bp, sp

mov ah, 2ah
int 21h

call prt_date
pop bp
pop ax
pop bx
pop cx
pop dx
pop si
pop di
ret



prt_date:
push dx
push cx
push es
push bp
mov bp, sp

mov ax, 0xb800
mov es, ax
xor di, di

mov ah, 07
mov al, dl
mov [es: di], dx			;Prints date

add di, 2
mov al, 47
mov [es:di], ax				;Prints slash

add di, 2
mov al, dh
mov [es:di], ax				;Prints month

add di, 2
mov al, 47
mov [es:di], ax				;Prints slash

add di, 2
mov al, ch
mov [es:di], ax				

add di, 2
mov al, cl
mov [es:di], ax				;Prints year

pop bp
pop es
pop cx
pop dx

ret



start:
xor ax, ax
mov es, ax								;Load 0 in es

mov ax, [es:21h * 4]
mov [oldisr], ax

mov ax, [es:21h * 4 + 2]
mov [oldisr + 2], ax

mov [es:21h * 4], myisr21		
mov [es:21h * 4], cs					;Hooked input

mov ah, 0
int 0x16								;Input interrupt stores value in al

cmp al, 100
int 21h

cmp al, 116
int 21h

cmp al, 113
je exit

jmp start

exit:

mov ax, 0x4c00
int 0x21