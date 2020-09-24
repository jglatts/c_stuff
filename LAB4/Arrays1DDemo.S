        .file   "Arrays1DDemo.c"
        .text
        .globl  main
        .type   main, @function
main:
.LFB2:
        .cfi_startproc
        pushq   %rbp
        .cfi_def_cfa_offset 16
        .cfi_offset 6, -16
        movq    %rsp, %rbp
        .cfi_def_cfa_register 6
        pushq   %r15
        pushq   %r14
        pushq   %r13
        pushq   %r12
        pushq   %rbx
        subq    $56, %rsp
        .cfi_offset 15, -24
        .cfi_offset 14, -32
        .cfi_offset 13, -40
        .cfi_offset 12, -48
        .cfi_offset 3, -56
        movq    %fs:40, %rax
        movq    %rax, -56(%rbp)
        xorl    %eax, %eax
        movq    %rsp, %rax
        movq    %rax, %rbx
        movl    $0, %eax
        call    get_array_size
        movl    %eax, -84(%rbp)
        movl    $0, %eax
        call    get_low_limit
        movl    %eax, -80(%rbp)
        movl    $0, %eax
        call    get_high_limit
        movl    %eax, -76(%rbp)
        movl    -84(%rbp), %eax
        movslq  %eax, %rdx
        subq    $1, %rdx
        movq    %rdx, -72(%rbp)
        movslq  %eax, %rdx
        movq    %rdx, %r14
        movl    $0, %r15d
        movslq  %eax, %rdx
        movq    %rdx, %r12
        movl    $0, %r13d
        cltq
        salq    $2, %rax
        leaq    3(%rax), %rdx
        movl    $16, %eax
        subq    $1, %rax
        addq    %rdx, %rax
        movl    $16, %ecx
        movl    $0, %edx
        divq    %rcx
        imulq   $16, %rax, %rax
        subq    %rax, %rsp
        movq    %rsp, %rax
        addq    $3, %rax
        shrq    $2, %rax
        salq    $2, %rax
        movq    %rax, -64(%rbp)
        movl    $0, %edi
        call    time
        movl    %eax, %edi
        call    srand
        movq    -64(%rbp), %rax
        movl    -76(%rbp), %ecx
        movl    -80(%rbp), %edx
        movl    -84(%rbp), %esi
        movq    %rax, %rdi
        call    fill_array
        movq    -64(%rbp), %rax
        movl    -84(%rbp), %edx
        movl    %edx, %esi
        movq    %rax, %rdi
        call    find_with_range
        movq    -64(%rbp), %rax
        movl    -84(%rbp), %edx
        movl    %edx, %esi
        movq    %rax, %rdi
        call    reverse_array
        movq    -64(%rbp), %rax
        movl    -84(%rbp), %edx
        movl    %edx, %esi
        movq    %rax, %rdi
        call    print_sequence
        movl    $0, %eax
        movq    %rbx, %rsp
        movq    -56(%rbp), %rbx
        xorq    %fs:40, %rbx
        je      .L3
        call    __stack_chk_fail
.L3:
        leaq    -40(%rbp), %rsp
        popq    %rbx
        popq    %r12
        popq    %r13
        popq    %r14
        popq    %r15
        popq    %rbp
        .cfi_def_cfa 7, 8
        ret
        .cfi_endproc
.LFE2:
        .size   main, .-main
        .section        .rodata
.LC0:
        .string "Please Enter Array Size: "
.LC1:
        .string "%d"
        .text
        .globl  get_array_size
        .type   get_array_size, @function
get_array_size:
.LFB3:
        .cfi_startproc
        pushq   %rbp
        .cfi_def_cfa_offset 16
        .cfi_offset 6, -16
        movq    %rsp, %rbp
        .cfi_def_cfa_register 6
        subq    $16, %rsp
        movq    %fs:40, %rax
        movq    %rax, -8(%rbp)
        xorl    %eax, %eax
        movl    $.LC0, %edi
        movl    $0, %eax
        call    printf
        leaq    -12(%rbp), %rax
        movq    %rax, %rsi
        movl    $.LC1, %edi
        movl    $0, %eax
        call    __isoc99_scanf
        movl    -12(%rbp), %eax
        movq    -8(%rbp), %rdx
        xorq    %fs:40, %rdx
        je      .L6
        call    __stack_chk_fail
.L6:
        leave
        .cfi_def_cfa 7, 8
        ret
        .cfi_endproc
.LFE3:
        .size   get_array_size, .-get_array_size
        .section        .rodata
