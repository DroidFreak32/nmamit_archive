;ALP program to input BCD coordinates and display the specified location
; INPUT IS ALWAYS 2 DIGIT!!!!!!!!!!!!!!!!!!!!!!!
CLRSCR MACRO
    MOV AH,00
    MOV AL,02
    INT 10H
ENDM

SETCURSOR MACRO R,C
    MOV DH,R
    MOV DL,C
    MOV BH,00H
    MOV AH,02H
    INT 10H
ENDM

DATA SEGMENT
    BCD_X DB ?
    BCD_Y DB ?
    BIN_X DB ?
    BIN_Y DB ?
    msg1 DB 'ENTER THE X CO-ORDINATE: $'
    msg2 DB 10,13,'ENTER THE Y CO-ORDINATE: $'
DATA ENDS

CODE SEGMENT
ASSUME CS:CODE,DS:DATA
START:
    MOV AX,DATA
    MOV DS,AX
    LEA DX,msg1
    MOV AH,09H
    INT 21H
    CALL READBCD
    MOV BCD_X,BL
    LEA DX,msg2
    MOV AH,09H
    INT 21H
    CALL READBCD
    MOV BCD_Y,BL


    MOV BL,BCD_X
    CALL BCD_TO_BIN
    MOV BIN_X,BL

    MOV BL,BCD_Y
    CALL BCD_TO_BIN
    MOV BIN_Y,BL


    CLRSCR
    SETCURSOR BIN_Y,BIN_X
    MOV AH,01H
    INT 21H
    MOV AH,4CH
    INT 21H

READBCD PROC NEAR                           ; Procedure to input 1st char, immediately store in MSB, read 2nd char, mask to store in LSB
    MOV AH,01H
    INT 21H
    MOV BL, AL
    MOV CL,04H
    SHL BL,CL
    MOV AH,01H
    INT 21H
    AND AL,0FH
    ADD BL,AL
    RET
READBCD ENDP                                ; Proper "15" stored in BL (00010101) 

BCD_TO_BIN PROC NEAR                        ; Converts "15" (decimal) to 0FH (Hex)
    MOV DH,BL
    AND DH,0FH
    MOV AL, BL
    MOV CL,04H
    SHR AL,CL
    MOV DL,0AH
    MUL DL
    ADD AL, DH
    MOV BL, AL
    RET
BCD_TO_BIN ENDP
CODE ENDS
END START