;copy values from one array to another
DATA SEGMENT
	AR1 DB 12H,13H,14H,15H,16H
	LEN DB $-AR1
	AR2 DB 5 DUP(?)	;initializes an empty array of 5 bytes
DATA ENDS
CODE SEGMENT
ASSUME CS:CODE,DS:DATA
START:
	MOV AX,DATA
	MOV DS,AX
	LEA SI,AR1	;load start address of arr1 in SI
	LEA DI,AR2	;load start address of arr1 in SI
	MOV CX,LEN	;Initialize counter with length of array
BACK:
	MOV AL,[SI] ;load the value in address of SI to AL
	MOV [DI],AL	;store the value of AL in address pointed by DI (start of arr2)
	INC SI		;arr1 ++
	INC DI		;arr2 ++
	LOOP BACK	;Loop. (Implicitly stops looping when SI has no value?)
	MOV AH,4CH
	INT 21H
CODE ENDS
END START
