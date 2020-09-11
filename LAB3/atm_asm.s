 .file   "atm.c"
        .section        .rodata
.LC0:
        .string "\nWelcome to the \"ATM\""
        .align 8
.LC1:
        .string "\nInvalid PIN. Please Try Again."
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
        subq    $48, %rsp
        movl    %edi, -36(%rbp)
        movq    %rsi, -48(%rbp)
        movq    %fs:40, %rax
        movq    %rax, -8(%rbp)
        xorl    %eax, %eax
        movl    $0, -28(%rbp)
        movl    $5000, -24(%rbp)
        movl    $0, -20(%rbp)
        movl    $0, -16(%rbp)
        movl    $.LC0, %edi
        call    puts
        jmp     .L2
.L6:
        movl    $0, %eax
        call    get_user_pin
        cmpl    $3014, %eax
        je      .L16
        addl    $1, -16(%rbp)
        cmpl    $3, -16(%rbp)
        je      .L2
        movl    $.LC1, %edi
        call    puts
.L2:
        cmpl    $2, -16(%rbp)
        jbe     .L6
        jmp     .L5
.L16:
        nop
.L5:
        cmpl    $3, -16(%rbp)
        jne     .L7
        movl    $0, %eax
        call    print_exit_message
        movl    $0, %edi
        call    exit
.L7:
        movl    $0, %eax
        call    print_main_menu
        movl    $0, %eax
        call    get_user_option
        movl    %eax, -12(%rbp)
        movl    -12(%rbp), %eax
        cmpl    $2, %eax
        je      .L9
        cmpl    $2, %eax
        jg      .L10
        cmpl    $1, %eax
        je      .L11
        jmp     .L8
.L10:
        cmpl    $3, %eax
        je      .L12
        cmpl    $4, %eax
        je      .L13
        jmp     .L8
.L11:
        movl    -24(%rbp), %eax
        movl    %eax, %edi
        call    print_user_balance
        jmp     .L14
.L9:
        leaq    -20(%rbp), %rdx
        leaq    -24(%rbp), %rax
        movq    %rdx, %rsi
        movq    %rax, %rdi
        call    get_withdrawl_amount
        jmp     .L14
.L12:
        leaq    -20(%rbp), %rdx
        leaq    -28(%rbp), %rcx
        leaq    -24(%rbp), %rax
        movq    %rcx, %rsi
        movq    %rax, %rdi
        call    get_depoist_amount
        jmp     .L14
.L13:
        movl    -20(%rbp), %eax
        movl    %eax, %edi
        call    quit_and_print
        jmp     .L14
.L8:
        movl    -12(%rbp), %eax
        movl    %eax, %edi
        call    print_login_error_message
        nop
.L14:
        jmp     .L7
        .cfi_endproc
.LFE2:
        .size   main, .-main
        .section        .rodata
.LC2:
        .string "Please enter your PIN: "
.LC3:
        .string "%d"
        .text
        .globl  get_user_pin
        .type   get_user_pin, @function
get_user_pin:
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
        movl    $.LC2, %edi
        movl    $0, %eax
        call    printf
        leaq    -12(%rbp), %rax
        movq    %rax, %rsi
        movl    $.LC3, %edi
        movl    $0, %eax
        call    __isoc99_scanf
        movl    -12(%rbp), %eax
        movq    -8(%rbp), %rdx
        xorq    %fs:40, %rdx
        je      .L19
        call    __stack_chk_fail
.L19:
        leave
        .cfi_def_cfa 7, 8
        ret
        .cfi_endproc
.LFE3:
        .size   get_user_pin, .-get_user_pin
        .section        .rodata
.LC4:
        .string "\tEnter option : "
        .text
        .globl  get_user_option
        .type   get_user_option, @function
get_user_option:
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
        movl    $.LC4, %edi
        movl    $0, %eax
        call    printf
        leaq    -12(%rbp), %rax
        movq    %rax, %rsi
        movl    $.LC3, %edi
        movl    $0, %eax
        call    __isoc99_scanf
        movl    -12(%rbp), %eax
        movq    -8(%rbp), %rdx
        xorq    %fs:40, %rdx
        je      .L22
        call    __stack_chk_fail
