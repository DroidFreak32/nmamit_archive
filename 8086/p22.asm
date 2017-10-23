include clrscr.mac
include dspchr.mac
include rdchr.mac
include stcur.mac
;ALP program to display name at specified location along with a message "What is your name?" and also clear the screen before the display.
DATA SEGMENT
   MSG1 DB 10,13,'ENTER YOUR NAME: $',10,13,'$'
   msg2 db 'what is your name?? $'
   n db ?
   str db 30 dup(?)
DATA ENDS
CODE SEGMENT
ASSUME CS:CODE,DS:DATA
START:
	mov ax,data
	mov ds,ax

	lea dx,msg1
	mov ah,09h
	int 21h

	lea si,str
	call READSTRING
	mov n,cl
	clrscr
	mov ah,02h
	int 21h
	setcursor 10,30
	lea dx,msg2
	mov ah,09h
	int 21h
	lea si,str
	mov cl,n
	call DISPSTRING
	mov ah,01h
	int 21h
	mov ah,4ch
	int 21h
READSTRING proc near
      mov cl,00h
      UP:
         mov ah,01h
         int 21h
         cmp al,0dh
         jz L1
         mov [si],al
         inc si
         inc cl
         jmp up
      L1:
      ret
      READSTRING endp
DISPSTRING proc near
      UP2:
         cmp cl,00
         jz L2
         mov dl,[si]
         dispchar
         inc si
         dec cl
         jmp UP2
      L2:
            ret
         DISPSTRING endp
code ends
end start





























    READSTRING PROC NEAR
      MOV CL,00H
    UP:
       MOV AH,01H
       INT 21H
       CMP AL,00H
       JZ L1
       MOV [SI],AL
       INC SI
       INC CL
       JMP UP
    L1:
        RET
        READSTRING ENDP