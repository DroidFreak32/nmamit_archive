; String compare
DATA SEGMENT
    STR1 DB 20 DUP(?)
    STR2 DB 20 DUP(?)
    LEN1 DB ?
    LEN2 DB ?
    mg1 db 10,13,'Enter string1',10,13,"$"
    mg2 db 10,13,'Enter string2',10,13,"$"
    mg3 db 10,13,'Equal$'
    mg4 db 10,13,'Not Equal$'
    mg5 db 10,13,'Length of str1: $'
    mg6 db 10,13,'Length of str2: $'
DATA ENDS
CODE SEGMENT
ASSUME CS:CODE,DS:DATA
START:
    mov ax,DATA
    mov ds,ax
    lea dx,mg1
    mov ah,09h
    int 21h
    LEA si,STR1                     ; Point SI to 0th index of STR1
    CALL READSTR                    ; This func will store the string and it's length in CL
    mov LEN1,Cl                     ; Store the length in LEN1
    lea dx,mg2
    mov ah,09h
    int 21h
    MOV CL,00                       ; Now CL is used to store STR2's length
    LEA si,STR2                     ; Point SI to 0th index of STR2
    CALL READSTR                    ; This func will store the string and it's length in CL
    mov LEN2,Cl                     ; Store the length in LEN2
    CMP CL,LEN1
    JNZ NOTEQ                       ; If lengths dont match, they are not Equal.
    LEA SI,STR1
    LEA DI,STR2                     ; Reset registers to point to 0th of both strings
    MOV CL,00                       ; Reset CL for comparison

; Loop to compare each char of STR1 and STR2
UP1:
    CMP CL,len1                     ; Check if all characs in STR1 match with STR2
    JZ EQUAL                        ; If len(str1)==len(str2) it's Equal !
    MOV AL,[SI]
    CMP AL,[DI]
    JNZ NOTEQ                       ; If any one char doesnt match, not Equal.
    INC DI
    INC CL                          ; Increment count after each char is Matched
    INC SI
    JMP UP1
NOTEQ:
    LEA DX,mg4
    MOV AH,09h
    INT 21h
    JMP DISPLEN                        ; To prevent EQUAL's message to be displayed
EQUAL:
    LEA DX,mg3
    MOV AH,09h
    INT 21h
DISPLEN:
    LEA DX,mg5
    MOV AH,09h
    INT 21h
    MOV BL,len1
    CALL HX2ASCII
    LEA DX,mg6
    MOV AH,09h
    INT 21h
    MOV BL,len2
    CALL HX2ASCII
EXIT:
    MOV AH,4CH
    INT 21h
; ReadSTR procedure
READSTR PROC NEAR
    MOV CL,00
; Loop to read and store all chars into STR1
BACK:
    MOV AH,01H                      ; Instr to read a char from KB
    INT 21h
    CMP AL,0DH                      ; ODH is the HexASCII equivalent of "Enter" key (End of string)
    JZ RETURN                       ; If enter is pressed, return to the main()
    MOV [SI],AL                     ; Store the read char into the location in SI.
    INC SI
    INC CL
    JMP BACK
RETURN:
    RET
READSTR ENDP
; HEX2ASCII procedure
HX2ASCII PROC NEAR
    MOV DL,BL                       ;START Display hexa to ASCII procedure, HEX value is MID position number.
    MOV CL,04H
    SHR DL,CL
    CMP dl,09H
    JBE l1
    ADD DL,09H
L1:
    ADD DL,30H
    MOV AH,02H
    INT 21H
    MOV DL,BL
    AND DL,0FH
    CMP DL,09H
    JBE L2
    ADD DL,07H

L2:
    ADD DL,30H
    MOV AH,02H
    INT 21H
    RET
HX2ASCII ENDP
CODE ENDS
END START