#include "../../lib/unp.h"
#include "tcp_listen.h"

int main(int argc, char **argv)
{
		int listenfd, connfd;
		socklen_t len;
		char buff[MAXLINE];
		time_t ticks;
		struct sockaddr_storage cliaddr;

		if (argc != 2)
				err_quit("usage: daytimetcpsrv <service or port#>");

		listenfd = my_tcp_listen(NULL, argv[1], NULL);

		for ( ; ; )
		{
				len = sizeof(cliaddr);
				connfd = Accept(listenfd, (SA *) &cliaddr, &len);
				printf("connection from %s\n", Sock_ntop((SA *) &cliaddr, len));

				ticks = time(NULL);
				snprintf(buff, sizeof(buff), "%.24s\r\n", ctime(&ticks));
				Write(connfd, buff, strlen(buff));

				Close(connfd);
		}
}
