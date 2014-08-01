.8086
.model small
.stack 4096

.data

p1 db 13,10,"how many nos u want to store",'$'
p2 db 13,10,"neter th no ",'$'
p3 db 13,10,"after reversing ",'$'
p4 db 13,10,'$'
n dw ?
arr dw 100 dup(0)
.code

extrn readsint:near,writesint:near

start:

mov ax,@data
mov ds,ax

lea dx,p1
mov ah,09h
int 21h

call readsint
mov n,ax

lea dx,p2
mov ah,09h
int 21h

mov si,0
mov cx,n

loop1:

call readsint 

mov [arr+si],ax
push ax
add si,2

loop loop1

mov si,0
mov cx,n

loop2:
pop ax
mov [arr+si],ax
add si,2

loop loop2

mov si,0
mov cx,n

lea dx,p3
mov ah,09h
int 21h

loop3:

mov ax,[arr+si]

call writesint
 add si,2
 loop loop3
 
 mov ah,4ch
 int 21h
  end start

