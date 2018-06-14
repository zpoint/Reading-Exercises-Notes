#include "../lib/unp.h"
#include "NonBlockingIO/strclinonb.c"
#include "NonBlockingIO/strclifork.c"

struct args 
{
		long arg1;
		long arg2;
};

struct result
{
		long sum;
};

void my_str_cli(FILE *fp, int sockfd)
{
		char sendline[MAXLINE], recvline[MAXLINE];

		while (Fgets(sendline, MAXLINE, fp) != NULL)
		{
				Writen(sockfd, sendline, strlen(sendline));

				if (Readline(sockfd, recvline, MAXLINE) == 0)
				{
						err_quit("str_cli: server terminated prematurely");
				}
				Fputs(recvline, stdout);
		}
}

void my_str_cli2(FILE *fp, int sockfd)
{
		char sendline[MAXLINE], recvline[MAXLINE];
		while (Fgets(sendline, MAXLINE, fp) != NULL)
		{
				Writen(sockfd, sendline, 1);
				sleep(1);
				Writen(sockfd, sendline + 1, strlen(sendline) - 1);

				if (Readline(sockfd, recvline, MAXLINE) == 0)
						err_quit("str_cli: server terminated prematurely");

				Fputs(recvline, stdout);
		}
}

void str_cli_binary(FILE *fp, int sockfd)
{
		char sendline[MAXLINE];
		struct args args;
		struct result result;

		while (Fgets(sendline, MAXLINE, fp) != NULL)
		{
				if (sscanf(sendline, "%ld%ld", &args.arg1, &args.arg2) != 2)
				{
						printf("invalid input: %s", sendline);
						continue;
				}
				Writen(sockfd, &args, sizeof(args));

				if (Readn(sockfd, &result, sizeof(result)) == 0)
						err_quit("str_cli: server terminated prematurely");

				printf("%ld\n", result.sum);
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
		// str_cli_nonblock(stdin, sockfd);
		str_cli_fork(stdin, sockfd);
		exit(0);
}
