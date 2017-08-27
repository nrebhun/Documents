;	p80.asm		2007 apr 14
;			2007 apr 15

;	For use with p8 compiled .asm programs.
;	This calls main (main@0), and defines:
;		inf  (input  float)
;		ini  (input  int)
;		outi (output float)
;		outi (output int)

include smallwin.inc
	public	inf,ini,outi,outf,_p80
	extern	main@0:near
_text	segment
_p80	proc
	call	main@0
	push	eax
	call	exitprocess
_p80	endp
disp	proc
	mov	ebx,offset bbuf
	mov	al,[ebx]
	shr	al,4
	cmp	al,5
	jl	_2
_0:	inc	ebx
	cmp	ebx,offset bbuf+9
	jne	_1
	inc	p
	dec	ebx
	mov	al,10h
	mov	[ebx],al
	jmp	_2
_1:	mov	al,[ebx]
	inc	al
	mov	[ebx],al
	and	al,0fh
	cmp	al,10
	jl	_2
	mov	al,[ebx]
	and	al,0f0h
	add	al,010h
	mov	[ebx],al
	shr	al,4
	cmp	al,10
	jl	_2
	xor	al,al
	mov	[ebx],al
	jmp	_0
_2:	mov	ebx,offset bbuf+9
	mov	ecx,8
_3:	dec	ebx
	mov	dl,[ebx]
	shr	dl,4
	add	dl,'0'
	inc	esi
	mov	[esi],dl
	cmp	ecx,8
	jne	_4
	mov	dl,'.'
	inc	esi
	mov	[esi],dl
_4:	mov	dl,[ebx]
	and	dl,0fh
	add	dl,'0'
	inc	esi
	mov	[esi],dl
	dec	ecx
	jg	_3
	add	esi,7
	mov	cx,10
	mov	ax,p
	mov	bx,ax
_5:	cwd
	idiv	cx
	test	dl,dl
	jge	_6
	neg	dl
_6:	add	dl,'0'
	dec	esi
	mov	[esi],dl
	test	ax,ax
	jnz	_5
	mov	dl,'0'
_7:	cmp	esi,offset buff+20
	je	_8
	dec	esi
	mov	[esi],dl
	jmp	_7
_8:	test	bx,bx
	jge	_9
	mov	dl,'-'
_9:	dec	esi
	mov	[esi],dl
	ret
disp	endp
getch	proc
	mov	eax,n
	test	eax,eax
	jle	_1
_0:	dec	dword ptr n
	push	esi
	mov	esi,bufp
	mov	al,[esi]
	inc	esi
	mov	bufp,esi
	pop	esi
	ret
_1:	pushad
	push	-10
	call	getstdhandle
	push	0
	push	offset n
	push	256
	push	offset buf
	push	eax
	call	readconsole
	mov	bufp,offset buf
	popad
	jmp	_0
getch	endp
inf	proc
	pushad
	mov	eax,offset pf
	call	puts
	fldz
	xor	esi,esi
_0:	call	getch
	cmp	al,' '
	je	_0
	cmp	al,09h
	je	_0
	cmp	al,'-'
	jne	_1
	inc	esi
	call	getch
_1:	call	lup
	xor	ecx,ecx
	cmp	al,'.'
	jne	_2
	call	getch
	call	lup
_2:	xor	ebx,ebx
	cmp	al,'e'
	je	_6
_3:	cmp	al,0dh
	jne	_4
	call	getch
_4:	mov	eax,ebx
	sub	eax,ecx
	call	tento
	fmul
	test	esi,esi
	jz	_5
	fchs
_5:	popad
	ret
_6:	xor	edi,edi
	call	getch
	cmp	al,'-'
	jne	_8
	inc	edi
_7:	call	getch
_8:	cmp	al,'0'
	jl	_9
	cmp	al,'9'
	jg	_9
	xor	ah,ah
	sub	al,'0'
	mov	edx,eax
	mov	eax,ebx
	mov	ebx,edx
	mul	teni
	add	ebx,eax
	jmp	_7
_9:	test	edi,edi
	jz	_a
	neg	ebx
_a:	jmp	_3
inf	endp
ini	proc
	pushad
	mov	eax,offset pi
	call	puts
	xor	esi,esi
	xor	ebx,ebx
	xor	ecx,ecx
_0:	call	getch
	cmp	al,' '
	je	_0
	cmp	al,09h
	je	_0
	cmp	al,'+'
	je	_2
	cmp	al,'-'
	jne	_1
	inc	esi
	jmp	_2
_1:	cmp	al,'0'
	jl	_4
	cmp	al,'9'
	jg	_4
	jmp	_3
_2:	call	getch
	cmp	al,'0'
	jl	_4
	cmp	al,'9'
	jg	_4
_3:	sub	al,'0'
	mov	cl,al
	mov	eax,ebx
	mul	tend
	add	eax,ecx
	mov	ebx,eax
	jmp	_2
