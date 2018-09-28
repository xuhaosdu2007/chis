/* write and read file 
a.ini ,test for record spi para :bmu cs gpio  

*/
#include <stdio.h>
#include <unistd.h>
#include <string.h>

unsigned char weichushi[1000];
unsigned int am = 111;
unsigned char quanju[100] = {1};
unsigned char *a = "hello world";

int main(int argc, char * *argv)
{
	unsigned int len;
	unsigned int bmu = 0;
	unsigned int cs = 0;
	unsigned int device = 0;
	unsigned char num = 2;
	unsigned char let[10] = "0-0-0------";
	unsigned char quan[100] = {0};
	unsigned char buff[10];
	//if(argv[1] != NULL)
	//{
		for(int n = 0;n< 1000;n++)
		{
			malloc(10);
			sleep(1);
		}
		if(argv[1][0] >= '0')
		bmu = argv[1][0] - '0';//atoi(argv[1][0]);//,NULL,0);
		printf("bmu is %d\n",bmu);
		FILE *fp = fopen("/home/autobuild/xh/a.ini","w");
		if(fp !=NULL)
		{
			let[0] = '0' + (bmu - 0);
			let[2] = '0' + (argv[2][0] - '0');
			let[4] = '0' + (argv[3][0] - '0');
			fwrite(&let,10,1,fp);
			fclose(fp);
		}
		FILE *tp = fopen("/home/autobuild/xh/a.ini","r");
		if(tp !=NULL)
		{
			len = fread(buff,1,10,tp);
			bmu = buff[0] - '0';
			cs = buff[2] - '0';
			device = buff[4] - '0';
			printf("len is %d,bmu is %d,cs is %d,device is %d\n",len,bmu,cs,device);
		}
	//}
}
