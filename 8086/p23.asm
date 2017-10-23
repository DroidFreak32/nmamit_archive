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
mov ax,1 ; store factorial
mov bl,n 
mov bh,00 
call factorial 
mov fact,ax 
mov bl, ah 
lea dx,msg 
mov ah,09h 
int 21h 
call disphexa 
mov bx,fact 
call disphexa 
mov ah,4ch 
int 21h 
factorial proc 
cmp bx,1 ;base condition
je l1 
push bx 
dec bx 
call factorial 
pop bx 
mul bx 
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