.LC2:
        .string "Please Enter Low Limit: "
        .text
        .globl  get_low_limit
        .type   get_low_limit, @function
get_low_limit:
.LFB4:
        .cfi_startproc
        pushq   %rbp
        .cfi_def_cfa_offset 16
        .cfi_offset 6, -16
        movq    %rsp, %rbp
        .cfi_def_cfa_register 6
        subq    $16, %rsp
        movq    %fs:40, %rax
        movq    %rax, -8(%rbp)
        xorl    %eax, %eax
        movl    $.LC2, %edi
        movl    $0, %eax
        call    printf
        leaq    -12(%rbp), %rax
        movq    %rax, %rsi
        movl    $.LC1, %edi
        movl    $0, %eax
        call    __isoc99_scanf
        movl    -12(%rbp), %eax
        movq    -8(%rbp), %rdx
        xorq    %fs:40, %rdx
        je      .L9
        call    __stack_chk_fail
.L9:
        leave
        .cfi_def_cfa 7, 8
        ret
        .cfi_endproc
.LFE4:
        .size   get_low_limit, .-get_low_limit
        .section        .rodata
.LC3:
        .string "Please Enter High Limit: "
        .text
        .globl  get_high_limit
        .type   get_high_limit, @function
get_high_limit:
.LFB5:
        .cfi_startproc
        pushq   %rbp
        .cfi_def_cfa_offset 16
        .cfi_offset 6, -16
        movq    %rsp, %rbp
        .cfi_def_cfa_register 6
        subq    $16, %rsp
        movq    %fs:40, %rax
        movq    %rax, -8(%rbp)
        xorl    %eax, %eax
        movl    $.LC3, %edi
        movl    $0, %eax
        call    printf
        leaq    -12(%rbp), %rax
        movq    %rax, %rsi
        movl    $.LC1, %edi
        movl    $0, %eax
        call    __isoc99_scanf
        movl    -12(%rbp), %eax
        movq    -8(%rbp), %rdx
        xorq    %fs:40, %rdx
        je      .L12
        call    __stack_chk_fail
.L12:
        leave
        .cfi_def_cfa 7, 8
        ret
        .cfi_endproc
.LFE5:
        .size   get_high_limit, .-get_high_limit
        .section        .rodata
.LC4:
        .string "%-10d"
        .text
        .globl  print_array
        .type   print_array, @function
print_array:
.LFB6:
        .cfi_startproc
        pushq   %rbp
        .cfi_def_cfa_offset 16
        .cfi_offset 6, -16
        movq    %rsp, %rbp
        .cfi_def_cfa_register 6
        subq    $32, %rsp
        movq    %rdi, -24(%rbp)
        movl    %esi, -28(%rbp)
        movq    $1, -8(%rbp)
        movl    $0, -12(%rbp)
        jmp     .L14
.L16:
        movl    -12(%rbp), %eax
        cltq
        leaq    0(,%rax,4), %rdx
        movq    -24(%rbp), %rax
        addq    %rdx, %rax
        movl    (%rax), %eax
        movl    %eax, %esi
        movl    $.LC4, %edi
        movl    $0, %eax
        call    printf
        movq    -8(%rbp), %rcx
        movabsq $-3689348814741910323, %rdx
        movq    %rcx, %rax
        mulq    %rdx
        shrq    $3, %rdx
        movq    %rdx, %rax
        salq    $2, %rax
        addq    %rdx, %rax
        addq    %rax, %rax
        subq    %rax, %rcx
        movq    %rcx, %rdx
        testq   %rdx, %rdx
        jne     .L15
        movl    $10, %edi
        call    putchar
.L15:
        addl    $1, -12(%rbp)
        addq    $1, -8(%rbp)
.L14:
        movl    -12(%rbp), %eax
        cmpl    -28(%rbp), %eax
        jl      .L16
        nop
        leave
        .cfi_def_cfa 7, 8
        ret
        .cfi_endproc
.LFE6:
        .size   print_array, .-print_array
        .section        .rodata
.LC5:
        .string "\n......Filling Array......"
        .text
        .globl  fill_array
        .type   fill_array, @function
fill_array:
.LFB7:
        .cfi_startproc
        pushq   %rbp
        .cfi_def_cfa_offset 16
        .cfi_offset 6, -16
        movq    %rsp, %rbp
        .cfi_def_cfa_register 6
        subq    $48, %rsp
        movq    %rdi, -24(%rbp)
        movl    %esi, -28(%rbp)
        movl    %edx, -32(%rbp)
        movl    %ecx, -36(%rbp)
        movl    $1, -4(%rbp)
        movl    $.LC5, %edi
        call    puts
        movl    $0, -12(%rbp)
        jmp     .L18
