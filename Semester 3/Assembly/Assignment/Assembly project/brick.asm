[org 0x100]
jmp start

dirX: dw 0  
dirY: dw 0

data: dw 'o'
oldisr: dd 0 
oldisr1:dd 0
space1: dw ' '
position: dw 0x1507
message: db '             ' ; string to be printed

lenght1: dw 18 

lives:	dw 3

tick:dw 0

;variable for timer tick
tickTime:dw 0

counterBrick: dw 0
lifeHeart: dw 3

barposition: dw 0

xposition: dw 0

ballposition: dw 0

level1: dw	0x6020, 0x5020, 0x4020, 0x3020, 0x2020, 0x1020, 0x6020, 0x5020, 0x4020, 0x3020, 0x2020, 0x1020, 0x6020, 0x5020, 0x4020, 0x3020, 0x2020, 0x1020, 0x6020,  0x5020, 0x4020, 0x3020, 0x2020, 0x1020, 0x6020, 0x5020, 0x4020, 0x3020, 0x2020, 0x1020, 0x6020, 0x5020, 0x4020, 0x3020, 0x2020, 0x1020, 0x6020, 0x5020, 0x4020,  0x3020,0
;Stores level1 blocks
size1: 	dw 	40
;Total no of blocks in lv 1

rightBar: 	dw	1
leftBar:	dw	1
;These variables determine movement of ball

start1: 	dw	0
;Variable that indicates if the game has started or not. When 1 it starts the timer

clock:	dw	0 
;For storing clock of the level

score:	dw	0
;For storing score

ball:	dw	0
;For storing current location of ball

bar:	dw	0
;For storing bar

;vedio memory pointer
pointer: dw 0

;variable for mintues and seconds
mintues: dw 49
seconds: dw 59
messageScore:db 'Score:',0

;Variable for storing if stage is complete or not

level1_comp: dw 0
time_end: dw 0
rightpress: dw 0
leftpress: dw 0

col_check: dw 0

printnum11: 
 push bp
 mov bp, sp
 push es
 push ax
 push bx
 push cx
 push dx
 push di
 mov ax, 0xb800
 mov es, ax ; point es to video base
 mov ax, [bp+4] ; load number in ax
 mov bx, 10 ; use base 10 for division
 mov cx, 0 ; initialize count of digits
nextdigit11: mov dx, 0 ; zero upper half of dividend
 div bx ; divide by 10
 add dl, 0x30 ; convert digit into ascii value
 push dx ; save ascii value on stack
 inc cx ; increment count of values
 cmp ax, 0 ; is the quotient zero
 jnz nextdigit11 ; if no divide it again
 mov di, 0 ; point di to top left column
mov di,3880

nextpos22: 
 
 
 pop dx ; remove a digit from the stack
 mov dh, 0x07 ; use normal attribute
 mov [es:di], dx ; print char on screen
 add di, 2 ; move to next screen location
 loop nextpos22 ; repeat for all digits on stack
 pop di
 pop dx
 pop cx
 pop bx
 pop ax
 pop es
 pop bp
 ret 2

Scoreprinting:
   push ax
   push es
   push si
   push bx
   push cx
   mov di,0 
   mov ax,0xb800
   mov es,ax
   mov si,3868
   mov ah,0x07
   mov cx,0
 printingstart:  
   mov byte al,[cs:messageScore+di]
   mov [es:si],ax
   add  cx,1
   add di,1
   add si,2
   cmp cx,6
   jne printingstart
   
   pop cx
   pop bx
   pop si
   pop es
   pop ax
   ret


LifePrint:
  
   
   push ax
   push es
   push di  
   push cx
 movHere:
   
   mov ax,0xb800
   mov es,ax
   mov cx,3
   mov ax,0x0720
   mov di,3988
   
