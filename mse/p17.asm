;FIREHELP
PA EQU 40A0H 
PB EQU PA+1 
PC EQU PB+1 
PCW EQU PC+1 
CW EQU 80H 

DATA SEGMENT 
SSFIRE DB 8EH, 0F9H, 0AFH, 86H 
SSHELP DB 89H, 86H, 0C7H, 8CH
SSRING DB 8FH,0F9H,0ABH,90H
SSLOL DB 80h,0c0h,0c0h,80h
DATA ENDS 
CODE SEGMENT 
ASSUME CS:CODE,DS:DATA 
START: 
    MOV AX, DATA 
    MOV DS, AX 
    MOV AL,CW
    MOV DX,PCW 
    OUT DX,AL 
UP:
    LEA SI, SSFIRE 
    CALL SSDISPLAY 
    CALL DELAY 
    LEA SI,SSHELP 
    CALL SSDISPLAY 
    CALL DELAY
    LEA SI,SSLOL 
    CALL SSDISPLAY 
    CALL DELAY
    push ax
    MOV AH,01H 
    INT 16H 
    JZ UP

    MOV AH, 4CH 
    INT 21H 

SSDISPLAY PROC NEAR 
    PUSH CX 
    MOV CX,04                   ; tot num of slots in 7 seg
    MOV DI, SI 

UP2:
    MOV AL, [DI] 
    MOV BL, 08                  ; 8 Bits of 1 character to be sent to 7 segment
UP1:
    ROL AL, 01H 
    MOV DX, PB 
    OUT DX, AL                  ; Send the MSB
    PUSH AX 
    MOV DX, PC 
    MOV AL, 01H                 ; -ve trigger
    OUT DX, AL 
    MOV AL, 00H
    OUT DX, AL                  ; -ve trigger end
    POP AX 
    DEC BL
    JNZ UP1                     ; Repeat for 8 bits 
    INC DI                      ; Point to 2nd char
    LOOP UP2                    ; Repeat for next slot
    POP CX 
    RET 
SSDISPLAY ENDP 


DELAY PROC NEAR
    PUSH BX
    PUSH CX
    MOV CX,0FFFFH
L1:
    MOV BX,0FFFFH
L2:
    DEC BX
    JNZ L2
    LOOP L1
    POP CX
    POP BX
    RET
DELAY ENDP

CODE ENDS
END START
