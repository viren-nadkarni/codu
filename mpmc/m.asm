.8086
.model small
.stack 512
.data
	n		dw ?
	tmp		dw ?
	arr		dw 64 dup(?)
	msg1	db 13,10,"How many items? $"
	msg2	db 13,10,"Enter items: ",13,10,'$'
	msg3	db 13,10,"Missing item: $"
	msg4	db 13,10,"No missing item ",13,10,'$'
	
.code
	extrn readsint:near,writesint:near
start:
	mov ax,@data
	mov ds,ax
	
	lea dx,msg1
	mov ah,09h
	int 21h
	
	call readsint
	mov n,ax
	
	lea dx,msg2
	mov ah,09h
	int 21h
	
	mov si,0
	mov cx,n
rloop:
	call readsint
	mov arr[si],ax
	inc si
	inc si
	loop rloop
	
	mov si,0
	mov cx,n
	mov dx,arr[si]
cloop:
	dec cx
	cmp cx,0
	jz nm					;no missing items
	inc si
	inc si
	inc dx
	cmp dx,arr[si]
	jz cloop
	
	mov tmp,dx
	lea dx,msg3				;missing item found
	mov ah,09h
	int 21h
	
	mov ax,tmp
	call writesint
	jmp endprog

nm:
	lea dx,msg4
	mov ah,09h
	int 21h

endprog:
	mov ah,4ch
	int 21h
end start