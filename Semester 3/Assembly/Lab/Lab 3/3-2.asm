[org 0x0100]


mov bx, arr1
mov ax, [bx]
mov si, arr2
add ax, [si]
mov di, arr3
mov [di], ax

mov ax, [bx +2]
add ax, [si +2]
mov [di +2], ax

mov ax, [bx +4]
add ax, [si +4]
mov [di +4], ax

mov ax, [bx +6]
add ax, [si +6]
mov [di +6], ax

mov ax, [bx +8]
add ax, [si +8]
mov [di +8], ax

mov ax, [bx +10]
add ax, [si +10]
mov [di +10], ax

mov ax, [bx +12]
add ax, [si +12]
mov [di +12], ax

mov ax, [bx +14]
add ax, [si +14]
mov [di +14], ax

mov ax, [bx +16]
add ax, [si +16]
mov [di +16], ax

mov ax, [bx +18]
add ax, [si +18]
mov [di +18], ax

mov ax, 0x4c00
int 0x21

arr1 : dw 101, 200, 500, 320, 550, 632, 400, 100 ,200, 900
arr2 : dw 50, 99, 256, 230, 550, 600, 220, 100, 200, 300
arr3 : dw 0