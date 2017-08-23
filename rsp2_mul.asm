Data segment
 a db 2h
 b db 2h
 c db ?
Data ends
Code segment
Assume CS:Code,DS:Data
Start:
	Mov AX,Data
	Mov DS,AX
	Mov AL,a
	MUL b ; it implicitly takes AX
	MOV c,AL
	mov AH,4Ch
	int 21h
Code ends
End Start
