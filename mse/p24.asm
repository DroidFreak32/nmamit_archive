; Scan an 8 x 3 keypad for key closure and simulate ADD and SUBTRACT operations as in a calculator.
PA EQU 40a0H
PB EQU PA+1
PC EQU PB+1
PCW EQU PC+1
CW EQU 90H
ASSUME CS:CODE,DS:DATA
DATA SEGMENT
    N1 DB ?
    N2 DB ?
    SUM DB ?
    msg1 DB 10,13,'Sum: $'
DATA ENDS
CODE SEGMENT
START:
    MOV AX,DATA
    MOV DS,AX
    MOV AL,CW
    MOV DX,PCW
    OUT DX,AL

    call keypress
    mov n1,cl
    mov cl,04
    shr n1,cl
    call keypress
    mov al,n1
    add al,cl
    mov n1,cl

    call keypress
    mov n2,cl
    mov cl,04
    shr n2,cl
    call keypress
    mov al,n2
    add al,cl
    mov n2,cl

    mov al,n1
    add al,n2
    mov sub.al
    lea dx,msg1
    mov ah,09H
    int 21H
    
    mov bl,sum  
    call DISPHEXA
    mov ah,4ch
    int 21h

KEYPRESS PROC NEAR
UP:
    MOV AL,01H                      ; PASS CURRENT TO 1ST ROW
    MOV DX,PC
    OUT DX,AL
    MOV DX,PA
    IN AL,DX
    CMP AL,00H
    JNZ FIRSTROW                    ; if any bit set in AL then some char pressed in 1st row
    MOV AL,02H
    MOV DX,PC
    OUT DX,AL
    MOV DX,PA
    IN AL,DX
    CMP AL,00H
    JNZ SECONDROW
    MOV AL,04H
    MOV DX,PC
    OUT DX,AL
    MOV DX,PA
    IN AL,DX
    CMP AL,00H
    JNZ THIRDROW
    JMP UP                          ; Scan till keypress
FIRSTROW: 
    CALL DELAY
    MOV BL,01                       ; ROW
    MOV BH,01                       ; COL
    MOV CL,00                       ; VALUE
UP1:
    ROR AL,1
    JC LAST
    INC BH
    INC CL
    JMP UP1
SECONDROW:
    CALL DELAY
    MOV BL,2
    MOV BH,1
    MOV CL,8
UP2:
    ROR AL,1
    JC LAST
    INC BH
    INC CL
    JMP UP2
THIRDROW:
    CALL DELAY
    MOV BL,3
    MOV BH,1
    MOV CL,10H                      ; 16 in decimal
UP3:
    ROR AL,1
    JC LAST
    INC BH
    INC CL
    JMP UP3
LAST:
    RET
KEYPRESS ENDP
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