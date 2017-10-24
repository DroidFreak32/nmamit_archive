PA equ 40A0h
PB equ PA+1
PC equ PB+1
PCW equ PC+1
CW equ 80h
DATA SEGMENT
n db 50
DATA ENDS
CODE SEGMENT
ASSUME CS:CODE,DS:DATA
START:
       MOV AX,DATA
       MOV DS,AX
       MOV AL,CW
       MOV DX,PCW                       ;both
       OUT DX,AL
       MOV BL,n
       MOV AX,9911h
       MOV DX,PA
       OUT DX,AL
       CALL DELAY
    UP1:ROR AL,01
       XCHG AL,AH
       OUT DX,AL
       CALL DELAY
       ROR AL,01
       XCHG AL,AH
       OUT DX,AL
       CALL DELAY
       DEC BL
       JNZ UP1
   

       MOV BL,n
       MOV AX,3311h
       MOV DX,PA
       OUT DX,AL
       CALL DELAY
    UP2:ROL AL,01
        XCHG AL,AH
        OUT DX,AL
        CALL DELAY
        ROL AL,01
        XCHG AL,AH
        OUT DX,AL
        CALL DELAY
        DEC BL
        JNZ UP2
        MOV AH,4ch
        INT 21h
        DELAY PROC
        PUSH BX
        PUSH AX
        PUSH CX
        MOV CX,3FFFh
     LA:MOV BX,0FFFh
     LB:DEC BX
        JNZ LB
        LOOP LA
        POP CX
        POP AX
        POP BX
        RET
        DELAY ENDP
        CODE ENDS
        END START
