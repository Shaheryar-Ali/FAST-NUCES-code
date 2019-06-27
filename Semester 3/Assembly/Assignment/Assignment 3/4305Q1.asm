;Program for displaying date
[org 0x0100]

mov ax, 0				;For storing result
mov bx, [Day]			;This register will be used to perform all shifting tasks
shl bx, 11				; uses 5 bits
add ax, bx

mov bx, [Month]			;For month
shl bx, 7				;uses 4
add ax, bx

mov bx, [Year]			;for year
add ax, bx				;uses remaining seven

mov ax, 0x4c00
int 0x21

Month:	dw	7
Day:	dw	20
Year:	dw	88