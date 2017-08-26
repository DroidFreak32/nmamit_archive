;10 - line feed (enters new line)  
;13 -  carriage return (cursur at the start of next line)
; $ end of statement
;
;LEA - Load Effective Address
;09h print in screen WHATEVER WAS LOADED IN DX by LEA
;01H has built in instructions to read char from KB. And stores in AL.
;02H has built in instructions to Display char to screen.

DATA SEGMENT
	msg1 db 10,13,'Enter a character',10,13,'$'
	msg2 db 10,13,'Entered  character is',10,13,'$'
	char db ?
DATA ENDS

CODE SEGMENT
ASSUME CS:CODE,DS:DATA
START:
	MOV AX,DATA
	MOV DS,AX
	LEA DX,MSG1
	MOV AH,09H
	INT 21H
	MOV AH,01H
	INT 21H
	MOV CHAR,AL
	LEA DX,MSG2
	MOV AH,09H
	INT 21H
	MOV DL,CHAR
	MOV AH,02H
	INT 21H
	MOV AH,4CH
	INT 21H
CODE ENDS
END START