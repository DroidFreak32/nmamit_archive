DATA SEGMENT
ARR DB 10H,34H,35H,22H,45H
LEN DB $-ARR
KEY DB 38H
SUCC DB 10,13,"FOUND$"
NOTSUCC DB 10,13,"NOTFOUND$"
DATA ENDS

CODE SEGMENT
ASSUME CS:CODE,DS:DATA
START:
      MOV AX,DATA
      MOV DS,AX
      MOV CL,0
      LEA SI,ARR  ;Load start of arr
      L1:
         CMP CL,LEN
         JZ NOTFOUND
         MOV AL,[SI]
         CMP KEY,AL
         JZ FOUND
         INC SI
         INC CL
         JMP L1
      FOUND:
         LEA DX,SUCC
         MOV AH,09H
         INT 21H
         JMP EXIT
      NOTFOUND:
         LEA DX,NOTSUCC
         MOV AH,09H
         INT 21H
      EXIT:
         MOV AH,4CH
         INT 21H
 CODE ENDS
 END START

