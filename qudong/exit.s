
.section .data
.section .text
.extern _hello
.globl _start_here
.globl work
work:
movl $2, %ebx
movl $3, %eax
ret
_start_here:
movl $1, %eax 
movl $9, %ebx
call hello
movl %eax, %ebx
movl $1, %eax
int $0x80
