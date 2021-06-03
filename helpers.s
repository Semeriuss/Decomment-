	.file	"helpers.c"
	.text
	.globl	handleNormalCodeState
	.type	handleNormalCodeState, @function
handleNormalCodeState:
.LFB6:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movl	%esi, %eax
	movb	%al, -12(%rbp)
	cmpb	$47, -12(%rbp)
	jne	.L2
	movq	-8(%rbp), %rax
	movl	$5, (%rax)
	jmp	.L6
.L2:
	cmpb	$34, -12(%rbp)
	jne	.L4
	movq	-8(%rbp), %rax
	movl	$2, (%rax)
	movsbl	-12(%rbp), %eax
	movl	%eax, %edi
	call	putchar@PLT
	jmp	.L6
.L4:
	cmpb	$39, -12(%rbp)
	jne	.L5
	movq	-8(%rbp), %rax
	movl	$1, (%rax)
	movsbl	-12(%rbp), %eax
	movl	%eax, %edi
	call	putchar@PLT
	jmp	.L6
.L5:
	movq	-8(%rbp), %rax
	movl	$0, (%rax)
	movsbl	-12(%rbp), %eax
	movl	%eax, %edi
	call	putchar@PLT
.L6:
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	handleNormalCodeState, .-handleNormalCodeState
	.globl	handleInCharLiteralState
	.type	handleInCharLiteralState, @function
handleInCharLiteralState:
.LFB7:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movl	%esi, %eax
	movb	%al, -12(%rbp)
	movsbl	-12(%rbp), %eax
	movl	%eax, %edi
	call	putchar@PLT
	cmpb	$92, -12(%rbp)
	jne	.L8
	movq	-8(%rbp), %rax
	movl	$3, (%rax)
	jmp	.L10
.L8:
	cmpb	$39, -12(%rbp)
	jne	.L10
	movq	-8(%rbp), %rax
	movl	$0, (%rax)
.L10:
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7:
	.size	handleInCharLiteralState, .-handleInCharLiteralState
	.globl	handleInStringLiteralState
	.type	handleInStringLiteralState, @function
handleInStringLiteralState:
.LFB8:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movl	%esi, %eax
	movb	%al, -12(%rbp)
	movsbl	-12(%rbp), %eax
	movl	%eax, %edi
	call	putchar@PLT
	cmpb	$92, -12(%rbp)
	jne	.L12
	movq	-8(%rbp), %rax
	movl	$3, (%rax)
	jmp	.L14
.L12:
	cmpb	$34, -12(%rbp)
	jne	.L14
	movq	-8(%rbp), %rax
	movl	$0, (%rax)
.L14:
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8:
	.size	handleInStringLiteralState, .-handleInStringLiteralState
	.globl	handleEscapeCharState
	.type	handleEscapeCharState, @function
handleEscapeCharState:
.LFB9:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movl	%esi, %eax
	movb	%al, -12(%rbp)
	movq	-8(%rbp), %rax
	movl	$1, (%rax)
	movsbl	-12(%rbp), %eax
	movl	%eax, %edi
	call	putchar@PLT
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9:
	.size	handleEscapeCharState, .-handleEscapeCharState
	.globl	handleEscapeStrState
	.type	handleEscapeStrState, @function
handleEscapeStrState:
.LFB10:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movl	%esi, %eax
	movb	%al, -12(%rbp)
	movq	-8(%rbp), %rax
	movl	$2, (%rax)
	movsbl	-12(%rbp), %eax
	movl	%eax, %edi
	call	putchar@PLT
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE10:
	.size	handleEscapeStrState, .-handleEscapeStrState
	.globl	handleCommentStarterState
	.type	handleCommentStarterState, @function
