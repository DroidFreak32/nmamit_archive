data segment
f1 db 00h
f2 db 01h
f3 db ?
n db 10h


data ends

code segment
assume cs:code,ds:data
start:
      mov ax,data
      mov ds,ax
      
      mov bl,f1
      call disphexa
      mov dl,' '
      mov ah,02h
      int 21h
      mov cl,00
      sub n,02h
      up:
          cmp cl,n
          jz exit
          mov al,f1
          add al,f2
          mov f3,al
          mov bl,f3
          call disphexa
          mov dl,' '
          mov ah,02h
          int 21h
          mov al,f2
          mov f1,al
          mov al,f3
          mov f2,al
          inc cl
          jmp up
      exit:
          mov ah,4ch
          int 21h
         disphexa proc near
         push cx
         push dx
         mov dl,bl
         mov cl,04h
         shr dl,cl
         cmp dl,09h
         jbe l1
         add dl,07h
       l1:
          add dl,30h
          mov ah,02h
          int 21h
          mov dl,bl
          and dl,0fh
          cmp dl,09h
          jbe l2
          add dl,07h
       l2:
          add dl,30h
          mov dh,02h
          int 21h
          pop dx
          pop cx
        ret
        disphexa endp
code ends
end start
