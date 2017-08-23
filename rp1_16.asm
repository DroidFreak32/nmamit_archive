Data segment
 a dw 1234h ; dw as its 16 bit
 b dw 5678h
 c dw ?
Data ends
Code segment
 Assume CS:Code,DS:Data
 Start:Mov AX,Data
       Mov DS,AX
       Mov AX,a   ;aX cuz 16 bit
       add AX,b
       mov c,AX
       mov AH,4Ch ;4ch terminates the program
       int 21h ; reads the instructions located in 4ch
     Code ends
  End Start