handleCommentStarterState:
.LFB11:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -8(%rbp)
	movl	%esi, %eax
	movq	%rdx, -24(%rbp)
	movq	%rcx, -32(%rbp)
	movb	%al, -12(%rbp)
	cmpb	$42, -12(%rbp)
	jne	.L18
	movq	-8(%rbp), %rax
	movl	$6, (%rax)
	movq	-32(%rbp), %rax
	movl	(%rax), %edx
	movq	-24(%rbp), %rax
	movl	%edx, (%rax)
	jmp	.L22
.L18:
	cmpb	$47, -12(%rbp)
	jne	.L20
	movq	-8(%rbp), %rax
	movl	(%rax), %eax
	cmpl	$5, %eax
	jne	.L20
	movsbl	-12(%rbp), %eax
	movl	%eax, %edi
	call	putchar@PLT
	movq	-8(%rbp), %rax
	movl	$5, (%rax)
	jmp	.L22
.L20:
	cmpb	$47, -12(%rbp)
	jne	.L21
	movq	-8(%rbp), %rax
	movl	$5, (%rax)
	jmp	.L22
.L21:
	movq	-8(%rbp), %rax
	movl	$0, (%rax)
	movl	$47, %edi
	call	putchar@PLT
	movsbl	-12(%rbp), %eax
	movl	%eax, %edi
	call	putchar@PLT
.L22:
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE11:
	.size	handleCommentStarterState, .-handleCommentStarterState
	.globl	handleInsideCommentState
	.type	handleInsideCommentState, @function
handleInsideCommentState:
.LFB12:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movl	%esi, %eax
	movb	%al, -12(%rbp)
	cmpb	$42, -12(%rbp)
	jne	.L24
	movq	-8(%rbp), %rax
	movl	$7, (%rax)
.L24:
	cmpb	$10, -12(%rbp)
	jne	.L26
	movsbl	-12(%rbp), %eax
	movl	%eax, %edi
	call	putchar@PLT
.L26:
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE12:
	.size	handleInsideCommentState, .-handleInsideCommentState
	.globl	handleCommentEnderState
	.type	handleCommentEnderState, @function
handleCommentEnderState:
.LFB13:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movl	%esi, %eax
	movb	%al, -12(%rbp)
	cmpb	$47, -12(%rbp)
	jne	.L28
	movq	-8(%rbp), %rax
	movl	$0, (%rax)
	jmp	.L31
.L28:
	cmpb	$42, -12(%rbp)
	jne	.L30
	movq	-8(%rbp), %rax
	movl	$7, (%rax)
	jmp	.L31
.L30:
	movq	-8(%rbp), %rax
	movl	$6, (%rax)
	movl	$32, %edi
	call	putchar@PLT
.L31:
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE13:
	.size	handleCommentEnderState, .-handleCommentEnderState
	.globl	lineCount
	.type	lineCount, @function
lineCount:
.LFB14:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movl	%esi, %eax
	movb	%al, -12(%rbp)
	cmpb	$10, -12(%rbp)
	jne	.L34
	movq	-8(%rbp), %rax
	movl	(%rax), %eax
	leal	1(%rax), %edx
	movq	-8(%rbp), %rax
	movl	%edx, (%rax)
.L34:
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE14:
	.size	lineCount, .-lineCount
	.section	.rodata
	.align 8
.LC0:
	.string	"Error: Comment started on line %d is unterminated comment.\n"
	.text
	.globl	checkTermination
	.type	checkTermination, @function
checkTermination:
.LFB15:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movl	%esi, -12(%rbp)
	movq	-8(%rbp), %rax
	movl	(%rax), %eax
	cmpl	$6, %eax
	je	.L36
	movq	-8(%rbp), %rax
	movl	(%rax), %eax
	cmpl	$7, %eax
	jne	.L38
.L36:
	movq	stderr(%rip), %rax
	movl	-12(%rbp), %edx
	leaq	.LC0(%rip), %rsi
	movq	%rax, %rdi
	movl	$0, %eax
	call	fprintf@PLT
.L38:
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE15:
	.size	checkTermination, .-checkTermination
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
