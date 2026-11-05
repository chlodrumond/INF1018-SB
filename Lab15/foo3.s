.text
.globl foo3

foo3:
    pushq %rbp
    movq %rsp, %rbp
    subq $32, %rsp

    movq %rdi, -8(%rbp)
    movl %esi, -12(%rbp)
    movl $0, -16(%rbp)

    xorpd %xmm0, %xmm0
    movsd %xmm0, -24(%rbp)

loop:
    movl -16(%rbp), %eax
    cmpl -12(%rbp), %eax
    jge fim

    movq -8(%rbp), %rax
    movsd (%rax), %xmm0

    call sin

    addsd -24(%rbp), %xmm0
    movsd %xmm0, -24(%rbp)

    addq $8, -8(%rbp)
    addl $1, -16(%rbp)

    jmp loop

fim:
    movsd -24(%rbp), %xmm0

    leave
    ret
