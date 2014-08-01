.8086
.model small
.stack 512
.data
	arr dw 100 dup(?)
	n	dw ?
	p1	db "No. of items: $"
	p2	db "Enter items: ",13,10,'$'
	p3	db "Highest: $"
	p4	db "Lowest: $"
	
	h 	dw ?
	l	dw ?
.code
	extrn readsint:near, writesint:near
start:
	mov ax,@data
	mov ds,ax
		
	lea dx,p1
	mov ax,0900h
	int 21h
	
	call readsint
	mov n,ax
		
	lea dx,p2
	mov ax,0900h
	int 21h
	
	mov cx,n
	mov si,0
	lea bp,arr
readlp:
	call readsint
	mov [bp][si],ax
	add si,2
	
	loop readlp
	
	; ; ; ; ;
	
	lea bp,arr	
	mov si,0
	mov ax,[bp][si]
	mov bx,[bp][si]
	mov cx,n
		
loop2:
	cmp ax,[bp][si]
	je nxtiter
	jl nxtcmp
	mov ax,[bp][si]
nxtcmp:
	cmp bx,[bp][si]
	jge nxtiter
	mov bx,[bp][si]
	
nxtiter:
	add si,2
	loop loop2
	
	mov h,ax
	mov l,bx
	
	lea dx,p3
	mov ax,0900h
	int 21h
	
	mov ax,l
	call writesint
	
	lea dx,p4
	mov ax,0900h
	int 21h

	mov ax,h
	call writesint
	
	mov ah,4ch
	int 21h
end start