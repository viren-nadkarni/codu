;binsearch
.8086
.model small
.stack 512
.data
	array 		dw 11,23,33,45,56
	len 		dw 5
	key 		dw 23
	success 	db 13,10,"Key found at index $"
	failure 	db 13,10,"Key was not found$"
.code
	extrn readsint:near,writesint:near
start:
	mov ax,@data
	mov ds,ax
	
	mov bx,1
	mov dx,len
	mov cx,key
again:
	cmp bx,dx
	ja notfound
	mov ax,bx
	add ax,dx
	shr ax,1
	mov si,ax
	dec si
	add si,si
	cmp cx,array[si]
	jae bigger
	dec ax
	mov dx,ax
	jmp again
bigger:
	je found
	inc ax
	mov bx,ax
	jmp again
found:
	mov si,ax
	lea dx,success
	mov ah,09h
	int 21h	
	dec si
	mov ax,si
	call writesint
	jmp endprog
notfound:
	lea dx,failure
	mov ah,09h
	int 21h
endprog:	
	mov ah,4ch
	int 21h
end start