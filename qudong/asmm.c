#include <stdio.h>

main()
{

 int val = 0;
 asm volatile("xor %eax,%eax");
 asm volatile("inc %eax");
 asm volatile("movl %%eax,%0" : "=b"(val));
 printf("%x/n",val);
}
