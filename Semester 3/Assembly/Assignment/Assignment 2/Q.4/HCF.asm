;program to calculate hcf
[org 0x0100]
	
	mov al, [numl]
	mov ah, [numh]
	
	cmp ah, al				;Here ah is suppose to be larger
	jg noswap				;In case no swapping is required
		mov ch, al			;Next three lines for swapping
		mov al, ah
		mov ah, ch

noswap:
	
	mov cl, 0
	
fact:
	add cl, 1
	cmp cl,al
	jg done
	mov dh, ah
	mov dl, al
	
	
	div1:
		
		sub dh,cl
		cmp dh,cl			;comparing if dh is larger, if true then subtract cl otherwise skip to div 2
		jge div1

	div2:
		
		sub dl,cl
		cmp dl,cl			;comparing if dh is larger, if true then subtract cl otherwise skip to div 2
		jge div2
		

		cmp dh, 0
		jne fact
		
		cmp dl, 0
		jne fact
		
			mov [hcf], cl
			cmp cl, al
			jl fact 
			
done:	
	;mov ch, 0			;to prevent executing  below statement
	mov ax,0x4c00
	int 0x21
	
numl:	db  18
numh:	db	24
hcf:	db	0