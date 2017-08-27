	.386
	.model	flat,stdcall
	.code
main	proc
	mov	eax,c50
	mov	v50,eax
	mov	eax,c51
	mov	v51,eax
	mov	eax,c52
	mov	v52,eax
	mov	eax,v50
	cmp	eax,v51
	jle	_0
	jmp	_1
_0:
	mov	eax,c53
	mov	v52,eax
_1:
	ret
_main	endp
text	ends
_data	segment	word public 'data'
c50	dd	2
c51	dd	1
c52	dd	0
c53	dd	3
v50	dd	0	;a
v51	dd	0	;b
v52	dd	0	;c
_data	ends
stack	segment	stack
	dw	100h dup(?)
stack	ends
	end
