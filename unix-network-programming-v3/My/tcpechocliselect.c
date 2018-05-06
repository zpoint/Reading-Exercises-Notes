#include "../lib/unp.h"

void str_cli_select(FILE *fp, int sockfd)
{
		int maxfdp1;
		fd_set rset;
		char sendline[MAXLINE], recvline[MAXLINE];

		FD_ZERO(&rset);
		for ( ; ; )
		{
				FD_SET(fileno(fp), &rset);
				FD_SET(sockfd, &rset);
				maxfdp1 = max(fileno(fp), sockfd) + 1;
				Select(maxfdp1, &rset, NULL, NULL, NULL);

				if (FD_ISSET(sockfd, &rset))
				{
						/* socket is readable */
						if (Readline(sockfd, recvline, MAXLINE) == 0)
								err_quit("str_cli: server terminated prematurely");
						Fputs(recvline, stdout);
				}

				if (FD_ISSET(fileno(fp), &rset))
				{
						/* input is readable */
						if (Fgets(sendline, MAXLINE, fp) == NULL)
								return; /* all done */
						Writen(sockfd, sendline, strlen(sendline));
				}
		}
}

void str_cli_select_handle_eof(FILE *fp, int sockfd)
{
		int maxfdp1, stdineof;
		fd_set rset;
		char buf[MAXLINE];
		int n;

		stdineof = 0;
		FD_ZERO(&rset);
		for ( ; ; )
		{
				if (stdineof == 0)
						FD_SET(fileno(fp), &rset);
				FD_SET(sockfd, &rset);
				maxfdp1 = max(fileno(fp), sockfd) + 1;
				Select(maxfdp1, &rset, NULL, NULL, NULL);

				if (FD_ISSET(sockfd, &rset)) // socket is readable
				{
						if ( (n = Read(sockfd, buf, MAXLINE)) == 0 )
						{
								if (stdineof == 1)
										return; /* normal termination */
								else
										err_quit("str_cli: server terminated prematurely");
						}

						Write(fileno(stdout), buf, n);
				}

				if (FD_ISSET(fileno(fp), &rset)) // input is readable
				{
						if ( (n = Read(fileno(fp), buf, MAXLINE)) == 0 )
						{
								stdineof = 1;
								Shutdown(sockfd, SHUT_WR); /* send FIN */
								FD_CLR(fileno(fp), &rset);
								continue;
						}
						
						Writen(sockfd, buf, n);
				}
		}
}

int main(int argc, char **argv)
{
		int sockfd;
		struct sockaddr_in servaddr;

		if (argc != 2)
				err_quit("usage: tcpcli <IPaddress>");

		sockfd = Socket(AF_INET, SOCK_STREAM, 0);

		bzero(&servaddr, sizeof(servaddr));
		servaddr.sin_family = AF_INET;
		servaddr.sin_port = htons(SERV_PORT);
		Inet_pton(AF_INET, argv[1], &servaddr.sin_addr);

		Connect(sockfd, (SA *) &servaddr, sizeof(servaddr));
		str_cli_select_handle_eof(stdin, sockfd);
		exit(0);
}
