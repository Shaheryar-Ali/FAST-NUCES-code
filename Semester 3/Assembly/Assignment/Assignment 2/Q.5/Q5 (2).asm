;Program to find transpose of two arrays

[org 0x0100]
	
	mov cx, [row]
	mov dx, [col]
	mov bp, 0					;for address of transpose array
	
	 mov si, 0		; for current col
	 mov di, 0		; for current row
	 
	 outer:
		mov bx, si							;for incrementing column. we are using row in inner loop bcz it helps in transpose.
		inner:
			mov al,[matrix + bx]			;read value from matrix
			mov [trans + bp], al			;transfer it for transpose
			add bp, 1						;increments for next input in transpose
			
			add bx, dx						;increments to next row but same column of original. For this we add the column no
			
			add di, 1						;to show increment of row
			
			cmp di, cx						
			jne inner
		add si, 1							;to increment to row
		mov di, 0
		cmp si, dx
		jne outer
		
	
	mov ax, 0x4c00
	int 0x21

	
	matrix: db 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 ,16
	trans: db 0
	row: dw 4
	col: dw 4