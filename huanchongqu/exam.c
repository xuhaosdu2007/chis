#include <stdio.h>
void haha()
{
	printf("\n success");
	sleep(10);
}
void fun(int a,int b,int c)
{
	char buffer1[5];
	char buffer2[10];
	int *ret;
	ret = (int *)(buffer1 + 0x28);
	(*ret) = &haha;
	printf("fun end\n");
}
void main()
{
	int *ha;
	ha = &haha;
	int x;
	x = 0;
	fun(1,2,3);
	x = 1;
	printf(" x is %d\n",x);
}
