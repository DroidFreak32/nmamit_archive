; System time
DATA SEGMENT
MSG1 DB 10,13,'SYSTEM TIME IS $'
HR DB ?
MIN DB ?
SEC DB ?
HSEC DB ?
DATA ENDS

CODE SEGMENT
ASSUME CS:CODE,DS:DATA
START:
    MOV AX,DATA
    MOV DS,AX
    LEA DX,MSG1
    MOV AH,09H
    INT 21H
    MOV AH,2CH
    INT 21H
    MOV HR,CH
    MOV MIN,CL
    MOV SEC,DH
    MOV HSEC,DL

    MOV AL,HR
    AAM                                 ; If hour is 15, AL = 0Fh. AAM makes AL=01 and AH=05
    MOV BX,AX
    CALL DISPUNPACKEDBCD
    MOV DL,':'
    MOV AH,02H
    INT 21H

    MOV AL,MIN
    AAM
    MOV BX,AX
    CALL DISPUNPACKEDBCD
    MOV DL,':'
    MOV AH,02H
    INT 21H

    MOV AL,SEC
    AAM
    MOV BX,AX
    CALL DISPUNPACKEDBCD
    MOV DL,':'
    MOV AH,02H
    INT 21H

    MOV AL,HSEC
    AAM
    MOV BX,AX
    CALL DISPUNPACKEDBCD

    MOV AH,4CH
    INT 21H

DISPUNPACKEDBCD PROC NEAR
    MOV DL,BH                           ; First display 1
    ADD DL,30H                          ; To get equiv ASCII of 1
    MOV AH,02H
    INT 21H

    MOV DL,BL                           ; Then display 5
    ADD DL,30H
    MOV AH,02H
    INT 21H
    RET
DISPUNPACKEDBCD ENDP
CODE ENDS
END START
