Data segment
	a dw 10e3h
	b dw 103eh
	c dw ?
Data ends
Code segment
Assume CS:Code,DS:Data
Start:
	Mov AX,Data
	Mov DS,AX
	Mov AX,a
	SUB AX,b
	mov c,AX
	mov AH,4Ch
	int 21h
Code ends
End Start