clearit:
   mov [es:di],ax
   add di,4
   dec cx
   cmp cx,0
   jne clearit
    mov word[cs:start1],0
	mov word[cs:position],0x1507
	mov word[cs:barposition],0     
	mov word ax, [cs:barposition]
	 push ax ; push x position
	 mov ax, 22
	 push ax ; push y position
	 mov ax, 1 ; blue on black attribute
	 push ax ; push attribute
	 mov ax, message
	 push ax ; push address of message
	 push word [cs:lenght1] ; push message length
	call clrscr1
	call printbar ; call the printstr subroutine

   cmp word[cs:lives],0
   jne movforward
   mov word[cs:lives],0xFFFF
   jmp backmov

movforward:
   
   mov ah,0x04   
   mov al,[cs:lifeHeart]
   
   mov cx,[cs:lives]
   mov di,3988
   
lifeprint:
    mov [es:di],ax
    add di,4
    sub cx,1
    cmp cx,0
    jne lifeprint
    dec word[cs:lives]
backmov:
   
   pop cx
   pop di
   pop es
   pop ax
   ret
  
  

;time printing
printTime:
     mov word[cs:tickTime],0
     cmp word[cs:start1],1
     jne Ending1
     mov al,[cs:mintues] 
     cmp byte al,47
     jne remainSame
     mov word[cs:seconds],0
     inc word[cs:mintues]
     call movForward
     mov word[cs:mintues],47 
     jmp Ending

remainSame:
     dec word[cs:seconds] 

    cmp word[cs:seconds],0
    jne movForward       
    mov al,[cs:mintues] 
   cmp byte al,48
   jne further
   dec word[cs:mintues]
   jmp Ending 
further:
     
  dec word[cs:mintues]
   jmp movForward
Ending1:
  jmp Ending
movForward:
    
 push bp
 mov bp, sp
 push es
 push ax
 push bx
 push cx
 push dx
 push di
 mov ax, 0xb800
 mov es, ax ; point es to video base
 mov ax,[cs:seconds] ; load number in ax

 mov bx, 10 ; use base 10 for division
 mov cx, 0 ; initialize count of digits
nextdigit: 
 
 mov dx, 0 ; zero upper half of dividend
 div bx ; divide by 10
 add dl, 0x30 ; convert digit into ascii value
 push dx ; save ascii value on stack
 inc cx ; increment count of values
 cmp ax, 0 ; is the quotient zero
 jnz nextdigit ; if no divide it again
 mov di,3846
 mov ah,0x07
 mov al,':'
 mov [es:di-2],ax
 mov al,[cs:mintues] 
 mov [es:di-4],ax
 
 

  mov word[es:di],0x0720
  add di,2   
  mov word[es:di],0x0720
  mov di,3846
nextpos: 
 pop dx ; remove a digit from the stack
 mov dh, 0x07 ; use normal attribute
 mov [es:di], dx ; print char on screen
 add di, 2 ; move to next screen location
 loop nextpos ; repeat for all digits on stack

cmp word[cs:seconds],0
jne functionEnd

mov word[cs:seconds],59

functionEnd:
 pop di
 pop dx
 pop cx
 pop bx
 pop ax
 pop es
 pop bp
Ending:
 ret 
 


collision:
	push ax
	push bx
	push cx
	push dx
	push es
	
	mov bh, 0
	mov dx, [cs:position],
	mov ah, 2
	int 10
	
	cmp byte[cs:position+1],21
	jne  notbarcol
	
	mov bh, 0
	mov dx, [cs:position]
	add dh, 1
	
	
	mov ah, 2
	int 0x10
	
	mov ah, 0x08
	int 0x10
	cmp ah, 0x00
	je exit_collision33			
	
	mov ax, 0x0001
	xor [cs:dirY], ax
	
	cmp word[cs:rightpress],1
	jne nopress_right
	mov word[cs:dirX],1
nopress_right:
     cmp word[cs:leftpress],1
     jne exit_collision33
     mov word[cs:dirX],0	 
	
	
	

exit_collision33:	
	
	
	
	jmp exit_collision
	
	
	notbarcol:
	cmp byte[cs:position+1],22
	je exit_collision100
	
	mov bh, 0
	mov dx, [cs:position]
	jmp contiueit
