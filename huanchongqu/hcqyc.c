#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <iostream.h>

int k;
void fun(const char *input)
{
	char buf[8];
	strcpy(buf,input);
	k =(int)buf - (int)&input;// - (int)buf;
	//k = (int)&input - (int)buf;
	printf("%s\n",buf);

}

void haha()
{
	printf("\n ok! success");

}

int main(int argc,char *argv[])
{
	printf("address of fun,%p\n",fun);
	printf("address of haha,%p\n",haha);
	int a = 1;
	int b = 2;
	int c = 3;
	printf("address a is %x\n",&a);
	printf("address b is %x\n",&b);
	printf("address c is %x\n",&c);
	void haha();
	int addr[4];
	char s[] = "findk";
	fun(s);
	printf("k is %d\n",k);
	int go = (int)&haha;
	addr[0] = (go << 24) >> 24;
	addr[1] = (go << 16) >> 24;
	addr[2] = (go << 8) >> 24;
	addr[3] = (go << 24) >> 24;
	char ss[] = "aaaaaaaaaaaaaaaaaaaaaaaaaaaa";
	for(int j = 0;j<4;j++)
	{
		ss[k - j - 1] = addr[3 - j];
	}	

	fun(ss);
	return 0;



}
