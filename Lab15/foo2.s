.text
.globl foo2

foo2:
    pushq %rbp
    movq %rsp, %rbp
    subq $16, %rsp

    movss %xmm1, -4(%rbp)
    cvtss2sd %xmm0, %xmm0

    call sin

    movsd %xmm0, -16(%rbp)

    movss -4(%rbp), %xmm0
    cvtss2sd %xmm0, %xmm0

    call cos

    addsd -16(%rbp), %xmm0

    leave
    ret
