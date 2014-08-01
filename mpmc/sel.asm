;selection
.8086
.model small
.stack 512
.data
	arr		dw 44h,11h,22h,66h
	sz		dw 4
	nc		dw ?					;total no. of comparisons
.code
start:
	mov ax,@data
	mov ds,ax
	
	mov dx,sz
	dec dx
	mov nc,0
outloop:
	mov cx,dx
	mov si,0
	mov ah,arr[si]
	mov bx,si
inloop:
	inc si
	inc nc
	cmp ah,arr[si]
	jb continue
	mov ah,arr[si]
	mov bx,si
continue:
	loop inloop
	xchg ah,arr[si]
	mov arr[bx],ah
	dec dx
	jnz outloop
	
	mov ah,4ch
	int 21h
end start
	