_4:	cmp	al,0dh
	jne	_5
	call	getch
_5:	test	esi,esi
	jz	_6
	neg	ebx
_6:	mov	x,ebx
	popad
	mov	eax,x
	ret
ini	endp
lup	proc
	xor	ebx,ebx
	jmp	_1
_0:	call	getch
_1:	cmp	al,'0'
	jl	_2
	cmp	al,'9'
	jg	_2
	inc	ecx
	mov	bl,al
	sub	bl,'0'
	mov	digit,bx
	fild	teni
	fmul
	fild	digit
	fadd
	jmp	_0
_2:	ret
lup	endp
outf	proc
	pushad
	ftst			;x
	fnstsw	ax
	sahf
	jnz	_0
	fstp	st		;
	mov	eax,offset zero
	jmp	_5
_0:	mov	esi,offset buff
	ja	_1
	fabs			;|x|
	mov	dl,'-'
	jmp	_2
_1:	mov	dl,' '
_2:	mov	[esi],dl
	fldlg2			;x,clog2
	fxch			;clog2,x
	fyl2x			;y=clog(x)
	fnstcw	word ptr bbuf
	mov	ax,word ptr bbuf
	or	ax,0c00h
	mov	word ptr bbuf+2,ax
	fldcw	word ptr bbuf+2
	fld	st		;y,y
	frndint			;y,p=[y]
	fclex
	fldcw	word ptr bbuf
	fist	word ptr p	;y,p
	fsub			;q=y-p
	fldl2t			;q,lg10
	fmul			;q*lg10
	fild	neg3		;q*lg10,-3
	fxch			;-3,q*lg10
	fscale			;-3,q*lg10/8
	fxch			;q*lg10/8,-3
	fstp	st		;q*lg10/8
	f2xm1			;2**(q*lg10/8) - 1
	fld1			;",1
	fadd			;2**(q*lg10/8)
	fmul	st,st		;**2
	fmul	st,st		;**4
	fmul	st,st		;**8 = 10**q
	fcom	tenf
	fstsw	ax
	sahf
	jb	_3
	fstp	st
	inc	p
	fld	ten17		;1.0*10**17
	jmp	_4
_3:	fmul	ten17		;10*q**10**17
_4:	fbstp	bbuf		;
	call	disp
	mov	eax,offset buff
_5:	call	puts
	popad
	ret
outf	endp
outi	proc
	pushad
	push	eax
	mov	ebx,offset bufi+11
	mov	ecx,10
_0:	cdq
	idiv	ecx
	test	dl,dl
	jge	_1
	neg	dl
_1:	add	dl,'0'
	dec	ebx
	mov	[ebx],dl
	test	eax,eax
	jnz	_0
_2:	pop	ecx
	test	ecx,ecx
	jge	_3
	dec	ebx
	mov	byte ptr [ebx],'-'
_3:	cmp	ebx,offset bufi
	jbe	_4
	dec	ebx
	mov	byte ptr [ebx],' '
	jmp	_3
_4:	push	-11
	call	getstdhandle
	push	0
	push	offset n
	push	13
	push	ebx
	push	eax
	call	writeconsole
	popad
	ret
outi	endp
puts	proc
	pushad
	mov	edx,eax
	mov	ebx,eax
	xor	ecx,ecx
_0:	mov	al,[ebx]
	test	al,al
	jz	_1
	inc	ecx
	inc	ebx
	jmp	_0
_1:	push	-11
	call	getstdhandle
	push	0
	push	offset bbuf
	push	ecx
	push	edx
	push	eax
	call	writeconsole
	popad
	ret
puts	endp
tento	proc
	fild	teni
	xor	edx,edx
	test	eax,eax
	jge	_0
	neg	eax
	inc	edx
_0:	test	al,1
	jnz	_1
	fld1
	fxch
	jmp	_3
_1:	fld	st
	jmp	_3
_2:	fmul	st,st
	test	al,1
	jz	_3
	fmul	st(1),st
_3:	shr	eax,1
	jnz	_2
	fstp	st
	test	edx,edx
	jz	_4
	fld1
	fdivr
_4:	ret
tento	endp
_text	ends
_data	segment
bbuf	tbyte	?
buf	db	258 dup (?)
buff	db	18 dup (?)
	db	'e'
	db	5 dup (?)
	db	0dh,0ah,0
bufi	db	11 dup (?)
	db	0dh,0ah,0
bufp	dd	?
char	db	?
digit	dw	?
n	dd	0
neg3	dw	-3
p	dw	?
pf	db	"float? ",0
pi	db	"  int? ",0
ten17	dq	1.0e17
tend	dd	10
tenf	dd	10.0
teni	dw	10
x	dd	?
zero	db	" 0.0",0dh,0ah,0
_data	ends
stack	segment	stack
	dd	100h dup (?)
stack	ends
	end	_p80