.L21:
        call    rand
        cltd
        idivl   -36(%rbp)
        movl    %edx, %eax
        addl    $1, %eax
        movl    %eax, -8(%rbp)
        jmp     .L19
.L20:
        call    rand
        cltd
        idivl   -36(%rbp)
        movl    %edx, %eax
        addl    $1, %eax
        movl    %eax, -8(%rbp)
.L19:
        movl    -8(%rbp), %eax
        cmpl    -32(%rbp), %eax
        jle     .L20
        movl    -12(%rbp), %eax
        cltq
        leaq    0(,%rax,4), %rdx
        movq    -24(%rbp), %rax
        addq    %rax, %rdx
        movl    -8(%rbp), %eax
        movl    %eax, (%rdx)
        addl    $1, -12(%rbp)
.L18:
        movl    -12(%rbp), %eax
        cmpl    -28(%rbp), %eax
        jl      .L21
        movl    -28(%rbp), %edx
        movq    -24(%rbp), %rax
        movl    %edx, %esi
        movq    %rax, %rdi
        call    print_array
        movl    $10, %edi
        call    putchar
        nop
        leave
        .cfi_def_cfa 7, 8
        ret
        .cfi_endproc
.LFE7:
        .size   fill_array, .-fill_array
        .section        .rodata
        .align 8
.LC6:
        .string "\n......Find Max In Range......"
        .align 8
.LC7:
        .string "Please Enter the Index Low Limit: "
        .align 8
.LC8:
        .string "Please Enter the Index High Limit: "
.LC9:
        .string "\033[1;31m"
.LC10:
        .string "\033[0m"
.LC11:
        .string "Max: %d\n"
        .text
        .globl  find_with_range
        .type   find_with_range, @function
find_with_range:
.LFB8:
        .cfi_startproc
        pushq   %rbp
        .cfi_def_cfa_offset 16
        .cfi_offset 6, -16
        movq    %rsp, %rbp
        .cfi_def_cfa_register 6
        subq    $48, %rsp
        movq    %rdi, -40(%rbp)
        movl    %esi, -44(%rbp)
        movq    %fs:40, %rax
        movq    %rax, -8(%rbp)
        xorl    %eax, %eax
        movl    $1, -16(%rbp)
        movl    $.LC6, %edi
        call    puts
        movl    $.LC7, %edi
        movl    $0, %eax
        call    printf
        leaq    -28(%rbp), %rax
        movq    %rax, %rsi
        movl    $.LC1, %edi
        movl    $0, %eax
        call    __isoc99_scanf
        movl    -28(%rbp), %eax
        cltq
        leaq    0(,%rax,4), %rdx
        movq    -40(%rbp), %rax
        addq    %rdx, %rax
        movl    (%rax), %eax
        movl    %eax, -20(%rbp)
        movl    $.LC8, %edi
        movl    $0, %eax
        call    printf
        leaq    -24(%rbp), %rax
        movq    %rax, %rsi
        movl    $.LC1, %edi
        movl    $0, %eax
        call    __isoc99_scanf
        movl    $0, -12(%rbp)
        jmp     .L23
.L28:
        movl    -28(%rbp), %eax
        cmpl    %eax, -12(%rbp)
        jl      .L24
        movl    -24(%rbp), %eax
        cmpl    %eax, -12(%rbp)
        jg      .L24
        movl    -12(%rbp), %eax
        cltq
        leaq    0(,%rax,4), %rdx
        movq    -40(%rbp), %rax
        addq    %rdx, %rax
        movl    (%rax), %eax
        cmpl    -20(%rbp), %eax
        jle     .L25
        movl    -12(%rbp), %eax
        cltq
        leaq    0(,%rax,4), %rdx
        movq    -40(%rbp), %rax
        addq    %rdx, %rax
        movl    (%rax), %eax
        movl    %eax, -20(%rbp)
.L25:
        movl    $.LC9, %edi
        movl    $0, %eax
        call    printf
        movl    -12(%rbp), %eax
        cltq
        leaq    0(,%rax,4), %rdx
        movq    -40(%rbp), %rax
        addq    %rdx, %rax
        movl    (%rax), %eax
        movl    %eax, %esi
        movl    $.LC4, %edi
        movl    $0, %eax
        call    printf
        movl    $.LC10, %edi
        movl    $0, %eax
        call    printf
        jmp     .L26
