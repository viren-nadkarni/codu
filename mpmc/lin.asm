;linear search
.8086
.model small
.stack 512
.data
	array dw 55h,33h,44h,66h,22h
	len dw 5
	scrkey equ 33h
	asc1 equ (scrkey/10h)+'0'
	asc2 equ (scrkey mod 10h)+'0'
	sucmsg db 'element ',asc1,asc2,' found at position: ','$'
	result db ?,0ch,0ah,'$'
	failmsg db 'element',asc1,asc2,'not found','$'
.code
lin:
	mov ax,@data
	mov ds,ax
	
	mov es,ax
	cld
	mov di,0
	mov al,scrkey
	mov cx,len
	repne scasb
	jz success
	lea dx,failmsg
	jmp disp
success:
	mov bx,di
	add bl,'0'
	mov result,bl
	lea dx,sucmsg
disp:
	mov ah,09h
	int 21h
	mov ah,4ch
	int 21h
end lin



