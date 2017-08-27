; Palindrome
DATA SEGMENT
	STR1 DB 20 DUP(?)
	STR2 DB 20 DUP(?)
	LEN DB ?
	mg1 db 10,13,'Enter a string',10,13,"$"
	mg2 db 10,13,'Palindrome$'
	mg3 db 10,13,'Not Palindrome$'
DATA ENDS
CODE SEGMENT
ASSUME CS:CODE,DS:DATA
START:
	mov ax,DATA
	mov ds,ax
	lea dx,mg1
	mov ah,09h
	int 21h
	LEA si,STR1						; Point SI to 0th index of STR1
	LEA di,STR2						; Point DI to 0th index of STR2
	CALL READSTR					; This func will store the string and it's length in DS
	mov len,Cl 						; Store the lenhtn in len
	dec SI 							; SI is out of bounds, so bring it back
	MOV CL,00 						; Now CL is used to store STR2's length
; Loop to Copy values in STR1 backwards into STR2
UP1:
	CMP CL,len 						; Check if all characs in STR1 are copied into STR2
	JZ CHECKPAL 					; If len(str1)==len(str2) go to checkPal()
	MOV AL,[SI]
	MOV [DI],AL 					; Last char of SI is First of DI
	INC DI
	INC CL 							; Increment count after each char is copied
	DEC SI
	JMP UP1
CHECKPAL:
	LEA SI,STR1
	LEA DI,STR2
	MOV CL,00
; Loop to compare each char of STR1 and STR2
UP2:
	CMP CL,len 						; Check if all characs in STR1 match with STR2
	JZ SUCC 	 					; If len(str1)==len(str2) it's a Palindrome !
	MOV AL,[SI]
	CMP AL,[DI]
	JNZ FAILURE 					; If any one char doesnt match, not a Palindrome.
	INC DI
	INC CL 							; Increment count after each char is Matched
	INC SI
	JMP UP2
FAILURE:
	LEA DX,mg3
	MOV AH,09h
	INT 21h
	JMP EXIT 						; To prevent SUCC()'s "Palindrome" message to be displayed
SUCC:
	LEA DX,mg2
	MOV AH,09h
	INT 21h
EXIT:
	MOV AH,4CH
	INT 21h
; ReadSTR procedure
READSTR PROC NEAR
	MOV CL,00
; Loop to read and store all chars into STR1
BACK:
	MOV AH,01H 						; Instr to read a char from KB
	INT 21h
	CMP AL,0DH 						; ODH is the HexASCII equivalent of "Enter" key (End of string)
	JZ RETURN 						; If enter is pressed, return to the main()
	MOV [SI],AL 					; Store the read char into the location in SI.
	INC SI
	INC CL
	JMP BACK
RETURN:RET
READSTR ENDP
CODE ENDS
END START