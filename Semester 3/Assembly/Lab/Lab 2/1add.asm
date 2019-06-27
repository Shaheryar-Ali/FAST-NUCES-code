;Program to add first 10 numbers of Fibonacci series
[ORG 0x0100]

MOV BX, 0		;SETS FIRST VARIABLE REG TO 0
MOV CX, 1		;SETS FIRST VARIABLE REG TO 1
MOV DX, 0		;fOR STORING PREVIOUS VALUE OF BX
MOV AX, CX		;MOVES VALUE OF BH in AX
ADD AX, BX		;STORES SUM OF FIRST 2 NUMBERS

MOV DX, BX		;TEMP VAR
MOV BX, CX		;
ADD CX, DX		;Getting third number of seq
ADD AX, CX		;Sum till third term

MOV DX, BX		;TEMP VAR
MOV BX, CX		;
ADD CX, DX		;Getting third number of seq
ADD AX, CX		;Sum till third term


MOV DX, BX		;TEMP VAR
MOV BX, CX		;
ADD CX, DX		;Getting third number of seq
ADD AX, CX		;Sum till third term


MOV DX, BX		;TEMP VAR
MOV BX, CX		;
ADD CX, DX		;Getting third number of seq
ADD AX, CX		;Sum till third term


MOV DX, BX		;TEMP VAR
MOV BX, CX		;
ADD CX, DX		;Getting third number of seq
ADD AX, CX		;Sum till third term


MOV DX, BX		;TEMP VAR
MOV BX, CX		;
ADD CX, DX		;Getting third number of seq
ADD AX, CX		;Sum till third term


MOV DX, BX		;TEMP VAR
MOV BX, CX		;
ADD CX, DX		;Getting third number of seq
ADD AX, CX		;Sum till third term


MOV DX, BX		;TEMP VAR
MOV BX, CX		;
ADD CX, DX		;Getting third number of seq
ADD AX, CX		;Sum till third term

MOV AX, 0X4C00
INT 0X21
