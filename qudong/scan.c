#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main()
{
	unsigned int a;
	unsigned int location,tmp;
	unsigned char buf[100];
	char para[100];
	printf("max unsigned int is :%u\n",-1);
	printf("d -1 %d\n",-1);
	printf("input a:\n");
	scanf("%d",&a);
	printf("a is %d\n",a);
	sprintf((char *)buf,"location %x,%d",a,a);
	printf("buf is %s \n",buf);
	sscanf((char *)(&buf[9]),"%x,%d",&location,&tmp);
	printf("location is %x, tmp is %d\n",location,tmp);
}