exit_collision100:
     jmp exit_collision1	
contiueit:	
	cmp word[cs:dirY], 1
	jne cursor_set12
	sub dh, 1
	jmp cursor_set13
	cursor_set12:
	add dh, 1
	cursor_set13:
	
	cmp word[cs:dirX], 1
	jne cursor_set32
	add dl, 1
	jmp cursor_set33
	cursor_set32:
	sub dl, 1
	cursor_set33:
	
	mov ah, 2
	int 0x10
	
	mov ah, 0x08
	mov bh, 0
	int 0x10
	cmp ah, 0x00
	je exit_collision200		
	
	mov word [cs:col_check], 1
	
	add word [cs:score] , 10				;Adding score
	push word[cs:score]
	call printnum11
	mov ax, dx
	and ax, 0x00ff
	mov bl, 10
	div bl
	mov ah, 0
	mul bl
	mov dl, al
	jmp continue12
exit_collision200:
   jmp exit_collision	
continue12:	

	
	mov bh, 0
	mov ah, 2
	int 0x10

	inc word[cs:counterBrick]
	
	mov al, 0x20
	mov bh, 0
	mov bl, 0
	mov cx, 10
	mov ah, 9
	int 0x10

 
	jmp pointing
exit_collision1:
       jmp exit_collision1_1	
pointing:	
	cmp byte[cs:position+1],0
	je exit_collision
	mov ax, 0x0001
	xor [cs:dirY], ax
	jmp exit_collision  

	mov dx, [cs:position]
	
	cmp word[cs:dirX], 1
	jne cursor_set72
	add dl, 1
	jmp cursor_set73
	cursor_set72:
	sub dl, 1
	cursor_set73:
	
	mov bh, 0
	mov ah, 2
	int 0x10
	
	mov ah, 8
	int 0x10
	
	cmp ah, 0
	je exit_collision1_1
	mov ax, 0x0001
	xor [cs:dirX], ax

	
	
	
	
exit_collision1_1:
   cmp word[cs:lives],0xFFFF
je exit_collision
       call LifePrint
	
	
	
exit_collision:

        pop es
	pop dx
	pop cx
	pop bx
	pop ax
	ret
	
blackcol:

 push ax
 push bx
 push es
 push bp
 mov ah, 0x13
 mov al, 2 ; subservice 01 – update cursor
 mov bh, 0 ; output on page 0
 mov bl, 7 ; normal attrib
 mov dx,[cs:position] ; row 10 column 3
 mov cx, 1 ; length of string
 push cs
 pop es ; segment of string
 mov bp, space1 ; offset of string
 int 0x10 ; call BIOS video service
 pop bp
 pop es
 pop bx
 pop ax
 ret

startprint:

 push ax
 push bx
 push es
 push bp
 mov ah, 0x13
 mov al, 1 ; subservice 01 – update cursor
 mov bh, 0 ; output on page 0
 mov bl, 7 ; normal attrib
 mov dx,[cs:position] 
 mov cx, 1 ; length of string
 push cs
 pop es ; segment of string
 mov bp, data ; offset of string
 int 0x10 ; call BIOS video service
 pop bp
 pop es
 pop bx
 pop ax
 ret



clrscr:
push es
push ax
push cx
push di

mov ax, 0xb800
mov es, ax
xor di, di
mov ax, 0x0020
mov cx, 2000

cld
rep stosw

pop di
pop cx
pop ax
pop es
ret

clrscr1:
push es
push ax
push cx
push di

mov ax, 0xb800
mov es, ax
xor di, di
mov ax, 0x0020
mov cx,100
mov di,3500
cld
rep stosw

pop di
pop cx
pop ax
pop es
ret



