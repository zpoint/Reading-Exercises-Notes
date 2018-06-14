#include "../../lib/unp.h"

static int pipefd[2];

static void recvfrom_alarm(int signo)
{
		Write(pipefd[1], "", 1); // write one numm byte to pipe */
		return;
}

void my_dg_cli(FILE *fp, int sockfd, const SA *pservaddr, socklen_t servlen)
{
		int n, maxfdp1;
		const int on = 1;
		char sendline[MAXLINE], recvline[MAXLINE + 1];
		fd_set rset;
		socklen_t len;
		struct sockaddr *preply_addr;

		preply_addr = (struct sockaddr *)Malloc(servlen);

		Setsockopt(sockfd, SOL_SOCKET, SO_BROADCAST, &on, sizeof(on));

		Pipe(pipefd);
		maxfdp1 = max(sockfd, pipefd[0]) + 1;
		FD_ZERO(&rset);

		Signal(SIGALRM, recvfrom_alarm);

		while (Fgets(sendline, MAXLINE, fp) != NULL)
		{
				Sendto(sockfd, sendline, strlen(sendline), 0, pservaddr, servlen);

				alarm(5);
				for ( ; ; )
				{
						FD_SET(sockfd, &rset);
						FD_SET(pipefd[0], &rset);
						if ( (n = select(maxfdp1, &rset, NULL, NULL, NULL)) < 0 )
						{
								if (errno == EINTR)
										continue;
								else
										err_sys("select error");
						}
						if (FD_ISSET(sockfd, &rset))
						{
								len = servlen;
								n = Recvfrom(sockfd, recvline, MAXLINE, 0, preply_addr, &len);
								recvline[n] = 0; /* null terminate */
								printf("from %s: %s", Sock_ntop_host(preply_addr, len), recvline);
						}
						if (FD_ISSET(pipefd[0], &rset))
						{
								Read(pipefd[0], &n, 1); /* timer expired */
								printf("time's up\n");
								break;
						}
				}
		}
}

int main(int argc, char **argv)
{
		struct sockaddr_in servaddr;
		int sockfd;

		if (argc != 2)
				err_quit("usage: <IPaddress>");

		bzero(&servaddr, sizeof(servaddr));
		servaddr.sin_family = AF_INET;
		servaddr.sin_port = htons(13);
		Inet_pton(AF_INET, argv[1], &servaddr.sin_addr.s_addr);

		sockfd = Socket(AF_INET, SOCK_DGRAM, 0);

		my_dg_cli(stdin, sockfd, (SA *)&servaddr, sizeof(servaddr));

		return 0;
}
