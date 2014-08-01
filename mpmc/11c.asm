;Cos(a+b)=cos(a)Cos(b)- sin(a) sin(b) 
.8087
.model small
.stack 512
.data
	a		dd 1.2
	b		dd 0.7	
	adj_ab	dd ?
	opp_ab	dd ?
	hyp_ab	dd ?
	adj_a	dd ?
	opp_a	dd ?
	hyp_a	dd ?
	adj_b	dd ?
	opp_b	dd ?
	hyp_b	dd ?
	result	dd ?
.code
start:
	mov ax,@data
	mov ds,ax

	finit
	fld a
	fld b
	fadd
	fptan

	fstp adj_ab
	fst opp_ab
	fmul st,st(0)
	fld adj_ab
	fmul st,st(0)
	fadd
	fsqrt
	fst hyp_ab
	
	finit
	fld a
	fptan
	fstp adj_a
	fst opp_a
	fmul st,st(0)
	fld adj_a
	fmul st,st(0)
	fadd
	fsqrt
	fst hyp_a
	
	finit
	fld b
	fptan
	fstp adj_b
	fst opp_b
	fmul st,st(0)
	fld adj_b
	fmul st,st(0)
	fadd
	fsqrt
	fst hyp_b
	
	finit
	fld adj_ab
	fld hyp_ab
	fdiv
	
	fld adj_a
	fld hyp_a
	fdiv
	
	fld adj_b
	fld hyp_b
	fdiv
	
	fmul
	fsub
	
	fld opp_a
	fld hyp_a
	fdiv
	
	fld opp_b
	fld hyp_b
	fdiv
	
	fmul
	fadd
	
	fst result
	
	mov ah,4ch
	int 21h
end start

