	.file	"main.c"
	.text
	.globl	func1
	.type	func1, @function
func1:
.LFB50:
	.cfi_startproc
	movzbl	%dil, %eax
	ret
	.cfi_endproc
.LFE50:
	.size	func1, .-func1
	.globl	func2
	.type	func2, @function
func2:
.LFB51:
	.cfi_startproc
	movsbl	%dil, %eax
	ret
	.cfi_endproc
.LFE51:
	.size	func2, .-func2
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"%x"
	.section	.rodata.str1.8,"aMS",@progbits,1
	.align 8
.LC1:
	.string	"unsigned int a = %X\nfunc1(a) = %X\nfunc2(a) = %X\n"
	.section	.rodata.str1.1
.LC2:
	.string	"%d %d\n"
.LC3:
	.string	"%d\n"
.LC6:
	.string	"%.2f = "
.LC7:
	.string	"%.2x"
.LC9:
	.string	"\n%lf >= \n"
.LC10:
	.string	"sx = %x; usx = %x\n"
	.section	.rodata.str1.8
	.align 8
.LC11:
	.string	"m = %d, n = %d, s = %d\ns - m  = %d, s - n = %d\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB49:
	.cfi_startproc
	pushq	%r12
	.cfi_def_cfa_offset 16
	.cfi_offset 12, -16
	pushq	%rbp
	.cfi_def_cfa_offset 24
	.cfi_offset 6, -24
	pushq	%rbx
	.cfi_def_cfa_offset 32
	.cfi_offset 3, -32
	subq	$16, %rsp
	.cfi_def_cfa_offset 48
	movq	%fs:40, %rax
	movq	%rax, 8(%rsp)
	xorl	%eax, %eax
	movl	$0, (%rsp)
	movl	$0, %ebp
	jmp	.L4
.L5:
	movq	%rsp, %rsi
	movl	$.LC0, %edi
	movl	$0, %eax
	call	__isoc99_scanf
	movl	(%rsp), %ebx
	movl	%ebx, %edi
	call	func2
	movl	%eax, %r12d
	movl	%ebx, %edi
	call	func1
	movl	%r12d, %r8d
	movl	%eax, %ecx
	movl	%ebx, %edx
	movl	$.LC1, %esi
	movl	$1, %edi
	movl	$0, %eax
	call	__printf_chk
	addl	$1, %ebp
.L4:
	cmpl	$3, %ebp
	jle	.L5
	movl	$-2, %ecx
	movl	%ecx, %edx
	movl	$.LC2, %esi
	movl	$1, %edi
	movl	$0, %eax
	call	__printf_chk
	movl	$0, %edx
	movl	$.LC3, %esi
	movl	$1, %edi
	movl	$0, %eax
	call	__printf_chk
	movl	$0x41040000, 4(%rsp)
	movsd	.LC5(%rip), %xmm0
	movl	$.LC6, %esi
	movl	$1, %edi
	movl	$1, %eax
	call	__printf_chk
	leaq	4(%rsp), %rax
	movl	$0, %ebx
	jmp	.L6
.L7:
	leaq	1(%rax), %rbp
	movsbl	(%rax), %edx
	movl	$.LC7, %esi
	movl	$1, %edi
	movl	$0, %eax
	call	__printf_chk
	addl	$1, %ebx
	movq	%rbp, %rax
.L6:
	cmpl	$3, %ebx
	jle	.L7
	movsd	.LC8(%rip), %xmm0
	movl	$.LC9, %esi
	movl	$1, %edi
	movl	$1, %eax
	call	__printf_chk
	movl	$-12345, %ecx
	movl	%ecx, %edx
	movl	$.LC10, %esi
	movl	$1, %edi
	movl	$0, %eax
	call	__printf_chk
	subq	$8, %rsp
	.cfi_def_cfa_offset 56
	pushq	$-2147483648
	.cfi_def_cfa_offset 64
	movl	$-2147483648, %r9d
	movl	$0, %r8d
	movl	%r9d, %ecx
	movl	%r9d, %edx
	movl	$.LC11, %esi
	movl	$1, %edi
	movl	$0, %eax
	call	__printf_chk
	addq	$16, %rsp
	.cfi_def_cfa_offset 48
	movl	$0, %eax
	movq	8(%rsp), %rcx
	xorq	%fs:40, %rcx
	je	.L8
	call	__stack_chk_fail
.L8:
	addq	$16, %rsp
	.cfi_def_cfa_offset 32
	popq	%rbx
	.cfi_def_cfa_offset 24
	popq	%rbp
	.cfi_def_cfa_offset 16
	popq	%r12
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE49:
	.size	main, .-main
	.section	.rodata.cst8,"aM",@progbits,8
	.align 8
.LC5:
	.long	0
	.long	1075871744
	.align 8
.LC8:
	.long	0
	.long	1139670048
	.ident	"GCC: (Ubuntu 5.5.0-12ubuntu1~16.04) 5.5.0 20171010"
	.section	.note.GNU-stack,"",@progbits
