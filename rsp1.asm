Data segment
	a db 10h
	b db 9h
	c db ?
Data ends
Code segment
Assume CS:Code,DS:Data
Start:
	Mov AX,Data
	Mov DS,AX
	Mov AL,a
	Mov BL,b
	add AL,bl
	mov c,AL
	mov AH,4Ch
	int 21h
Code ends
End Start
