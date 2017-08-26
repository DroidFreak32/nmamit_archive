Data segment
	a db 56h
	b db 12h
	c db ?
Data ends
Code segment
Assume CS:Code,DS:Data
Start:
	Mov AX,Data
	Mov DS,AX
	Mov AL,a
	MOV AH,00H		;to remove the junk value in AH
	div b
	MOV c,AL
	mov AH,4Ch
	int 21h
Code ends
End Start
