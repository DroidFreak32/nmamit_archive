Data segment
	a dw 1234h
	b dw 5678h
	c dw ?
	d dw ?
Data ends
Code segment
Assume CS:Code,DS:Data
Start:
	Mov AX,Data
	Mov DS,AX
	Mov AX,a
	MUL b 		; it implicitly takes AX
	MOV d,DX 	; 1st 16 bit of the 32 bit ans in c
	MOV c,AX 	; 2nd 16 bit of the 32 bit ans in c
;	MOV c+2,DX can also be written like this
	mov AH,4Ch
	int 21h
Code ends
End Start
