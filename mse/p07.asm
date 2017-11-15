; Display name
CLRSCR MACRO
MOV AH, 00H
MOV AL, 02H
INT 10H
ENDM

SETCURSOR MACRO row, col
MOV DH, row 
MOV DL, col
MOV BH, 00H
MOV AH, 02H
INT 10H
ENDM

DATA SEGMENT
msg1 DB 'ENTER YOUR NAME:$'
msg2 DB 'What is your name?$'
str DB 30 dup(?)
n DB ?
DATA ENDS

CODE SEGMENT
ASSUME CS:CODE,DS:DATA
START:
    MOV AX,DATA
    MOV DS,AX
    LEA DX,msg1
    MOV AH,09H
    INT 21H
    LEA SI, str
    CALL READSTRING
    MOV n,CL
    CLRSCR
    MOV AH, 02H
    SETCURSOR 10,30
    LEA DX,msg2
    MOV AH,09H
    INT 21H
    LEA SI, str
    MOV CL, n
    CALL DISPSTRING
    MOV AH,01H
    INT 21H
    MOV AH,4CH
    INT 21H
READSTRING PROC NEAR
    MOV CL, 00H
UP:
    CMP CL,30
    JZ L1
    MOV AH,01H
    INT 21H
    CMP AL,0DH
    JZ L1
    MOV [SI],AL
    INC SI
    INC CL
    JMP UP
L1:
    RET
READSTRING ENDP

DISPSTRING PROC NEAR
UP1:
    CMP CL,00H
    JZ L2
    MOV DL,[SI]
    MOV AH,02H
    INT 21H
    INC SI
    DEC CL
    JMP UP1
L2:
    RET
DISPSTRING ENDP
CODE ENDS
END START