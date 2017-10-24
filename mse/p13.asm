;Program to implement odd/even parity and count no of 1's

pa equ 40a0h
pb equ pa+1
pc equ pb+1
cwr equ pc+1
cw equ 82h

code segment
assume cs:code
start:
    mov dx,cwr              ;Initializing control word
    mov al,cw               ; of 8255
    out dx,al

    mov dx,pb               ;read port B, input
    in al,dx

    mov bl,al
    mov cl,00h              ; Count of NO. of 1s
    mov ch,08h              ; For 8 bits

l1:     
    rol bl,01h              ;reads 8 bits
    jnc down                ; If no carry is generated, it means the bit rotated left (LSB) is 0 (NO LED) . So dont inc 1's count
    inc cl

down:
    dec ch                  ; 7th bit
    cmp ch,00h              ; Id CH > 0 , All leds aren't scanned
    ja l1                   ; So repeat the loop till all 8 bits are scanned

; CHECK FOR O/E PARITY
    mov ch,cl               ; Store NO of 1s in CH (We'll need CL later display the NO of 1s)

    shr ch,01h              ; In BINARY, If it ends with 0, it's ODD else it's EVEN
    jnc evenp
; Odd parity if Carry is generated
    mov al,00h              ; If odd, show 00
    jmp display

evenp:
    mov al,0ffh             ;output stored in al

display:
    mov dx,pa               ;output moved to port A
    out dx,al

    mov ah,01h
    int 21h                 ;waits till a key is pressed

    mov al,cl               ;Count of 1's moved to al and displayed in PA
    out dx,al

    mov ah,4ch
    int 21h
code ends
end start


