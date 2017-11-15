; Program to implement upcounter
CLRSCR MACRO 
MOV AH, 00H 
MOV AL, 02H
INT 10H 
ENDM 
SETCURSOR MACRO row,col
    MOV DH, row 
    MOV DL, col
    MOV BH, 00H
    MOV AH, 02H
    INT 10H
ENDM
CODE SEGMENT 
ASSUME CS:CODE 
START:
    CLRSCR 
    MOV AL,00H 
UP:
    CMP AL,99H                          ; Disp 99 at the end
    JZ DISP99
    PUSH AX
    SETCURSOR 12,39                     ; Cursor at the CENTER
    POP AX
    MOV BL,AL
    CALL DISPHEXA
    CALL DELAY
    ADD AL, 01H                         ; Cant use INC as DAA will not work then
    DAA
    JMP UP
DISP99: 
    PUSH AX
    SETCURSOR 39,12
    POP AX
    MOV BL, AL 
    CALL DISPHEXA
    CALL DELAY 
    MOV AH, 4CH 
    INT 21H

DISPHEXA PROC NEAR
    PUSH AX
    MOV DL, BL
    MOV CL,04
    SHR DL, CL
    CMP DL,09
    JBE DOWN1
    ADD DL,07
DOWN1:
    ADD DL,30H
    MOV AH,02H
    INT 21H
    MOV DL, BL
    AND DL,0FH
    CMP DL,09H
    JBE DOWN2
    ADD DL,07H
DOWN2:
    ADD DL,30H
    MOV AH,02H
    INT 21H
    POP AX
    RET
DISPHEXA ENDP

DELAY PROC
    PUSH BX
    MOV CX,0300H
L1:
    MOV BX,01FFH
L2:
    DEC BX
    JNZ L2
    LOOP L1
    POP BX
    RET
    DELAY ENDP
CODE ENDS
END START