kbisr: 

	 push ax
	 push es
	 mov ax, 0xb800
	 mov es, ax ; point es to video memory
	 
	 in al, 0x60 ; read a char from keyboard port
	 cmp al, 0x4D ; is the key right key is pressed
 
	 jne nextcmp ; no, try next comparison
	  mov word[cs:rightpress],1
	 call startprint  
	 mov word ax,[cs:barposition]
	 add ax,60	
	 cmp word ax,122 
	 je lable2
	 mov word ax, [cs:barposition]
	 add word[cs:barposition],2
	 add ax,2
	 push ax ; push x position
	 mov ax, 22
	 push ax ; push y position
	 mov ax, 1 ; blue on black attribute
	 push ax ; push attribute
	 mov ax, message
	 push ax ; push address of message
	 push word [cs:lenght1] ; push message length
	 
	 cmp word[cs:start1],1
	 je  GameStart
	 call blackcol
	 add byte[cs:position],2
	 call startprint
GameStart:	 
	 call clrscr1
	 call printbar ; call the printstr subroutine

lable2:	
	 jmp nomatch ; leave interrupt routine
	
	nextcmp: 
    cmp al, 0x4B ; is the key left shift
	jne nomatch ; no, leave interrupt routine
	 mov word[cs:leftpress],1
    
	 mov word ax, [cs:barposition]
	 cmp ax,0
	 jbe nomatch
	 cmp word[cs:start1],1
	 je GameStart1
	 call blackcol
	 sub byte[cs:position],2
	 call startprint

GameStart1:

	 sub word[cs:barposition],2
	 sub ax,2
	 push ax ; push x position
	 mov ax, 22
	 push ax ; push y position
	 mov ax, 1 ; blue on black attribute
	 push ax ; push attribute
	 mov ax, message
	 push ax ; push address of message
	 push word [cs:lenght1] ; push message length
	 call clrscr1
	 call printbar ; call the printstr subroutine
   
nomatch:
   cmp al,0xcb
   jne nextcmpare7
    mov word[cs:leftpress],0
	
nextcmpare7:
      cmp al,0xcd
	  jne nomatch111
      mov word[cs:rightpress],0
nomatch111:

 pop es
 pop ax
 jmp far [cs:oldisr] 
 

printbar: 
	 push bp
	 mov bp, sp
	 push es
	 push ax
	 push cx
	 push si
	 push di
	 
	 mov ax, 0xb800
	 mov es, ax ; point es to video base
	 
	 mov al, 80 ; load al with columns per row
	 mul byte [bp+10] ; multiply with y position
	 add ax, [bp+12] ; add x position
	 shl ax, 1 ; turn into byte offset
	 mov di,ax ; point di to required location
	 mov si, [bp+6] ; point si to string
	 
	 mov cx, [bp+4] ; load length of string in cx
	 mov ah, [bp+8] ; load attribute in ah
	
	nextchar: 
	 
	 mov ax,0x1020
	 mov word[es:di], ax ; show this char on screen
	 add di, 2 ; move to next screen location
	 loop nextchar ; repeat the operation cx times
	 pop di
	 pop si
	 pop cx
	 pop ax
	 pop es
	 pop bp
	 ret 10

print_blocklv1:
push bp
push ax
push bx
push cx
push dx
push di
push si
push ds
push es

mov ax, 0xb800						;Loads video memory
mov es, ax
xor di, di

mov si, level1					;Moves level 1 address in si
mov cx, 0							;For storing current block in memory

cld									;Sets direction flag  to one
	print1_out:
	cmp cx, [size1]
	jae exit_print_blocklv1
	mov ax, cx						;Temporary var for helping us go to required printing position
	push cx
	mov cx, 20
	mul cx
	mov di, ax
	mov cx, 10
	lodsw
	repne stosw						;prints the string 10 times
	
	pop cx
	inc cx
	jmp print1_out
	exit_print_blocklv1:

	pop es
	pop ds
	pop si
	pop di
	pop dx
	pop cx
	pop bx
	pop ax
	pop bp
	ret
	


timer: 
  
 push ax
 push es
 mov ax, 0xb800
 inc word[cs:tick]
 inc word[cs:tickTime]
  cmp word[cs:tickTime],18
jne nextCmp1
   call printTime