.L24:
        movl    -12(%rbp), %eax
        cltq
        leaq    0(,%rax,4), %rdx
        movq    -40(%rbp), %rax
        addq    %rdx, %rax
        movl    (%rax), %eax
        movl    %eax, %esi
        movl    $.LC4, %edi
        movl    $0, %eax
        call    printf
.L26:
        movl    -16(%rbp), %ecx
        movl    $1717986919, %edx
        movl    %ecx, %eax
        imull   %edx
        sarl    $2, %edx
        movl    %ecx, %eax
        sarl    $31, %eax
        subl    %eax, %edx
        movl    %edx, %eax
        sall    $2, %eax
        addl    %edx, %eax
        addl    %eax, %eax
        subl    %eax, %ecx
        movl    %ecx, %edx
        testl   %edx, %edx
        jne     .L27
        movl    $10, %edi
        call    putchar
.L27:
        addl    $1, -12(%rbp)
        addl    $1, -16(%rbp)
.L23:
        movl    -12(%rbp), %eax
        cmpl    -44(%rbp), %eax
        jl      .L28
        movl    -20(%rbp), %eax
        movl    %eax, %esi
        movl    $.LC11, %edi
        movl    $0, %eax
        call    printf
        nop
        movq    -8(%rbp), %rax
        xorq    %fs:40, %rax
        je      .L29
        call    __stack_chk_fail
.L29:
        leave
        .cfi_def_cfa 7, 8
        ret
        .cfi_endproc
.LFE8:
        .size   find_with_range, .-find_with_range
        .section        .rodata
.LC12:
        .string "\n......Reversing Array......"
.LC13:
        .string "Original Array: "
.LC14:
        .string "\nReversed Array: "
        .text
        .globl  reverse_array
        .type   reverse_array, @function
reverse_array:
.LFB9:
        .cfi_startproc
        pushq   %rbp
        .cfi_def_cfa_offset 16
        .cfi_offset 6, -16
        movq    %rsp, %rbp
        .cfi_def_cfa_register 6
        pushq   %rbx
        subq    $72, %rsp
        .cfi_offset 3, -24
        movq    %rdi, -72(%rbp)
        movl    %esi, -76(%rbp)
        movq    %fs:40, %rax
        movq    %rax, -24(%rbp)
        xorl    %eax, %eax
        movq    %rsp, %rax
        movq    %rax, %rbx
        movl    -76(%rbp), %eax
        movslq  %eax, %rdx
        subq    $1, %rdx
        movq    %rdx, -48(%rbp)
        movslq  %eax, %rdx
        movq    %rdx, %r10
        movl    $0, %r11d
        movslq  %eax, %rdx
        movq    %rdx, %r8
        movl    $0, %r9d
        cltq
        salq    $2, %rax
        leaq    3(%rax), %rdx
        movl    $16, %eax
        subq    $1, %rax
        addq    %rdx, %rax
        movl    $16, %esi
        movl    $0, %edx
        divq    %rsi
        imulq   $16, %rax, %rax
        subq    %rax, %rsp
        movq    %rsp, %rax
        addq    $3, %rax
        shrq    $2, %rax
        salq    $2, %rax
        movq    %rax, -40(%rbp)
        movq    $1, -32(%rbp)
        movq    $0, -64(%rbp)
        movl    -76(%rbp), %eax
        subl    $1, %eax
        cltq
        movq    %rax, -56(%rbp)
        movl    $.LC12, %edi
        call    puts
        jmp     .L31
.L32:
        movq    -56(%rbp), %rax
        leaq    0(,%rax,4), %rdx
        movq    -72(%rbp), %rax
        addq    %rdx, %rax
        movl    (%rax), %ecx
        movq    -40(%rbp), %rax
        movq    -64(%rbp), %rdx
        movl    %ecx, (%rax,%rdx,4)
        movq    -56(%rbp), %rax
        leaq    -1(%rax), %rdx
        movq    %rdx, -56(%rbp)
        movq    -64(%rbp), %rdx
        leaq    1(%rdx), %rcx
        movq    %rcx, -64(%rbp)
        leaq    0(,%rdx,4), %rcx
        movq    -72(%rbp), %rdx
        addq    %rcx, %rdx
        movl    (%rdx), %ecx
        movq    -40(%rbp), %rdx
        movl    %ecx, (%rdx,%rax,4)
