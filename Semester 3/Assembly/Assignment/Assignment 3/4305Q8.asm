;Program for multiplying 64 bit number
[org 0x0100]

mov cl, 64

checkbit:
	mov dx, [multiplier]
	shr dx, 1
	mov dx, [multiplier + 2]
	rcr dx, 1
	mov dx, [multiplier + 4]
	rcr dx, 1
	mov dx, [multiplier + 6]
	rcr dx, 1
	jnc skip

addition:	
	mov ax, [multiplicand ]
	add [result], ax
	mov ax, [multiplicand + 2]
	adc [result + 2], ax
	mov ax, [multiplicand + 4]
	adc [result + 4], ax
	mov ax, [multiplicand + 6]
	adc [result + 6], ax
	mov ax, [multiplicand + 8]
	adc [result + 8], ax
	mov ax, [multiplicand + 10]
	adc [result + 10], ax
	mov ax, [multiplicand + 12]
	adc [result + 12], ax
	mov ax, [multiplicand + 14]
	adc [result + 14], ax
	
skip:
	shl word	[multiplicand ], 1
	rcl word	[multiplicand + 2], 1
	rcl word	[multiplicand + 4], 1
	rcl word	[multiplicand + 6], 1
	rcl word	[multiplicand + 8], 1
	rcl word	[multiplicand + 10], 1
	rcl word	[multiplicand + 12], 1
	rcl word	[multiplicand + 14], 1
	
	dec cl
	jnz checkbit
	
mov ax, 4c00
int 0x21



multiplicand:	dw 0xf330, 0xc5c2, 0x4251, 0xc8c8 , 0, 0, 0, 0		;extra 4 bit to prevent addition in case memory already has some value, order of byte is lsb to msb
multiplier:		dw 0x746e, 0xb293, 0x9a00, 0x2209 
result:			dw 0, 0, 0, 0, 0, 0, 0, 0