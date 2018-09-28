#include <stdio.h>
#include <pthread.h>

void *create(void *arg)
{
	char *num;
	num = (char *)arg;
	printf("create para is %s\n",num);
	return (void *)0;
	
}

int main(int argc, const char *argv[])
{
	pthread_t id1;
	int error;
	int test = 4;
	char *attr = "hello";//&test;
	error = pthread_create(&id1,NULL,create,(void *)attr);
	if (error)
	{
		printf("pthread create is error");
		return -1;
	}
	sleep(1);
	printf("pthread is created\n");
	return 0;
}
