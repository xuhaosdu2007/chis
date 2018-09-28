#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

#define MYPORT 8887
//#define ERR_EXIT(m)\
	do{ \
	perror(m);\
	exit(EXIT_FAILURE);\
	}while(0)
char *SERVERIP = "127.0.0.1";
void echo_ser(int sock)
{
	char recvbuf[1024] = {0};
	struct sockaddr_in peeraddr;
	socklen_t peerlen;
	int n;

	while(1)
	{
		peerlen = sizeof(peeraddr);
		memset(recvbuf,0,sizeof(recvbuf));
		n = recvfrom(sock,recvbuf,sizeof(recvbuf),0,(struct sockaddr *)&peeraddr,&peerlen);
		if(n <= 0)
		{
			if(errno = EINTR)
			printf("recv error");
				continue;
			//ERR_EXIT("recvfrom error");
		}
		else if(n > 0)
		{
			printf("recv data is %s\n",recvbuf);
			
			sendto(sock,recvbuf,n,0,(struct sockaddr *)&peeraddr,peerlen);
			printf("send back : %s",recvbuf);
		}
	}
	close(sock);
}

int main(void)
{
	int sock;
	printf("start: \n");
	if((sock = socket(PF_INET,SOCK_DGRAM,0)) < 0)
		printf("socket error\n");//ERR_EXIT("socket error");

	printf("start1: \n");
	struct sockaddr_in servaddr;
	memset(&servaddr,0,sizeof(servaddr));
	printf("start2: \n");
	servaddr.sin_family = AF_INET;
	
	servaddr.sin_port = htons(MYPORT);
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);//inet_addr("127.0.0.1");// htons(SERVERIP);//(INADDR_ANY);

	printf("start3: \n");
	printf("list port is %d\n",MYPORT);
	if(bind(sock,(struct sockaddr *)&servaddr,sizeof(servaddr)) < 0)
	{
		printf("error");
		printf("bind error");//ERR_EXIT("bind error");
	}
	echo_ser(sock);
	return 0;
}
