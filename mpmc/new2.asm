.8087
.model small
.stack 512
.data
	x	dd ?
	y	dd ?
	dsc	dd ?
	a	dd 1.0
	b	dd 5.0
	c	dd 6.0
	four	dd 4.0
.code
start:
	mov ax,@data
	mov ds,ax
	
	finit
	fld b
	fmul st,st
	fld a
	fld c
	fmul
	fld four
	fmul
	fsub
	fsqrt
	fst dsc
	
	finit
	
	mov ax,4c00h
	int 21h
end start