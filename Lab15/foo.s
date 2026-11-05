
.text
.globl foo

foo:
    pushq %rbp
    movq %rsp, %rbp

    cvtss2sd %xmm1, %xmm1
    movsd %xmm0, %xmm2

    addsd %xmm1, %xmm0
    subsd %xmm1, %xmm2
    mulsd %xmm2, %xmm0

    cvtsd2ss %xmm0, %xmm0

    leave
    ret
