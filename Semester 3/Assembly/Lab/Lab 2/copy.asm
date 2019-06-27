;Program for copy
[ORG 0x0100]

MOV AX, 0x2CA1	;Randomly assigns value
MOV BX, 0	;
OR BX,AX	;

MOV AX, 0X4c00	;
INT 0x21	;