.L22:
        leave
        .cfi_def_cfa 7, 8
        ret
        .cfi_endproc
.LFE4:
        .size   get_user_option, .-get_user_option
        .section        .rodata
        .align 8
.LC5:
        .string "\n\tPlease enter withdrawl amount (in mutlitiples in 20 of only please): "
        .align 8
.LC6:
        .string "\tAmount must be a multipile of 20. Please try again"
        .align 8
.LC7:
        .string "\tAmount cannot be 0. Please try again"
        .align 8
.LC8:
        .string "\tAmount cannot be negative. Please try again"
        .text
        .globl  get_withdrawl_amount
        .type   get_withdrawl_amount, @function
get_withdrawl_amount:
.LFB5:
        .cfi_startproc
        pushq   %rbp
        .cfi_def_cfa_offset 16
        .cfi_offset 6, -16
        movq    %rsp, %rbp
        .cfi_def_cfa_register 6
        subq    $32, %rsp
        movq    %rdi, -24(%rbp)
        movq    %rsi, -32(%rbp)
        movq    %fs:40, %rax
        movq    %rax, -8(%rbp)
        xorl    %eax, %eax
        movl    $0, -12(%rbp)
        jmp     .L24
.L29:
        movl    $.LC5, %edi
        movl    $0, %eax
        call    printf
        leaq    -16(%rbp), %rax
        movq    %rax, %rsi
        movl    $.LC3, %edi
        movl    $0, %eax
        call    __isoc99_scanf
        movl    -16(%rbp), %ecx
        movl    $1717986919, %edx
        movl    %ecx, %eax
        imull   %edx
        sarl    $3, %edx
        movl    %ecx, %eax
        sarl    $31, %eax
        subl    %eax, %edx
        movl    %edx, %eax
        sall    $2, %eax
        addl    %edx, %eax
        sall    $2, %eax
        subl    %eax, %ecx
        movl    %ecx, %edx
        testl   %edx, %edx
        je      .L25
        movl    $.LC6, %edi
        call    puts
        addl    $1, -12(%rbp)
        jmp     .L24
.L25:
        movl    -16(%rbp), %eax
        testl   %eax, %eax
        jne     .L26
        movl    $.LC7, %edi
        call    puts
        addl    $1, -12(%rbp)
        jmp     .L24
.L26:
        movl    -16(%rbp), %eax
        testl   %eax, %eax
        jns     .L33
        movl    $.LC8, %edi
        call    puts
        addl    $1, -12(%rbp)
.L24:
        cmpl    $2, -12(%rbp)
        jbe     .L29
        jmp     .L28
.L33:
        nop
.L28:
        cmpl    $2, -12(%rbp)
        ja      .L30
        movq    -24(%rbp), %rax
        movl    (%rax), %edx
        movl    -16(%rbp), %eax
        subl    %eax, %edx
        movq    -24(%rbp), %rax
        movl    %edx, (%rax)
        movq    -32(%rbp), %rax
        movl    (%rax), %eax
        leal    1(%rax), %edx
        movq    -32(%rbp), %rax
        movl    %edx, (%rax)
        movl    $0, %eax
        call    check_for_receipt
        nop
        movq    -8(%rbp), %rax
        xorq    %fs:40, %rax
        je      .L31
        jmp     .L32
.L30:
        movl    $0, %edi
        call    exit
.L32:
        call    __stack_chk_fail
.L31:
        leave
        .cfi_def_cfa 7, 8
        ret
        .cfi_endproc
.LFE5:
        .size   get_withdrawl_amount, .-get_withdrawl_amount
        .section        .rodata
        .align 8
.LC9:
        .string "\n\tPlease enter depoist amount (Limit of $10,000 a day): "
        .align 8
.LC10:
        .string "\n\tYou're deposit attempt limit has been reached"
.LC11:
        .string "\tPlease depoist tommorow"
        .text
        .globl  get_depoist_amount
        .type   get_depoist_amount, @function
