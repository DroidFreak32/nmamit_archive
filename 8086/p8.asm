Data segment
	a dw 5678h
	b dw 1234h
	c dw ?
Data ends
Code segment
Assume CS:Code,DS:Data
Start:
	Mov AX,Data
	Mov DS,AX
	Mov AX,a
	div b
	MOV c,AX
	mov AH,4Ch
	int 21h
Code ends
End Start
