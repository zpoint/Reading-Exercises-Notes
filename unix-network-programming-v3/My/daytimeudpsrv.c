#include "../lib/unp.h"
#include <time.h>

int main(int argc, char **argv)
{
		int listenfd, n;
		socklen_t len;
		struct sockaddr_in servaddr, cliaddr;
		char buff[MAXLINE + 1], buff2[MAXLINE];
		time_t ticks;

		listenfd = Socket(AF_INET, SOCK_DGRAM, 0);
		bzero(&servaddr, sizeof(servaddr));
		servaddr.sin_family = AF_INET;
		servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
		servaddr.sin_port = htons(13); /* daytime server */

		Bind(listenfd, (SA *) &servaddr, sizeof(servaddr));

		for ( ; ; )
		{
				len = sizeof(cliaddr);
				n = recvfrom(listenfd, buff, MAXLINE, 0, (SA *)&cliaddr, &len);
				printf("connection from %s, port %d\n", Inet_ntop(AF_INET, &cliaddr.sin_addr, buff2, sizeof(buff2)), ntohs(cliaddr.sin_port));
				ticks = time(NULL);
				snprintf(buff, sizeof(buff), "%.24s\r\n", ctime(&ticks));
				Sendto(listenfd, buff, strlen(buff), 0, (SA *)&cliaddr, len);
		}
}
