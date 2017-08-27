# test code, first 5 lines on p.135
	.delay
	.code	0
main:	.globl	main
	li	$sp, 0x10004000
	li	$gp, 0x10008000
	# code goes here

end:	b	end
	nop