get_depoist_amount:
.LFB6:
        .cfi_startproc
        pushq   %rbp
        .cfi_def_cfa_offset 16
        .cfi_offset 6, -16
        movq    %rsp, %rbp
        .cfi_def_cfa_register 6
        subq    $64, %rsp
        movq    %rdi, -40(%rbp)
        movq    %rsi, -48(%rbp)
        movq    %rdx, -56(%rbp)
        movq    %fs:40, %rax
        movq    %rax, -8(%rbp)
        xorl    %eax, %eax
        movl    $0, -16(%rbp)
        movl    $10000, -12(%rbp)
        jmp     .L35
.L39:
        movl    $.LC9, %edi
        movl    $0, %eax
        call    printf
        leaq    -20(%rbp), %rax
        movq    %rax, %rsi
        movl    $.LC3, %edi
        movl    $0, %eax
        call    __isoc99_scanf
        movl    -20(%rbp), %eax
        testl   %eax, %eax
        jne     .L36
        movl    $.LC7, %edi
        call    puts
        addl    $1, -16(%rbp)
        jmp     .L35
.L36:
        movl    -20(%rbp), %eax
        testl   %eax, %eax
        jns     .L43
        movl    $.LC8, %edi
        call    puts
        addl    $1, -16(%rbp)
.L35:
        cmpl    $2, -16(%rbp)
        jbe     .L39
        jmp     .L38
.L43:
        nop
.L38:
        cmpl    $2, -16(%rbp)
        ja      .L40
        movq    -48(%rbp), %rax
        movl    (%rax), %eax
        cmpl    -12(%rbp), %eax
        jnb     .L40
        movq    -40(%rbp), %rax
        movl    (%rax), %edx
        movl    -20(%rbp), %eax
        addl    %eax, %edx
        movq    -40(%rbp), %rax
        movl    %edx, (%rax)
        movq    -48(%rbp), %rax
        movl    (%rax), %edx
        movl    -20(%rbp), %eax
        addl    %eax, %edx
        movq    -48(%rbp), %rax
        movl    %edx, (%rax)
        movq    -56(%rbp), %rax
        movl    (%rax), %eax
        leal    1(%rax), %edx
        movq    -56(%rbp), %rax
        movl    %edx, (%rax)
        movl    $0, %eax
        call    check_for_receipt
        nop
        movq    -8(%rbp), %rax
        xorq    %fs:40, %rax
        je      .L41
        jmp     .L42
.L40:
        movl    $.LC10, %edi
        call    puts
        movl    $.LC11, %edi
        call    puts
        movl    $0, %edi
        call    exit
.L42:
        call    __stack_chk_fail
.L41:
        leave
        .cfi_def_cfa 7, 8
        ret
        .cfi_endproc
.LFE6:
        .size   get_depoist_amount, .-get_depoist_amount
        .section        .rodata
        .align 8
.LC12:
        .string "\n\tWould you like a receipt Nana?"
.LC13:
        .string "\tEnter 1 for yes, 2 for no: "
        .text
        .globl  check_for_receipt
        .type   check_for_receipt, @function
check_for_receipt:
.LFB7:
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
        movl    $.LC12, %edi
        call    puts
        movl    $.LC13, %edi
        movl    $0, %eax
        call    printf
        leaq    -12(%rbp), %rax
        movq    %rax, %rsi
        movl    $.LC3, %edi
        movl    $0, %eax
        call    __isoc99_scanf
        nop
        movq    -8(%rbp), %rax
        xorq    %fs:40, %rax
        je      .L45
        call    __stack_chk_fail
.L45:
        leave
        .cfi_def_cfa 7, 8
        ret
        .cfi_endproc
.LFE7:
        .size   check_for_receipt, .-check_for_receipt
        .section        .rodata
        .align 8
.LC14:
        .string "\n\tWelcome Nana, please choose an \"ATM\" option"
.LC15:
        .string "\t\t1. Balance"
.LC16:
        .string "\t\t2. Cash withdrawl"
.LC17:
        .string "\t\t3. Cash deposition"
.LC18:
        .string "\t\t4. Quit"
        .text
        .globl  print_main_menu
        .type   print_main_menu, @function
