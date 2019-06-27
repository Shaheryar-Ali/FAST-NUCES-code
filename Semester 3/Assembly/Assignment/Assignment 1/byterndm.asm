[org 0x0100]


mov ax, [startingbit]	;move 83 to ax
mov bl, 8		;move 8 (byte)
div bl			;div 83/8   al=10, ah=3
mov bx, ax		;bx =ax
mov dl, bh		;remainder into dl
mov bh, 0		;bh= 0, to make BX= quotient
mov ax, [random+bx]	;move two bytes from bit 80 to ax
mov dh, [random+bx+2]	;move 1 byte from bit 96 to dh


loop1:			
shl dh, 1		;shift byte starting from 96
rcl ax,1		;rotate through carry into ax
dec dl			;do it till remainder (i.e 3 times in this case)
jnz loop1


mov ax, 0x4c00
int 21h

startingbit: dw 83

random: dd 3, 0xE, 4, 2, 5, 9, 0xD, 1