/*
	test int type change to char type
	,used for gpt slot change
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	int n;
	int a;
	int b;
	char buff[20];
	char tmp[32];
	char *server_ip;
	char sum[8] = "1.2.3";
	n = ~(1 << 2) &0xff;
	printf("n is %x\n",n);
	server_ip = "56";
	sprintf(tmp,"%s",&sum[0]);
printf("tmp is %s",tmp);	
server_ip = tmp;
//server_ip = tmp;
printf("serverip is %s",server_ip);
#if o	
tmp = &sum[2];
	printf("tmp is %d\n",tmp[1]);
	tmp[2] = 0 ;
	tmp = &sum[0];
	for (int i =0;i<8;i++)
	printf(" %d",sum[i]); 	
	printf ("%d",tmp[2]);
	sprintf(buff,"jd %d\n",32 << 5 | 32);
	printf("res is %s\n",buff);
	n = atoi(&buff[3]);
	a = n/100;
	b = n%100;
	printf("atoi is %d,kuang is %d,slot is %d\n",n,a,b);
#endif
}

