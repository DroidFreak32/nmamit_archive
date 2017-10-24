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
       MOV DX,PCW
       OUT DX,AL
       MOV BL,n        ;anticlockwise
       MOV AX,3311h
       MOV DX,PA
       OUT DX,AL
       CALL DELAY
    UP1:ROL AL,01
       XCHG AL,AH
       OUT DX,AL
       CALL DELAY
       ROL AL,01
       XCHG AL,AH
       OUT DX,AL
       CALL DELAY
       DEC BL
       JNZ UP1
       MOV AH,4ch
       INT 21h
DELAY PROC NEAR 
PUSH BX 
MOV CX,3FFFH 
THERE: 
MOV BX,00FFH 
HERE: 
DEC BX 
JNZ HERE 
LOOP THERE 
POP BX 
RET 
DELAY ENDP 
CODE ENDS 
END START 
