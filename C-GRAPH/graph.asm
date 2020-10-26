	.file	"c_graph.c"
	.comm	all_nodes,400,32
	.comm	_count,4,4
	.text
	.globl	create_new_node
	.type	create_new_node, @function
create_new_node:
.LFB2:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movl	%edi, -20(%rbp)
	movl	$96, %edi
	call	malloc
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rax
	movl	-20(%rbp), %edx
	movl	%edx, (%rax)
	movq	-8(%rbp), %rax
	movl	$0, 4(%rax)
	movq	-8(%rbp), %rax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	create_new_node, .-create_new_node
	.globl	has_edge
	.type	has_edge, @function
has_edge:
.LFB3:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movl	$0, -4(%rbp)
	jmp	.L4
.L7:
	movq	-24(%rbp), %rax
	movl	-4(%rbp), %edx
	movslq	%edx, %rdx
	addq	$2, %rdx
	movq	(%rax,%rdx,8), %rax
	movl	(%rax), %edx
	movq	-32(%rbp), %rax
	movl	(%rax), %eax
	cmpl	%eax, %edx
	jne	.L5
	movl	$1, %eax
	jmp	.L6
.L5:
	addl	$1, -4(%rbp)
.L4:
	movq	-24(%rbp), %rax
	movl	4(%rax), %eax
	cmpl	-4(%rbp), %eax
	jg	.L7
	movl	$0, %eax
.L6:
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3:
	.size	has_edge, .-has_edge
	.globl	add_new_edge
	.type	add_new_edge, @function
add_new_edge:
.LFB4:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$24, %rsp
	.cfi_offset 3, -24
	movq	%rdi, -24(%rbp)
	movl	%esi, -28(%rbp)
	movq	-24(%rbp), %rax
	movl	4(%rax), %ebx
	leal	1(%rbx), %edx
	movq	-24(%rbp), %rax
	movl	%edx, 4(%rax)
	movl	-28(%rbp), %eax
	movl	%eax, %edi
	call	create_new_node
	movq	%rax, %rcx
	movq	-24(%rbp), %rax
	movslq	%ebx, %rdx
	addq	$2, %rdx
	movq	%rcx, (%rax,%rdx,8)
	nop
	addq	$24, %rsp
	popq	%rbx
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE4:
	.size	add_new_edge, .-add_new_edge
	.section	.rodata
.LC0:
	.string	"Reading file: %s\n"
.LC1:
	.string	"r"
.LC2:
	.string	"%d %d"
	.align 8
.LC3:
	.string	"Number of Nodes From File = %d\n"
	.align 8
.LC4:
	.string	"Number of Edges From File = %d\n"
.LC5:
	.string	"Could not open file"
	.text
	.globl	read_new_graph_file
	.type	read_new_graph_file, @function
