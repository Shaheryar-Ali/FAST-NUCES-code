;Program to calculate exponent without multiplication
[org 0x0100]
	mov cx, [y]			;for outer loop
	mov dx, [x]			;for inner loop

					
	mov bx, dx	
	
ol:						; outside loop
	cmp cx, 1
	je outsi
	mov ax, 0
	
	il:					;label for inner loop
		add ax, bx
		sub dx, 1		; counter increments
		jnz il			; repeats loop until false
		
	mov bx, ax 		;For next inner loop
	mov dx, [x]		
	sub cx, 1		;Increments outer loop
	jmp ol
	
outsi:
	mov word [res], bx
	
	mov ax, 0x4c00
	int 0x21
	
x : dw 5
y : dw 3
res : dw 0