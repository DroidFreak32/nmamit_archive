; Write ALP macros: 
; a) To read a character from the keyboard in the module (1) (different file).
; b) To display a character in module (2) (different file).
; c) Use the above two modules to read a string of characters from the keyboard terminated by the carriage return and print the string on the display in the next line.
READ MACRO
MOV AH,01H
INT 21H
ENDM
WRITE MACRO
MOV DL,AL
MOV AH,02H
INT 21H
ENDM
DATA SEGMENT
MSG DB 10,13,'ENTER A STRING',10,13,'$'
MSG2 DB 10,13,'ENTERED STRING IS:',10,13,'$'
STR DB 50 DUP(?)
DATA ENDS
CODE SEGMENT
ASSUME CS:CODE,DS:DATA
START: 
    MOV AX,DATA
    MOV DS,AX
    MOV CL,0
    LEA SI,STR
    LEA DX,MSG
    MOV AH,09H
    INT 21H
UP:
    READ
    MOV [SI],AL
    INC SI
    CMP AL,0DH
    JE DOWN
    INC CL
    CMP CL,50
    JNE UP
DOWN: 
    LEA SI,STR
    LEA DX,MSG2
    MOV AH,09H
    INT 21H
UP1:
    MOV AL,[SI]
    WRITE
    DEC CL
    INC SI
    CMP CL,0
    JNZ UP1
    MOV AH,4CH
    INT 21H
CODE ENDS
END START