nextCmp1:
  cmp word[cs:tick],1
  jne nomatch3
 mov word[cs:tick],0


 cmp word[cs:start1],0
 je nomatch3
 jmp cmparision
 nomatch3:
    jmp nomatchend
cmparision: 
call collision
cmp word[cs:col_check], 1
 je nomatchend
 call blackcol
 
 cmp word[cs:dirX],1
 jne incMovX
 inc byte[cs:position]
 jmp movY
 incMovX:
     dec byte[cs:position]
 movY:
 cmp word[cs:dirY],1
 jne decMov
 dec byte[cs:position+1]
 jmp nextCompare
 decMov:
     inc byte[cs:position+1]
	

   
 
 nextCompare:
       cmp byte[cs:position+1],0				;0 indicates down, 1 indicates up
	   jne nextCompare1
	   mov word[cs:dirY],0
nextCompare1:
         cmp byte[cs:position+1],22
		 jne nextCompare2
         mov word[cs:dirY],1			
nextCompare2:
         cmp byte[cs:position],78
		 jne nextCompare3
		 mov word[cs:dirX],0
nextCompare3:
          cmp byte[cs:position],0				;0 indicates left, 1 indicates right
		  jne nextCompare4
		  mov word[cs:dirX],1
nextCompare4:
   call startprint
	
				 
 nomatchend: 
 mov word[cs:col_check], 0
 pop es
 pop ax
 jmp far [cs:oldisr] ; call the original ISR
 

start:
	call clrscr
call Scoreprinting	
        call LifePrint

        mov word ax, [cs:barposition]
	 push ax ; push x position
	 mov ax, 22
	 push ax ; push y position
	 mov ax, 1 ; blue on black attribute
	 push ax ; push attribute
	 mov ax, message
	 push ax ; push address of message
	 push word [cs:lenght1] ; push message length
	
	call printbar ; call the printstr subroutine
        call print_blocklv1

	 mov cx, 0x2607
	 mov ah, 1
	 int 0x10
	 
	xor ax, ax
	mov es, ax ; point es to IVT base
	mov ax, [es:9*4]
	mov [cs:oldisr], ax ; save offset of old routine
	mov ax, [es:9*4+2]
	mov [cs:oldisr+2], ax ; save segment of old routine
 

 
	xor ax, ax
	mov es, ax ; point es to IVT base
	mov ax, [es:8*4]
	mov [oldisr1], ax ; save offset of old routine
	mov ax, [es:8*4+2]
	mov [oldisr1+2], ax ; save segment of old routine
 
 
 cli ; disable interrupts

	mov word [es:9*4], kbisr ; store offset at n*4
	mov [es:9*4+2], cs ; store segment at n*4+2
    mov word [es:8*4], timer ; store offset at n*4
    mov [es:8*4+2], cs ; store segment at n*4+2
 
 sti 
 


 l1: 
 
	mov ah, 0 ; service 0 – get keystroke
	int 0x16 ; call BIOS keyboard service
	cmp word[cs:counterBrick],40
    jae exitmain	
	cmp word [cs:lives], 0xFFFF
	je exitmain
	cmp al,0x20
        jne anotherCheck
        mov word[cs:start1],1   
 
anotherCheck:            
        cmp al, 27 ; is the Esc key presseda
         
 jne l1 ; if no, check for next key
 
exitmain:
    cmp word[cs:seconds], 0
	je exit_for_real
	cmp word[cs:counterBrick], 40
	jb exit_for_real
	add word[cs:score], 50
	push word[cs:score]
	call printnum11
	;Add routine to print score
	mov ax,0
	mov es,ax
	mov cx,[oldisr1]
	mov dx,[oldisr1+2]
	mov ax,[oldisr]
	mov bx,[oldisr+2]
	cli
	 mov [es:9*4],ax
	 mov [es:9*4+2],bx
	 mov [es:8*4],cx
	 mov [es:8*4+2],dx
	sti
	
exit_for_real:
	
mov ax, 0x4c00
int 0x21