/*
	test mmap fun between processes, process 1 printf mapped everty two seconds
*/
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <error.h>

int main(int argc, char *argv[])
{
	int fd,nread;
	struct stat sb;
	char *mapped;

printf("start:\n");
//open file
	if((fd = open(argv[1], O_RDWR)) < 0)
	{
		perror("open \n");
	}
//file property
	if((fstat(fd, &sb) == -1))
	{
		perror("fstat \n");
	}
//mmap file
if((mapped = mmap(NULL, sb.st_size, PROT_READ|\
	PROT_WRITE,MAP_SHARED, fd, 0)) == (void *) -1)
{
	perror("mmap \n");
} 

// chage a char mmap
mapped[20] = '8';
//if((msync((void *)mapped, sb.st_size, MS_SYNC)) == -1)
//	perror("msync \n");

//unmmap
//if((munmap((void *)mapped,sb.st_size)) == -1)
//	perror("munmap");

// close file
close(fd);
//printf mmap every 2 seconds

while(1)
{
	printf("%s\n",mapped);
	sleep(2);
}

return 0;

}
