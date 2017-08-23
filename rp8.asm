; Binary Search
DATA SEGMENT
ARR DW 1234H,2345H,3456H,4567H,5678H
LEN DB $-ARR ;
KEY DW 2345H
MID DB ?
FOUND DB 10,13,"FOUND$"
NOTFOUND DB 10,13,"NOTFOUND$"
DATA ENDS
CODE SEGMENT
ASSUME CS:CODE,DS:DATA
START:
      MOV AX,DATA
      MOV DS,AX
      MOV CL,0
      SHR LEN,01
      DEC LEN
      MOV DL,00   ;LOW
      MOV DH,LEN ;HIGH
      MOV BX,0000H
UP:
      CMP DL,DH
      JG NOTFO
      MOV BL,DL
      ADD BL,DH   ;L+H
      SHR BL,01
      MOV MID,BL
      MOV AL,02H
      MUL BL
      MOV BX,AX
      MOV AX,KEY
      CMP AX,ARR[BX]
      JE FO
      JG SECHALF
      DEC MID 
      MOV DH,MID
      JMP UP
SECHALF:
      INC MID
      MOV DL,MID
      JMP UP
FO:
      LEA DX,FOUND
      MOV AH,09H
      INT 21H
      JMP EXIT
NOTFO:
      LEA DX,NOTFOUND
      MOV AH,09H
      INT 21H
EXIT:
      MOV AH,4CH
      INT 21H
CODE ENDS
END START
