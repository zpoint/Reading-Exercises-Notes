#include "../lib/unp.h"

static void recvfrom_int(int);
static int count;

void my_dg_echo(int sockfd, SA *pcliaddr, socklen_t clilen)
{
		socklen_t len;
		char mesg[MAXLINE];

		Signal(SIGINT, recvfrom_int);

		for ( ; ; )
		{
				len = clilen;
			   	Recvfrom(sockfd, mesg, MAXLINE, 0, pcliaddr, &len);
				count++;	
		}
}

static void recvfrom_int(int signo)
{
		printf("\nreceived %d datagram\n", count);
		exit(0);;
}

int main(int argc, char **argv)
{
		struct sockaddr_in servaddr, cliaddr;
		int sockfd;

		servaddr.sin_family = AF_INET;
		servaddr.sin_port = htons(SERV_PORT);
		servaddr.sin_addr.s_addr = htons(INADDR_ANY);

		sockfd = Socket(AF_INET, SOCK_DGRAM, 0);
		Bind(sockfd, (SA *)&servaddr, sizeof(servaddr));

		my_dg_echo(sockfd, (SA *) &cliaddr, sizeof(cliaddr));

		return 0;	
}
