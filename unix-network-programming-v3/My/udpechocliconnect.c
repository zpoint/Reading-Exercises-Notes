#include "../lib/unp.h"

void my_dg_cli(FILE *fp, int sockfd)
{
		char recvline[MAXLINE + 1], sendline[MAXLINE];
		int n;

		while ( Fgets(sendline, MAXLINE, fp) != NULL)
		{
				Send(sockfd, sendline, strlen(sendline), 0);
				n = Recvfrom(sockfd, recvline, MAXLINE, 0, NULL, NULL);
				recvline[n] = 0;
				Fputs(recvline, stdout);
		}
}

int main(int argc, char **argv)
{
		struct sockaddr_in servaddr, cliaddr;
		int sockfd;
		socklen_t len;
		
		if (argc != 2)
				err_quit("usage: udpechocliconnect <IPaddress>");

		servaddr.sin_family = AF_INET;
		servaddr.sin_port = htons(SERV_PORT);
		Inet_pton(AF_INET, argv[1], &servaddr.sin_addr);

		sockfd = Socket(AF_INET, SOCK_DGRAM, 0);
		Connect(sockfd, (SA *) &servaddr, sizeof(servaddr));

		len = sizeof(cliaddr);
		Getsockname(sockfd, (SA *) &cliaddr, &len);
		printf("local address %s\n", Sock_ntop((SA *) &cliaddr, len));
		my_dg_cli(stdin, sockfd);
		return 0;
}
