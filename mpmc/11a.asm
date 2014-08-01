;proves sin^2(x) + con^2(x) = 1
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
        fst h

        finit
        fld o
        fld h
        fdiv
        fmul st,st(0)

        fld a
        fld h
        fdiv
        fmul st,st(0)

        fadd
        fst result

        mov ah,4ch
        int 21h
end start
