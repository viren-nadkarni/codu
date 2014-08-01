; IOASM-clone
; provides integer input/output procedures


.MODEL SMALL

.DATA
TempStr  db   1,2           ; temporary storage for STDIN input
t2       db   80 dup (0)     
t3       db   13,10,'$'      
Letters  db   '0123456789'  ; possible characters
CrLf     db   13,10,'$'     ; carriage return and linefeed

.CODE

PUBLIC readsint,writesint

PROC readsint           ; reads an integer into the AX register

   push bx              ; save all registers used
   push cx
   push dx
   push si

   mov  TempStr,80      ; read in string using buffered STDIN function
   mov  ah,0Ah
   lea  dx,TempStr
   int  21h

   mov  cl,TempStr+1    ; get length of string
   xor  ch,ch
   mov  bx,0            ; initialize digit index 
   mov  ax,0            ; initialize running total
   mov  si,10           ; radix = decimal = 10
startmul:
   mul  si              ; move total one place to the left
   xor  dh,dh
   mov  dl,[bx+t2]      ; get next digit
   sub  dl,48           ; ascii --> integer value
   add  ax,dx           ; add digit to total
   inc  bx              ; increment digit index
   loop startmul

   push ax
   mov  ah,09h          ; output carriage return/linefeed
   lea  dx,CrLf
   int  21h
   pop  ax

   pop  si              ; restore registers
   pop  dx
   pop  cx
   pop  bx

   ret                  ; return to point of call

readsint ENDP

PROC writesint          ; outputs the integer in the AX register

   push ax              ; save all registers used
   push bx
   push cx
   push dx
   push si

   mov  bx,10           ; radix = decimal = 10
   xor  si,si           ; initialize digit counter 
startdiv:
   xor  dx,dx
   div  bx              ; divide no by 10
   push dx              ; save remainder
   inc  si              ; increment digit counter
   cmp  ax,0            ; check for end of divisions
   jne  startdiv

   mov  cx,si           ; set digit counter
   mov  bx,0            ; initialize position counter
makeletters:
   pop  ax              ; get digit
   add  al,48           ; make integer --> ascii value
   mov  [t2+bx],al      ; insert digit into string
   inc  bx              ; increment position counter
   loop makeletters
   mov  [t2+bx],'$'     ; put end-of-string marker

   mov  ah,09h          ; output integer as string
   lea  dx,t2
   int  21h

   mov  ah,09h          ; output carriage return/linefeed
   lea  dx,CrLf
   int  21h

   pop  si              ; restore registers
   pop  dx
   pop  cx
   pop  bx
   pop  ax

   ret                  ; return to point of call

writesint ENDP

END
