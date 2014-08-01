;insertion sort
.8086
.model small
.stack 512
.data
	arr		dw 78h,34h,12h,56h
	sz		dw 4
.code
start:
	mov ax,@data
	mov ds,ax
	
	mov cx,2
outloop:
	mov dx,cx
	dec dx
	mov si,dx
	add si,si
	mov ax,arr[si]
inloop:
	cmp arr[si-2],ax
	jbe inloop_exit
	mov di,arr[si-2]
	mov arr[si],di
	dec si
	dec si
	dec dx
	jnz inloop
inloop_exit:
	mov arr[si],ax
	inc cx
	cmp cx,sz
	jbe outloop

	mov ah,4ch
	int 21h
end start