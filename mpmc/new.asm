.8086
.model small
.stack 512
.data
	x db "Hello Viren!$"
.code
start:
	mov ax,@data
	mov ds,ax
	
	lea dx,x
	mov ax,0900h
	int 21h
	
	mov ax,0100h
	int 21h
	
	mov ax,4c00h
	int 21h
	
end start