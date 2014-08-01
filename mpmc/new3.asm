.8086
.model small
.stack 512
.data
	msg0	db "Enter first number: ",'$'
	msg1	db "Enter second number: ",'$'
	msg2	db "Sum: ",'$'
	msg3	db "Difference: ",'$'
	msg4	db "Product: ",'$'
	msg5	db "Quotient: ",'$'
	a		dw ?
	b		dw ?
	tmp		dw ?
.code
	extrn readsint:near, writesint:near
start:
	mov ax,@data
	mov ds,ax
	
	lea dx,msg0
	mov ax,0900h
	int 21h
	
	call readsint
	mov a,ax
	
	lea dx,msg1
	mov ax,0900h
	int 21h
	
	call readsint
	mov b,ax
	
	
	; ; ; ; ; ; ; ; ;
	
	add ax,a
	mov tmp,ax
	
	lea dx,msg2
	mov ax,0900h
	int 21h
	
	mov ax,tmp
	call writesint
	
	; ; ; ; ; ; ; ; ;
	
	lea dx,msg3
	mov ax,0900h
	int 21h
	
	mov ax,a
	sub ax,b
		
	call writesint
		
	; ; ; ; ; ; ; ; ;
	
	lea dx,msg4
	mov ax,0900h
	int 21h
	
	mov ax,a
	mul ax,b
		
	call writesint
	
	; ; ; ; ; ; ; ; ;
	
	; ; ; ; ; ; ; ; ;
	
	mov ax,0100h
	int 21h
	
	mov ax,4c00h
	int 21h
end start