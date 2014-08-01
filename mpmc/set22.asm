.8086
.model small
.stack 512
.data
	crlf	db 13,10,'$'
	x		dw 10
.code
start:
	mov ax,@data
	mov ds,ax

readchar macro
	mov ah,01h
	int 21h
endm

writechar macro 
	;char to be moved to dl
	mov ax,0200h
	int 21h
endm

	readchar

	mov ah, 00h
loophere:
	mov dx,10
	div x

	;al <-- ax/10
	;ah <-- ax % 10

	push ax

	; convert dl to ascii
	mov dl,ah
	add dl,'0'
	
	writechar
	
	; now restore eax
	pop ax
	mov ah,00h
	; if ax is zero, we can quit
	cmp ax, 0
	jnz loophere
	
	
	mov ah,4ch
	int 21h
end start


