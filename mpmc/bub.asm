;bubble sort
.8086
.model small
.stack 512
.data
	arr		dw 34h,78h,56h,47h
	sz		dw 4
.code
start:
	mov ax,@data
	mov ds,ax
	
	mov bx,sz
	dec bx
outloop:
	mov cx,bx
	mov si,0
inloop:
	mov al,arr[si]
	inc si
	cmp al,arr[si]
	jb continue
	xchg al,a[si]
	mov a[si-1],al
continue:
	loop inloop
	dec bx
	jnz outloop

	mov ah,4ch
	int 21h
end start