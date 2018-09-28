#include <stdio.h>
extern int work(); 
void main()
{
    int i;
    i = work();
    printf("i is %d\n",i);
}
