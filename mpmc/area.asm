.8086
.model small
.stack 512
.data
        rad     dd 5.0
        area    dd ?
.code
start:
        mov ax,@data
        mov ds,ax

        fld rad
        fmul st(0),st(0)

        fldpi
        fmul st(0),st(1)

        fst area

        mov ax,4c00h
        int 21h

end start
