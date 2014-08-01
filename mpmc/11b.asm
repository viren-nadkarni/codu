;proves tan^2(x)+1 = sec^2(x)
.8087
.model small
.stack 512
.data
        x       dd 1.2
        a       dd ?
        o       dd ?
        h       dd ?
        result  dd ?
.code
start:
        mov ax,@data
        mov ds,ax

        finit
        fld x
        fptan

        fstp a
        fst o

        fmul st,st(0)
        fld a
        fmul st,st(0)
        fadd
        fsqrt
        fstp h

        finit
        fld x
        fptan
        fdiv
        fmul st,st(0)

        fld h
        fld a
        fdiv
        fmul st,st(0)
        fsub
        fst result

        mov ah,4ch
        int 21h
end start

