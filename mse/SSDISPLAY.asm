SSDISPLAY proc near
	PUSH cx		;Commonizing
	MOV di,si	;Reqd for other progs
	MOV cx,04	;Tracks the no. of chars displayed
UP2:
	mov bl,08
	MOV al,[di]	;copy 1st value of DL to AL for OUTing to 7 seg
UP1:
	rol al,01	;To send bits 1 at a time
	MOV dx,pb	;Port B is the output
	OUT dx,al	;send value of AL to port B
	PUSH ax		;Backup AX
; Now to perform -ve edge trigger  to display
	MOV al,01
	MOV dx,pc
	OUT dx,al	;01 to..
	MOV al,00
	OUT dx,al	;00 high to low = -ve trigger
	POP ax		;restore old value
	DEC BL		;8-1 
	JNZ up1		;Repeat until BL = 0 (No more bits left of the current character)
	INC DI		;Point to 2nd char
	DEC cx		; 3 more chars to dislay
	JNZ up2		; If there's a char, rotate its 8 bits again
	POP cx		;commonizing
	RET
SSDISPLAY endp
