[org 0x0100]
jmp start

compare:
push bp
mov bp, sp
mov bx, [bp + 6]
mov si, [bp + 4]
mov ax, [bx]
mov cx, [si]
cmp ax, cx
jne skip1					;In case msb of 1 is larger, the number automatically becomes larger so no need to compare lsb
mov ax,[bx+2]
mov cx,[si+2]
cmp ax, cx		;comparing lsb
skip1:

jnc skip_carry				;let carry remain unchanged if not 1
mov byte[carry_flag], 1		

skip_carry:

jnp sk_parity				;let parity remain unchanged if not 1
mov byte[parity_flag], 1

sk_parity:

jnz	skip_zero
mov byte[zero_flag], 1

skip_zero:

jno	over
mov byte[overflow_flag], 1

over:

jns sign
mov byte[signed_flag], 1

sign:

jl skip_aux					;In case num 1 is smaller, it will try to borrow carry thus aux will be 1
mov byte[auxiliary_flag], 1

skip_aux:

pop bp
ret 4


start:
mov bx, num1
mov si, num2
push bx
push si
call compare

mov ax, 0x4c00
int 0x21

; variables to store flag
carry_flag:		db	0
parity_flag:	db	0
auxiliary_flag:	db	0
zero_flag:		db	0
overflow_flag:	db	0
signed_flag:	db	0

num1:	dw	0x4251, 0x7685				;left to right is ms-byte to ls-byte i.e first is more significant
num2:	dw	0x4251,	0x1526