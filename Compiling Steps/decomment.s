	.file	"decomment.c"
	.text
	.globl	main
	.type	main, @function
main:
.LFB6:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movl	$0, -12(%rbp)
.L14:
	call	getchar@PLT
	movb	%al, -13(%rbp)
	movsbl	-13(%rbp), %eax
	movl	%eax, %esi
	leaq	code_line.2876(%rip), %rdi
	call	lineCount@PLT
	cmpb	$-1, -13(%rbp)
	jne	.L2
	movl	unterminated_line.2877(%rip), %edx
	leaq	-12(%rbp), %rax
	movl	%edx, %esi
	movq	%rax, %rdi
	call	checkTermination@PLT
	nop
	movl	$0, %eax
	movq	-8(%rbp), %rcx
	xorq	%fs:40, %rcx
	je	.L16
	jmp	.L17
.L2:
	movl	-12(%rbp), %eax
	cmpl	$7, %eax
	ja	.L14
	movl	%eax, %eax
	leaq	0(,%rax,4), %rdx
	leaq	.L6(%rip), %rax
	movl	(%rdx,%rax), %eax
	cltq
	leaq	.L6(%rip), %rdx
	addq	%rdx, %rax
	notrack jmp	*%rax
	.section	.rodata
	.align 4
	.align 4
.L6:
	.long	.L13-.L6
	.long	.L12-.L6
	.long	.L11-.L6
	.long	.L10-.L6
	.long	.L9-.L6
	.long	.L8-.L6
	.long	.L7-.L6
	.long	.L5-.L6
	.text
.L13:
	movsbl	-13(%rbp), %edx
	leaq	-12(%rbp), %rax
	movl	%edx, %esi
	movq	%rax, %rdi
	call	handleNormalCodeState@PLT
	jmp	.L4
.L12:
	movsbl	-13(%rbp), %edx
	leaq	-12(%rbp), %rax
	movl	%edx, %esi
	movq	%rax, %rdi
	call	handleInCharLiteralState@PLT
	jmp	.L4
.L11:
	movsbl	-13(%rbp), %edx
	leaq	-12(%rbp), %rax
	movl	%edx, %esi
	movq	%rax, %rdi
	call	handleInStringLiteralState@PLT
	jmp	.L4
.L10:
	movsbl	-13(%rbp), %edx
	leaq	-12(%rbp), %rax
	movl	%edx, %esi
	movq	%rax, %rdi
	call	handleEscapeCharState@PLT
	jmp	.L4
.L9:
	movsbl	-13(%rbp), %edx
	leaq	-12(%rbp), %rax
	movl	%edx, %esi
	movq	%rax, %rdi
	call	handleEscapeStrState@PLT
	jmp	.L4
.L8:
	movsbl	-13(%rbp), %esi
	leaq	-12(%rbp), %rax
	leaq	code_line.2876(%rip), %rcx
	leaq	unterminated_line.2877(%rip), %rdx
	movq	%rax, %rdi
	call	handleCommentStarterState@PLT
	jmp	.L4
.L7:
	movsbl	-13(%rbp), %edx
	leaq	-12(%rbp), %rax
	movl	%edx, %esi
	movq	%rax, %rdi
	call	handleInsideCommentState@PLT
	jmp	.L4
.L5:
	movsbl	-13(%rbp), %edx
	leaq	-12(%rbp), %rax
	movl	%edx, %esi
	movq	%rax, %rdi
	call	handleCommentEnderState@PLT
	nop
.L4:
	jmp	.L14
.L17:
	call	__stack_chk_fail@PLT
.L16:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	main, .-main
	.data
	.align 4
	.type	code_line.2876, @object
	.size	code_line.2876, 4
code_line.2876:
	.long	1
	.align 4
	.type	unterminated_line.2877, @object
	.size	unterminated_line.2877, 4
unterminated_line.2877:
	.long	1
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