read_new_graph_file:
.LFB5:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$160, %rsp
	movq	%rdi, -152(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movq	-152(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC0, %edi
	movl	$0, %eax
	call	printf
	movq	-152(%rbp), %rax
	movl	$.LC1, %esi
	movq	%rax, %rdi
	call	fopen
	movq	%rax, -120(%rbp)
	cmpq	$0, -120(%rbp)
	je	.L10
	leaq	-132(%rbp), %rcx
	leaq	-136(%rbp), %rdx
	movq	-120(%rbp), %rax
	movl	$.LC2, %esi
	movq	%rax, %rdi
	movl	$0, %eax
	call	__isoc99_fscanf
	movl	-136(%rbp), %eax
	movl	%eax, %esi
	movl	$.LC3, %edi
	movl	$0, %eax
	call	printf
	movl	-132(%rbp), %eax
	movl	%eax, %esi
	movl	$.LC4, %edi
	movl	$0, %eax
	call	printf
	jmp	.L11
.L14:
	leaq	-124(%rbp), %rcx
	leaq	-128(%rbp), %rdx
	movq	-120(%rbp), %rax
	movl	$.LC2, %esi
	movq	%rax, %rdi
	movl	$0, %eax
	call	__isoc99_fscanf
	movl	-128(%rbp), %eax
	movl	%eax, %edi
	call	graph_contains_node
	testl	%eax, %eax
	jne	.L12
	movl	-128(%rbp), %eax
	movl	%eax, %edi
	call	create_new_node
	movq	%rax, -112(%rbp)
	movl	-124(%rbp), %edx
	movq	-112(%rbp), %rax
	movl	%edx, %esi
	movq	%rax, %rdi
	call	add_new_edge
	movl	_count(%rip), %eax
	leal	1(%rax), %edx
	movl	%edx, _count(%rip)
	cltq
	movq	-112(%rbp), %rdx
	movq	%rdx, all_nodes(,%rax,8)
	jmp	.L11
.L12:
	movl	-128(%rbp), %eax
	movl	%eax, %edi
	call	get_node_handle
	movq	%rax, -104(%rbp)
	movl	-124(%rbp), %edx
	movq	-104(%rbp), %rax
	movl	%edx, %esi
	movq	%rax, %rdi
	call	add_new_edge
.L11:
	movq	-120(%rbp), %rax
	movq	%rax, %rdi
	call	feof
	testl	%eax, %eax
	je	.L14
	jmp	.L17
.L10:
	movl	$.LC5, %edi
	movl	$0, %eax
	call	printf
.L17:
	nop
	movq	-8(%rbp), %rax
	xorq	%fs:40, %rax
	je	.L16
	call	__stack_chk_fail
.L16:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE5:
	.size	read_new_graph_file, .-read_new_graph_file
	.globl	graph_contains_node
	.type	graph_contains_node, @function
graph_contains_node:
.LFB6:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	%edi, -20(%rbp)
	movl	$0, -4(%rbp)
	jmp	.L19
.L22:
	movl	-4(%rbp), %eax
	cltq
	movq	all_nodes(,%rax,8), %rax
	movl	(%rax), %eax
	cmpl	-20(%rbp), %eax
	jne	.L20
	movl	$1, %eax
	jmp	.L21
.L20:
	addl	$1, -4(%rbp)
.L19:
	movl	_count(%rip), %eax
	cmpl	%eax, -4(%rbp)
	jl	.L22
	movl	$0, %eax
.L21:
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	graph_contains_node, .-graph_contains_node
	.globl	get_node_handle
	.type	get_node_handle, @function
get_node_handle:
.LFB7:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	%edi, -20(%rbp)
	movl	$0, -12(%rbp)
	jmp	.L24
.L27:
	movl	-12(%rbp), %eax
	cltq
	movq	all_nodes(,%rax,8), %rax
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rax
	movl	(%rax), %eax
	cmpl	-20(%rbp), %eax
	jne	.L25
	movq	-8(%rbp), %rax
	jmp	.L26
.L25:
	addl	$1, -12(%rbp)
.L24:
	movl	_count(%rip), %eax
	cmpl	%eax, -12(%rbp)
	jl	.L27
	movl	$0, %eax
.L26:
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7:
	.size	get_node_handle, .-get_node_handle
	.section	.rodata
.LC6:
	.string	"Edges From %d: "
.LC7:
	.string	"%d "
.LC8:
	.string	"No Edges From %d\n"
	.text
	.globl	print_edge_info
	.type	print_edge_info, @function
print_edge_info:
.LFB8:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movq	-24(%rbp), %rax
	movl	4(%rax), %eax
	testl	%eax, %eax
	jle	.L29
	movq	-24(%rbp), %rax
	movl	(%rax), %eax
	movl	%eax, %esi
	movl	$.LC6, %edi
	movl	$0, %eax
	call	printf
	movl	$0, -4(%rbp)
	jmp	.L30
.L31:
	movq	-24(%rbp), %rax
	movl	-4(%rbp), %edx
	movslq	%edx, %rdx
	addq	$2, %rdx
	movq	(%rax,%rdx,8), %rax
	movl	(%rax), %eax
	movl	%eax, %esi
	movl	$.LC7, %edi
	movl	$0, %eax
	call	printf
	addl	$1, -4(%rbp)
.L30:
	movq	-24(%rbp), %rax
	movl	4(%rax), %eax
	cmpl	-4(%rbp), %eax
	jg	.L31
	movl	$10, %edi
	call	putchar
	jmp	.L33
.L29:
	movq	-24(%rbp), %rax
	movl	(%rax), %eax
	movl	%eax, %esi
	movl	$.LC8, %edi
	movl	$0, %eax
	call	printf
.L33:
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8:
	.size	print_edge_info, .-print_edge_info
	.section	.rodata
.LC9:
	.string	"Edges from %d: "
	.text
	.globl	print_all_nodes
	.type	print_all_nodes, @function
print_all_nodes:
.LFB9:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	$0, -16(%rbp)
	jmp	.L35
.L38:
	movl	-16(%rbp), %eax
	cltq
	movq	all_nodes(,%rax,8), %rax
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rax
	movl	(%rax), %eax
	movl	%eax, %esi
	movl	$.LC9, %edi
	movl	$0, %eax
	call	printf
	movl	$0, -12(%rbp)
	jmp	.L36
.L37:
	movq	-8(%rbp), %rax
	movl	-12(%rbp), %edx
	movslq	%edx, %rdx
	addq	$2, %rdx
	movq	(%rax,%rdx,8), %rax
	movl	(%rax), %eax
	movl	%eax, %esi
	movl	$.LC7, %edi
	movl	$0, %eax
	call	printf
	addl	$1, -12(%rbp)
.L36:
	movq	-8(%rbp), %rax
	movl	4(%rax), %eax
	cmpl	-12(%rbp), %eax
	jg	.L37
	movl	$10, %edi
	call	putchar
	addl	$1, -16(%rbp)
.L35:
	movl	_count(%rip), %eax
	cmpl	%eax, -16(%rbp)
	jl	.L38
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9:
	.size	print_all_nodes, .-print_all_nodes
	.section	.rodata
.LC10:
	.string	"Edge Found"
	.align 8
.LC11:
	.string	"Edge Not Found Between %d and %d"
	.text
	.globl	test
	.type	test, @function
test:
.LFB10:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	$5, %edi
	call	create_new_node
	movq	%rax, -16(%rbp)
	movl	$1200, %edi
	call	create_new_node
	movq	%rax, -8(%rbp)
	movq	-16(%rbp), %rax
	movl	$69, %esi
	movq	%rax, %rdi
	call	add_new_edge
	movq	-16(%rbp), %rax
	movl	$420, %esi
	movq	%rax, %rdi
	call	add_new_edge
	movq	-16(%rbp), %rax
	movl	$100, %esi
	movq	%rax, %rdi
	call	add_new_edge
	movq	-16(%rbp), %rax
	movl	$85, %esi
	movq	%rax, %rdi
	call	add_new_edge
	movq	-16(%rbp), %rax
	movl	$32, %esi
	movq	%rax, %rdi
	call	add_new_edge
	movq	-16(%rbp), %rax
	movq	40(%rax), %rax
	movl	$26, %esi
	movq	%rax, %rdi
	call	add_new_edge
	movq	-16(%rbp), %rax
	movq	40(%rax), %rax
	movl	$58, %esi
	movq	%rax, %rdi
	call	add_new_edge
	movq	-16(%rbp), %rax
	movq	40(%rax), %rax
	movl	$11, %esi
	movq	%rax, %rdi
	call	add_new_edge
	movq	-16(%rbp), %rax
	movq	%rax, %rdi
	call	print_edge_info
	movq	-16(%rbp), %rax
	movq	32(%rax), %rax
	movq	%rax, %rdi
	call	print_edge_info
	movq	-16(%rbp), %rax
	movq	40(%rax), %rax
	movq	%rax, %rdi
	call	print_edge_info
	movq	-8(%rbp), %rdx
	movq	-16(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	has_edge
	testl	%eax, %eax
	je	.L40
	movl	$.LC10, %edi
	movl	$0, %eax
	call	printf
	jmp	.L42
.L40:
	movq	-8(%rbp), %rax
	movl	(%rax), %edx
	movq	-16(%rbp), %rax
	movl	(%rax), %eax
	movl	%eax, %esi
	movl	$.LC11, %edi
	movl	$0, %eax
	call	printf
.L42:
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE10:
	.size	test, .-test
	.globl	main
	.type	main, @function
main:
.LFB11:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	%edi, -4(%rbp)
	movq	%rsi, -16(%rbp)
	cmpl	$2, -4(%rbp)
	jne	.L44
	movq	-16(%rbp), %rax
	addq	$8, %rax
	movq	(%rax), %rax
	movq	%rax, %rdi
	call	read_new_graph_file
	movl	$0, %eax
	call	print_all_nodes
.L44:
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE11:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.12) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
