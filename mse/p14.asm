; up down counter.asm
pa equ 40a0h
pb equ pa+1
pc equ pb+1
pcw equ pc+1
cw equ 82h

code segment
assume cs:code
start:
	mov al,cw
	mov dx,pcw
	out dx,al

	mov al,00h
	mov dx,pa
up:
	cmp al,15h
	jz down
	out dx,al
	call delay

	push ax 				; Wait for keypress
	mov ah,01h
	int 16h
	jnz exit  				; Exit if key is pressed (if keypress, zero flag is unset)
	pop ax

	add al,01h 				; Daa will automatically change 0A to 10
	daa
	jmp up
down:
	cmp al,00h
	je exit
	out dx,al
	call delay

	push ax
	mov ah,01h
	int 16h
	jnz exit
	pop ax

	sub al,01
	das
	jmp down
exit:
	mov al,00h
	out dx,al
	mov ah,4ch
	int 21h

delay proc near
	push bx
	push cx
	mov cx,0ffaah
l1:
	mov bx,0ffaah
l2:
	dec bx
	jnz l2
	loop l1
	pop cx
	pop bx
	ret
delay endp
code ends
end start


