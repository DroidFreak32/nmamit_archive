; Factorial
data segment 
n db 05h 
fact dw ?
msg db 'factorial(6)=$' 
data ends 

code segment 
assume cs:code,ds:data 
start: 
mov ax,data 
mov ds,ax 
lea dx,msg 
mov ah,09h 
int 21h 

mov ax,1 						; store factorial
mov bl,n
mov bh,00 						; Remove junk 
call factorial 
mov fact,ax
mov bl, ah 						; Display MSB
call disphexa 
mov ax,fact 					; Restore the value of fact in AX 
mov bl,al 						; Display LSB
call disphexa 
mov ah,4ch 
int 21h 
factorial proc 
	cmp bx,1 					;base condition
	je l1 
	push bx 
	dec bx 
	call factorial 				; Pushes 6,5,4,3,2,1 to stack
	pop bx 						; pops 1,2,3,4,5,6
	mul bx 						; Multiply prev popped & mul'd to current popped. 1*1 > 1*2 > 2*3 > 6*4 until X*6 and store in AX
	l1: 
	ret 
factorial endp

disphexa proc
mov dl,bl
mov cl,04
shr dl,cl
cmp dl,09h
jbe l2
add dl,07h
l2:
add dl,30h
mov ah,02h
int 21h
mov dl,bl
and dl,0fh
cmp dl,09h
jbe l3
add dl,07h
l3:
add dl,30h
mov ah,02h
int 21h
ret
disphexa endp
code ends
end start
