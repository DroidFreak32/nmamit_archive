;ROLLING MESSAGE TO DISPLAY UDUPI IN & SEGMENT
PA equ 40a0h
PB equ pa+1
PC equ pb+1
PCW equ pc+1
CW equ 80h
DATA segment
    SSMSG db 0ffh,0ffh,0ffh,0ffh,0c1h,0c0h,0c1h,8ch,0f9h,0ffh,0ffh,0ffh
DATA ends
CODE SEGMENT
ASSUME CS:CODE,DS:DATA
START: 
    MOV AX,DATA
    MOV DS,AX
    MOV AL,CW
    MOV DX,PCW
    OUT DX,AL
GO:
    LEA SI,SSMSG
    MOV cx,09h
UP:
    CALL SSDISPLAY
    CALL DELAY
    PUSH ax
    MOV ah,01h
    INT 16h
    JNZ exit
    POP ax
    INC SI
    DEC cx
    JNZ UP
    MOV ah,01h
    INT 16h
    JZ go
EXIT:
    MOV AH,4CH
    INT 21H
SSDISPLAY PROC NEAR
    PUSH CX
    MOV CX,4
    MOV DI,SI
UP2:
    MOV BL,8
    MOV AL,[DI]
UP1:
    ROL AL,1
    MOV DX,PB
    OUT DX,AL
    PUSH AX
    MOV AL,1
    MOV DX,PC
    OUT DX,AL
    MOV AL,0
    MOV DX,PC
    OUT DX,AL
    POP AX
    DEC BL
    JNZ UP1
    INC DI
    LOOP UP2
    POP CX
    RET
SSDISPLAY ENDP
DELAY PROC NEAR
    PUSH CX
    PUSH BX
    MOV CX,0fFFfH
L1:
    MOV BX,0FFFH
L2:
    DEC BX
    JNZ L2
    LOOP L1
    POP BX
    POP CX
    RET
DELAY ENDP
CODE ENDS
END START
