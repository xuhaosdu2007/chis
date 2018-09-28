#include <stdio.h>

//inline int fun(int i);
static inline int fun(int i)
{
    return i*i; 
}

void main()
{
    int a = 9;
    int b = fun(a);
    printf("fact is %d\n",fun(a));
}