print_main_menu:
.LFB8:
        .cfi_startproc
        pushq   %rbp
        .cfi_def_cfa_offset 16
        .cfi_offset 6, -16
        movq    %rsp, %rbp
        .cfi_def_cfa_register 6
        movl    $.LC14, %edi
        call    puts
        movl    $.LC15, %edi
        call    puts
        movl    $.LC16, %edi
        call    puts
        movl    $.LC17, %edi
        call    puts
        movl    $.LC18, %edi
        call    puts
        nop
        popq    %rbp
        .cfi_def_cfa 7, 8
        ret
        .cfi_endproc
.LFE8:
        .size   print_main_menu, .-print_main_menu
        .section        .rodata
.LC19:
        .string "\n\tNana's Balance is: $%d\n"
        .text
        .globl  print_user_balance
        .type   print_user_balance, @function
print_user_balance:
.LFB9:
        .cfi_startproc
        pushq   %rbp
        .cfi_def_cfa_offset 16
        .cfi_offset 6, -16
        movq    %rsp, %rbp
        .cfi_def_cfa_register 6
        subq    $16, %rsp
        movl    %edi, -4(%rbp)
        movl    -4(%rbp), %eax
        movl    %eax, %esi
        movl    $.LC19, %edi
        movl    $0, %eax
        call    printf
        nop
        leave
        .cfi_def_cfa 7, 8
        ret
        .cfi_endproc
.LFE9:
        .size   print_user_balance, .-print_user_balance
        .section        .rodata
        .align 8
.LC20:
        .string "\nThank you for using the \"ATM\" Program"
.LC21:
        .string "Number of Transactions: %d\n"
        .align 8
.LC22:
        .string "The program will now terminate"
        .text
        .globl  quit_and_print
        .type   quit_and_print, @function
quit_and_print:
.LFB10:
        .cfi_startproc
        pushq   %rbp
        .cfi_def_cfa_offset 16
        .cfi_offset 6, -16
        movq    %rsp, %rbp
        .cfi_def_cfa_register 6
        subq    $16, %rsp
        movl    %edi, -4(%rbp)
        movl    $.LC20, %edi
        call    puts
        movl    -4(%rbp), %eax
        movl    %eax, %esi
        movl    $.LC21, %edi
        movl    $0, %eax
        call    printf
        movl    $.LC22, %edi
        call    puts
        movl    $0, %edi
        call    exit
        .cfi_endproc
.LFE10:
        .size   quit_and_print, .-quit_and_print
        .section        .rodata
        .align 8
.LC23:
        .string "\n\nInvalid PIN number limit has been reached (3 failed attempts)"
        .align 8
.LC24:
        .string "The \"ATM\" Program will terminate.\n"
        .text
        .globl  print_exit_message
        .type   print_exit_message, @function
print_exit_message:
.LFB11:
        .cfi_startproc
        pushq   %rbp
        .cfi_def_cfa_offset 16
        .cfi_offset 6, -16
        movq    %rsp, %rbp
        .cfi_def_cfa_register 6
        movl    $.LC23, %edi
        call    puts
        movl    $.LC24, %edi
        call    puts
        nop
        popq    %rbp
        .cfi_def_cfa 7, 8
        ret
        .cfi_endproc
.LFE11:
        .size   print_exit_message, .-print_exit_message
        .section        .rodata
.LC25:
        .string "\n\t%d is not a valid option\n"
.LC26:
        .string "\tPlease try again"
        .text
        .globl  print_login_error_message
        .type   print_login_error_message, @function
print_login_error_message:
.LFB12:
        .cfi_startproc
        pushq   %rbp
        .cfi_def_cfa_offset 16
        .cfi_offset 6, -16
        movq    %rsp, %rbp
        .cfi_def_cfa_register 6
        subq    $16, %rsp
        movl    %edi, -4(%rbp)
        movl    -4(%rbp), %eax
        movl    %eax, %esi
        movl    $.LC25, %edi
        movl    $0, %eax
        call    printf
        movl    $.LC26, %edi
        call    puts
        nop
        leave
        .cfi_def_cfa 7, 8
        ret
        .cfi_endproc
.LFE12:
        .size   print_login_error_message, .-print_login_error_message
        .ident  "GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.12) 5.4.0 20160609"
        .section        .note.GNU-stack,"",@progbits