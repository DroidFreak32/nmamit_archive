;Program to display system time using 7 segment display.
PA equ 40a0h
PB equ pa+1
PC equ pb+1
PCW equ pc+1
CW equ 80h

DATA segment
	SSTABLE db 0c0h,0f9h,0a4h,0b0h,99h,92h,82h,0f8h,80h,90h ; REVERSE ORDER CUS NEW DEVICE
	SSCODE db 4 dup(?) 										; Codes of time digits
	HR db ?
	MIN db ?
	AINDEX db 4 dup(?) 										; To store the time digits
DATA ends

CODE segment
ASSUME cs:code, ds:data
START:
	MOV ax,data
	MOV ds,ax
	MOV al,cw
	MOV dx,pcw
	OUT dx,al

	MOV ah,2ch 												; Get sys time
	INT 21h
	MOV hr,ch
	MOV min,cl
	LEA si,aindex 											;Pointer to puth the values in array
	MOV al,hr
	AAM
	MOV [si],ah
	MOV [si+1],al
	MOV al,min
	AAM
	MOV [si+2],ah
	MOV [si+3],al
	MOV cx,04
	LEA si,aindex ;aindex is source
	LEA bx,SSTABLE ;for XLAT TO work, BX need to search in SSTABLE
	LEA di,SSCODE ;Storing in the destination
UP:
	MOV al,[si]
	XLAT ;Points AL to equivalent value in BX
	MOV [di],al ;whats returned by XLAT is now stored in DI (SSCODE)
	INC si
	INC di
	LOOP up ;Uses CX implicitly
	LEA si,SSCODE
	CALL ssdisplay
	MOV ah,4ch
	INT 21h
SSDISPLAY proc near
	PUSH cx
	MOV di,si
	MOV cx,04
UP2:
	mov bl,08
	MOV al,[di]
UP1:
	rol al,01
	MOV dx,pb
	OUT dx,al
	PUSH ax
	MOV al,01
	MOV dx,pc
	OUT dx,al
	MOV al,00
	OUT dx,al
	POP ax
	DEC BL
	JNZ up1
	INC DI
	DEC cx
	JNZ up2
	POP cx
RET
SSDISPLAY endp
CODE ends
END start