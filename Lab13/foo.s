
.text
.globl foo

foo:
    pushq %rbp
    movq %rsp, %rbp
    incl %edi
    movl %edi, %eax
    leave
    ret
  
