PA EQU 40A0H
PB EQU PA+1
PC EQU PB+1
CW EQU 82H
PCW EQU PC+1


CODE SEGMENT
ASSUME CS:CODE
START: MOV AL,CW
       MOV DX,PCW
       OUT DX,AL

       MOV AL,01
       MOV DX,PA

       RING: OUT DX,AL
             CALL DELAY
             PUSH AX
             MOV AH,01H
             INT 16H
             JNZ EXIT
             POP AX

             ROR AL,01
             JMP RING
    EXIT:MOV AH,4CH
        INT 21H

    DELAY PROC NEAR
    PUSH AX
    PUSH BX
    PUSH CX
    MOV CX,0FFFH
    L1: MOV BX,0FFFH
    L2:DEC BX
       JNZ L2
       LOOP L1
       POP CX
       POP BX
       POP AX
       RET
       DELAY ENDP
  CODE ENDS
 END START

