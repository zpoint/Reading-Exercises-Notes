#include "../../lib/unp.h"

void my_dg_echo(int sockfd, SA *pcliaddr, socklen_t clilen)
{
		int n;
		socklen_t len;
		char buf[MAXLINE];

		for ( ; ; )
		{
				len = clilen;
				n = Recvfrom(sockfd, buf, MAXLINE, 0, pcliaddr, &len);
				Sendto(sockfd, buf, n, 0, pcliaddr, len);
				
		}
}

int main(int argc, char **argv)
{
		int sockfd;
		struct sockaddr_un servaddr, cliaddr;

		sockfd = Socket(AF_LOCAL, SOCK_DGRAM, 0);

		unlink(UNIXDG_PATH);
		bzero(&servaddr, sizeof(servaddr));
		servaddr.sun_family = AF_LOCAL;
		strcpy(servaddr.sun_path, UNIXDG_PATH);

		Bind(sockfd, (SA *) &servaddr, sizeof(servaddr));

		my_dg_echo(sockfd, (SA *)&cliaddr, sizeof(cliaddr));
}
