.8086
.model small
.stack 512
.data
	arr dw 100 dup(?)
	n	dw ?
	p1	db "No. of items: $"
	p2	db "Enter items: ",13,10,'$'
	p3	db "Items in reverse: ",13,10,'$'
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
	
	;;;
	
	lea dx,p3
	mov ax,0900h
	int 21h
	
	lea bp,arr
	mov cx,n
	sub si,2
wlp:
	mov ax,[bp][si]
	call writesint
	sub si,2
	
	loop wlp
		
	mov ax,4c00h
	int 21h
end start
	