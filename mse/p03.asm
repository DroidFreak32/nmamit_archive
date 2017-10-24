; Bubbly sort!
DATA SEGMENT
	A DB 34H,00H,45H,10H,32H
	LEN DB $-A
	NL DB 10,13,'$'
	MSG DB 10,13,'Sorted $',10,13
DATA ENDS

CODE SEGMENT
ASSUME CS:CODE,DS:DATA
START:
	MOV AX,DATA
	MOV DS,AX
	MOV CL,00H 						; I=0
	MOV DL,LEN 						; first loop i=0 to n-1
	DEC DL 							; DL=n-1
LOOP1:
	CMP CL,DL 						; if i < n-1
	JZ DISPLAY
	MOV DH,DL 						; For loop 2 where j < n-i-1
	SUB DH,CL 						; dh = n-i-1
	MOV BX,0000H 					; j=0
LOOP2:
	CMP BL,DH 						; if j < n-i-1 , check if not sorted.
	JB IFCN
	INC CL 							; Else i++ and loop again.
	JMP LOOP1
IFCN:
	MOV AL,A[BX] 					; AL = a[j]
	MOV AH,A[BX+1] 					; AH = a[j+1]
	CMP AL,AH 						; If a[j]<a[j+1] , already sorted so skip to next ele.
	JBE NOSWP
	MOV A[BX],AH 					; SWAP
	MOV A[BX+1],AL 					
NOSWP:
	INC BX
	JMP LOOP2
DISPLAY:
	MOV BX,0000H
	LEA DX,MSG ;Display message
    MOV AH,09H
    INT 21H
BACK:
	MOV DL,A[BX]
	MOV CL,04H
	SHR DL,CL
	CMP DL,09H
	JBE L3
	ADD DL,07H
L3:
	ADD DL,30H
	MOV AH,02H
	INT 21H
	MOV DL,A[BX]
	AND DL,0FH
	CMP DL,09H
	JBE L4
	ADD DL,07H
L4:
	ADD DL,30H
	MOV AH,02H
	INT 21H
	LEA DX,NL
	MOV AH,09H
	INT 21H
	INC BX
	CMP BL,LEN
	JZ EXIT
	JMP BACK
EXIT:
	MOV AH,4CH
	INT 21H
CODE ENDS
END START

