	.file	"main.cpp"
	.text
	.globl	_Z9decrementi
	.type	_Z9decrementi, @function
_Z9decrementi:
.LFB0:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	%edi, -4(%rbp)
	cmpl	$0, -4(%rbp)
							# The compiler performs a conditional jump to the corresponding label
	jne	.L2					# when the value of num does not equal zero, the compiler executes the .L2 label
	movl	$0, %eax		# when the value of the argument equals zero, the return value is set to 0
	jmp	.L3
.L2:
	subl	$1, -4(%rbp)	# Here the argument is updated
	movl	-4(%rbp), %eax	# Here it is passed as an argument
	movl	%eax, %edi		# Here the return destination is set
	call	_Z9decrementi	# And finally, here the recursive call is performed
	nop
.L3:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	_Z9decrementi, .-_Z9decrementi
	.globl	main
	.type	main, @function
main:
.LFB1:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	$7, %edi
	call	_Z9decrementi
	movl	$0, %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	 1f - 0f
	.long	 4f - 1f
	.long	 5
0:
	.string	 "GNU"
1:
	.align 8
	.long	 0xc0000002
	.long	 3f - 2f
2:
	.long	 0x3
3:
	.align 8
4:
