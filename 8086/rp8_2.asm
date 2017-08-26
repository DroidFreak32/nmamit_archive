; Binary Search
; LOW , HUGH USE DL, DH
; ADDRESS BX,SI,DI


DATA SEGMENT
ARR DW 1234H,2345H,3456H,4567H,5678H
LEN DB $-ARR                              ;Address of last location-first=length
KEY DW 5478H
MID DB ?
FOUND DB 10,13,"FOUND AT POSITION $"
NOTFOUND DB 10,13,"NOTFOUND $"
DATA ENDS
CODE SEGMENT
ASSUME CS:CODE,DS:DATA
START:
	MOV AX,DATA
	MOV DS,AX
	MOV CL,0
	SHR LEN,01							;16 bit -> NO of addrs will be 2x. So divide by 2
	DEC LEN								;5 elements, but index starts from 0
	MOV DL,00							;LOW
	MOV DH,LEN							;HIGH
	MOV BX,0000H						;Remove existing value
UP:
	CMP DL,DH							;	if(low>high)
	JG NOTFO 							; 		print "Not found"
	MOV BL,DL   						;bl - Low 
	ADD BL,DH   						;bl=L+H
	SHR BL,01   						;bl=l+h/2
	MOV MID,BL 							;mid=^^^^

; The value of mid is NOT pointing to the exact middle element of the array's address. 
; It just stores l+h/2, (the Position of the MID element)
; The real address of the "MID" element is found by multiplying the value of mid by 2, done in the next step
; In case of 8 bit elements, MID will automatically point to both the position and the address of "MID" element
; 
	MOV AL,02H
	MUL BL 								;Muliply by 2 to get exact address of MID
	MOV BX,AX							;Store multiplied value to BX
	MOV AX,KEY
	CMP AX,ARR[BX]						; if (KEY==A[mid]), display message
	JE FO
	JG SECHALF							;else if (key<a(mid)) , go to sechalf
	DEC MID 							;else --mid
	MOV DH,MID 							; high = mid-1
	JMP UP								;Repeat the loop
SECHALF:
	INC MID 							;mid++
	MOV DL,MID 							;l=mid+1
	JMP UP								;repeat loop
FO:
	LEA DX,FOUND
	MOV AH,09H
	INT 21H
	INC mid
	MOV DL,MID 				;START Display hexa to ASCII procedure, HEX value is MID position number
	MOV CL,04H
	SHR DL,CL
	CMP dl,09H
	JBE l1
	ADD DL,09H
L1:
	ADD DL,30H
	MOV AH,02H
	INT 21H
	MOV DL,MID
	AND DL,0FH
	CMP DL,09H
	JBE L2
	ADD DL,07H

L2:
	ADD DL,30H
	MOV AH,02H
	INT 21H
	JMP EXIT 			;STOP display to hexa

NOTFO:
	LEA DX,NOTFOUND
	MOV AH,09H
	INT 21H
EXIT:
	MOV AH,4CH
	INT 21H
CODE ENDS
END START
