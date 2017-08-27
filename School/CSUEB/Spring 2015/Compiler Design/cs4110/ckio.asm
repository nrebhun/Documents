	.model	small
	.386
dgroup	group	_data
	assume	cs:text,ds:dgroup,ss:dgroup
text	segment	para public 'code'
_main	proc	far
	mov	ax,seg _data
	mov	ds,ax
	finit
	call	_ini
	mov	v50,eax
	call	_ini
	mov	v51,eax
	mov	eax,v50
	call	_outi
	mov	eax,v51
	call	_outi
	fld	c00
	fstp	v00
	fdivr	v00
	call	_outf
	call	_inf
	fmul	v00
	call	_inf
	fmul	v01
	fdivr	v00
	call	_outf
	fdivr	v01
	call	_outf
	mov	ax,4c00h
	int	21h
_main	endp
text	ends
_data	segment	word public 'data'
c00	real10	1.00000000000000e+123
v00	real10	0.0	;real
v01	real10	0.0	;xyz
v50	dd	0	;a
v51	dd	0	;number
_data	ends
stack	segment	stack
	dw	100h dup(?)
stack	ends
	extern	_inf:near
	extern	_ini:near
	extern	_outf:near
	extern	_outi:near
	end	_main
