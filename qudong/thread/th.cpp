#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <memory.h>
#include <sys/ioctl.h>

#include "pthread.h"

unsigned char data[6001]={0};
unsigned char res[6001]={0};

unsigned crc_sum = 0;
unsigned crc_get(unsigned char *buff,unsigned int len)
{
	unsigned char res = 0;
	if(len > 6000)
		return 0;
	
	for(int i = 0;i < len;i++)
		res = res + buff[i];
	
	return res;
}
//read file
int readFile(char *fileName, unsigned char *buff)
{
	FILE *fp = fopen(fileName, "rb");

	if(fp == NULL)
		return -1;

	int len = 0;

	while(fread(&buff[len], 1, 1, fp) > 0)
		len++ ;

	fclose(fp);
	return len;
}

//write file
void jd_write_file(char *fileName, unsigned char *buff, int len)
{
    FILE *f = fopen(fileName, "wb");
	if(f == NULL)
	{
		printf(" file is null\n");
		return;
	}
    fwrite((const void *)buff, len, 1, f);
    fclose(f);
}

int main(int argc,char **argv)
{
	int run_time = 0;
	int cal_right = 0;
	int cal_error = 0;
	srand((int)time(0));
	while(1)
	{	
		run_time++;
		sleep(2);
		for(int tmp = 0;tmp < 6001 ;tmp++)
		{
			data[tmp] = (unsigned char)(rand()); 
			usleep(10);
		}
		sleep(2);
		unsigned char crc_result = crc_get(data,6000);
		data[6000] = crc_result;
	    jd_write_file("/dev/shm/jd/file_test", data, 6001);

		sleep(10);
		
		unsigned int len = readFile("/dev/shm/jd/file_test", res);
		if(6001 == len)
		{
			
			unsigned char crc_read_result = crc_get(res,6000);

			if(crc_read_result == res[6000])
			{
				cal_right++;
				printf("run_time is %d , cal_right is %d , res_crc %d \n",run_time,cal_right,res[6000]);
				for(int j = 0;j<100;j++)
				{
					
					printf(" %d " ,res[j]);
				}
				printf(" \n " );
			}
			else
			{
				cal_error++;
				printf("cal_error is %d \n",cal_error);
			}
		}
		else
		{
				cal_error++;
				printf("cal_error is %d \n",cal_error);
		}
	}
}
