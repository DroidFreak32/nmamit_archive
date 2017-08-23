;Reading a character from KeyBoard
;01H has built in instructions to read char from KB. And stores in AL.
;02H has built in instructions to Display char to screen.
CODE SEGMENT
ASSUME CS:CODE
START:  MOV AH,01H
	INT 21H ; Performs the 01H instr.
	MOV DL,AL
	MOV AH,02H
	INT 21H
	MOV AH,4CH
	INT 21H
CODE ENDS
END START