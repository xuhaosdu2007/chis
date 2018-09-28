#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>

#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

#define MYPORT 8887

char *SERVERIP = "127.0.0.1";
#define ERR_EXIT(m)\
	do{ \
	perror(m);\
	exit(EXIT_FAILURE);\
	}while(0)

void echo_cli(int sock)
{
	struct sockaddr_in servaddr;
	memset(&servaddr,0,sizeof(servaddr));
	servaddr.sin_family = AF_INET;
		
	servaddr.sin_port = htons(MYPORT);
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);//inet_addr(SERVERIP);//htons(SERVERIP);

	int ret;
	char sendbuf[1024] = {0};
	char recvbuf[1024] = {0};
	while(fgets(sendbuf,sizeof(sendbuf),stdin) != NULL)
	{
		printf("send is :%s",sendbuf);
		sendto(sock,sendbuf,strlen(sendbuf),0,(struct sockaddr *)&servaddr,sizeof(servaddr));
		ret = recvfrom(sock,recvbuf,sizeof(recvbuf),0,NULL,NULL);
		if(ret == -1)
		{
			printf("error recv");
		}
		printf("recv from server :%s",recvbuf);
		memset(sendbuf,0,sizeof(sendbuf));
		memset(recvbuf,0,sizeof(recvbuf));
	}
	close(sock);
}

int main(void)
{
	int sock;
	printf("start:\n");
	if((sock = socket(PF_INET,SOCK_DGRAM,0)) < 0)
		ERR_EXIT("socket error");
	echo_cli(sock);
	return 0;
}
