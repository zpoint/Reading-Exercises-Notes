#include "../lib/unp.h"

void my_str_echo(int sockfd)
{
		ssize_t n;
		char recvline[MAXLINE];
again:
		while ( (n = Read(sockfd, recvline, MAXLINE)) > 0 )
				Writen(sockfd, recvline, n);

		if (n < 0 && errno == EINTR)
				goto again;
		else if (n < 0)
				err_sys("read error");
}

void sig_chld(int signo)
{
		int stat;
		pid_t pid;
		while ((pid = waitpid(-1, &stat, WNOHANG)) > 0)
				printf("child %d terminate\n", pid);
		return;
}

int main(int argc, char **argv)
{
		int listenfd, connfd, udpfd, nready, maxfdp1;
		char mesg[MAXLINE];
		pid_t childpid;
		fd_set rset;
		ssize_t n;
		socklen_t len;
		const int on = 1;
		struct sockaddr_in cliaddr, servaddr;

		/* create listening TCP socket */
		listenfd = Socket(AF_INET, SOCK_STREAM, 0);

		bzero(&servaddr, sizeof(servaddr));
		servaddr.sin_family = AF_INET;
		servaddr.sin_port = htons(SERV_PORT);
		servaddr.sin_addr.s_addr = htonl(INADDR_ANY);

		Setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on));
		Bind(listenfd, (SA *) &servaddr, sizeof(servaddr));

		Listen(listenfd, LISTENQ);

		/* create UDP socket */
		udpfd = Socket(AF_INET, SOCK_DGRAM, 0);

		bzero(&servaddr, sizeof(servaddr));
		servaddr.sin_family = AF_INET;
		servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
		servaddr.sin_port = htons(SERV_PORT);

		Bind(udpfd, (SA *) &servaddr, sizeof(servaddr));
		Signal(SIGCHLD, sig_chld);

		FD_ZERO(&rset);
		maxfdp1 = max(listenfd, udpfd) + 1;
		for ( ; ; )
		{
				FD_SET(listenfd, &rset);
				FD_SET(udpfd, &rset);
				if ( (nready = select(maxfdp1, &rset, NULL, NULL, NULL)) < 0 )
				{
						if (errno == EINTR)
								continue;
						else
								err_sys("select error");
				}

				if (FD_ISSET(listenfd, &rset))
				{
						len = sizeof(cliaddr);
						connfd = Accept(listenfd, (SA *) &cliaddr, &len);

						if ((childpid = Fork()) == 0) /* child process */
						{
								Close(listenfd); /* close listening socket */
								my_str_echo(connfd);
								exit(0);
						}
						Close(connfd);  /* parent closes connected socket */ 
				}

				if (FD_ISSET(udpfd, &rset))
				{
						len = sizeof(cliaddr);
						n = Recvfrom(udpfd, mesg, MAXLINE, 0, (SA *) &cliaddr, &len);
						Sendto(udpfd, mesg, n, 0, (SA *) &cliaddr, len);
				}
		}

		return 0;
}
