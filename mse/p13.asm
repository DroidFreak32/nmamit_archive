;Program to implement odd/even parity and count no of 1's

pa equ 40a0h
pb equ pa+1
pc equ pb+1
cwr equ pc+1
cw equ 82h

code segment
assume cs:code
start:
        mov dx,cwr      ;Initializing control word
        mov al,cw
        out dx,al

        mov dx,pb     ;read port B
        in al,dx

        mov bl,al
        mov cl,00h
        mov ch,08h

     l1:rol bl,01h     ;reads 8 bits
        jnc down
        inc cl

down:   dec ch
        cmp ch,00h
        ja l1

        mov ch,cl

        shr ch,01h
        jnc evenp

        mov al,00h
        jmp display

  evenp:mov al,0ffh     ;output stored in al

display:mov dx,pa       ;output moved to port A
        out dx,al

        mov ah,01h
        int 21h           ;waits till a key is pressed

        mov al,cl         ;Count of 1's moved to al
        out dx,al

        mov ah,4ch
        int 21h
code ends
end start


