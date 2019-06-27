[org 0x0100]



mov ax, [arr1]
add ax, [arr2]
mov [arr3], ax

mov ax, [arr1 +2]
add ax, [arr2 +2]
mov [arr3 +2], ax

mov ax, [arr1 +4]
add ax, [arr2 +4]
mov [arr3 +4], ax

mov ax, [arr1 +6]
add ax, [arr2 +6]
mov [arr3 +6], ax

mov ax, [arr1 +8]
add ax, [arr2 +8]
mov [arr3 +8], ax

mov ax, [arr1 +10]
add ax, [arr2 +10]
mov [arr3 +10], ax

mov ax, [arr1 +12]
add ax, [arr2 +12]
mov [arr3 +12], ax

mov ax, [arr1 +14]
add ax, [arr2 +14]
mov [arr3 +14], ax

mov ax, [arr1 +16]
add ax, [arr2 +16]
mov [arr3 +16], ax

mov ax, [arr1 +18]
add ax, [arr2 +18]
mov [arr3 +18], ax

mov ax, 0x4c00
int 0x21

arr1 : dw 101, 200, 500, 320, 550, 632, 400, 100 ,200, 900
arr2 : dw 50, 99, 256, 230, 550, 600, 220, 100, 200, 300
arr3 : dw 0