.L31:
        movq    -64(%rbp), %rax
        cmpq    -56(%rbp), %rax
        jb      .L32
        movl    $.LC13, %edi
        call    puts
        movl    -76(%rbp), %edx
        movq    -72(%rbp), %rax
        movl    %edx, %esi
        movq    %rax, %rdi
        call    print_array
        movl    $.LC14, %edi
        call    puts
        movq    -40(%rbp), %rax
        movl    -76(%rbp), %edx
        movl    %edx, %esi
        movq    %rax, %rdi
        call    print_array
        movq    %rbx, %rsp
        nop
        movq    -24(%rbp), %rax
        xorq    %fs:40, %rax
        je      .L33
        call    __stack_chk_fail
.L33:
        movq    -8(%rbp), %rbx
        leave
        .cfi_def_cfa 7, 8
        ret
        .cfi_endproc
.LFE9:
        .size   reverse_array, .-reverse_array
        .section        .rodata
.LC15:
        .string "Seqeunce found at index %d\n"
.LC16:
        .string "Seqeunce not found"
        .text
        .globl  print_sequence
        .type   print_sequence, @function
print_sequence:
.LFB10:
        .cfi_startproc
        pushq   %rbp
        .cfi_def_cfa_offset 16
        .cfi_offset 6, -16
        movq    %rsp, %rbp
        .cfi_def_cfa_register 6
        subq    $32, %rsp
        movq    %rdi, -24(%rbp)
        movl    %esi, -28(%rbp)
        movl    -28(%rbp), %edx
        movq    -24(%rbp), %rax
        movl    %edx, %esi
        movq    %rax, %rdi
        call    find_sequence
        movl    %eax, -4(%rbp)
        jmp     .L35
.L36:
        movl    -4(%rbp), %eax
        movl    %eax, %esi
        movl    $.LC15, %edi
        movl    $0, %eax
        call    printf
        movl    -28(%rbp), %edx
        movq    -24(%rbp), %rax
        movl    %edx, %esi
        movq    %rax, %rdi
        call    find_sequence
        movl    %eax, -4(%rbp)
.L35:
        cmpl    $0, -4(%rbp)
        jns     .L36
        movl    $.LC16, %edi
        call    puts
        nop
        leave
        .cfi_def_cfa 7, 8
        ret
        .cfi_endproc
.LFE10:
        .size   print_sequence, .-print_sequence
        .section        .rodata
.LC17:
        .string "\n......Finding Sequence......"
.LC18:
        .string "Enter Two Numbers: "
.LC19:
        .string "%d %d"
        .text
        .globl  find_sequence
        .type   find_sequence, @function
find_sequence:
.LFB11:
        .cfi_startproc
        pushq   %rbp
        .cfi_def_cfa_offset 16
        .cfi_offset 6, -16
        movq    %rsp, %rbp
        .cfi_def_cfa_register 6
        subq    $48, %rsp
        movq    %rdi, -40(%rbp)
        movl    %esi, -44(%rbp)
        movq    %fs:40, %rax
        movq    %rax, -8(%rbp)
        xorl    %eax, %eax
        movl    $.LC17, %edi
        call    puts
        movl    $.LC18, %edi
        movl    $0, %eax
        call    printf
        leaq    -16(%rbp), %rdx
        leaq    -20(%rbp), %rax
        movq    %rax, %rsi
        movl    $.LC19, %edi
        movl    $0, %eax
        call    __isoc99_scanf
        movl    $0, -12(%rbp)
        jmp     .L38
.L41:
        movl    -12(%rbp), %eax
        cltq
        leaq    0(,%rax,4), %rdx
        movq    -40(%rbp), %rax
        addq    %rdx, %rax
        movl    (%rax), %edx
        movl    -20(%rbp), %eax
        cmpl    %eax, %edx
        jne     .L39
        movl    -12(%rbp), %eax
        cltq
        addq    $1, %rax
        leaq    0(,%rax,4), %rdx
        movq    -40(%rbp), %rax
        addq    %rdx, %rax
        movl    (%rax), %edx
        movl    -16(%rbp), %eax
        cmpl    %eax, %edx
        jne     .L39
        movl    -12(%rbp), %eax
        jmp     .L42
.L39:
        addl    $1, -12(%rbp)
.L38:
        movl    -44(%rbp), %eax
        subl    $1, %eax
        cmpl    -12(%rbp), %eax
        jg      .L41
        movl    $-1, %eax
.L42:
        movq    -8(%rbp), %rcx
        xorq    %fs:40, %rcx
        je      .L43
        call    __stack_chk_fail
.L43:
        leave
        .cfi_def_cfa 7, 8
        ret
        .cfi_endproc
.LFE11:
        .size   find_sequence, .-find_sequence
        .ident  "GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.12) 5.4.0 20160609"
        .section        .note.GNU-stack,"",@progbits
