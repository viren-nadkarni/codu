.8086
.model small
.stack 512
.data
	arr		dw 12,22,34,45,55
	n		dw 5
	key		dw 34
	prompt1	db 13,10,"Key found at index $"
	prompt2	db 13,10,"Key not found $"
.code
	extrn readsint:near,writesint:near
start:
	mov ax,@data
	mov ds,ax
	
	mov si,n
	mov cx,0
	mov bx,key
lp:
	div si,2
	cmp bx,arr[si]
	ja above
	jb below
	lea dx,prompt1
	goto endprog
above:
	
	
	
	
	
	
	
endprog:
	mov ah,09h
	int 21h
	
	mov ah,4ch
	int 21h
end start