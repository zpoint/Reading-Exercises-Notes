#include "../lib/unp.h"

struct args
{
		long arg1;
		long arg2;
};

struct result
{
		long sum;
};

void my_str_echo(int sockfd)
{
		ssize_t n;
		char buf[MAXLINE];
again:
		while ( (n = read(sockfd, buf, MAXLINE)) > 0 )
				Writen(sockfd, buf, n);

		if (n < 0 && errno == EINTR)
				goto again;
		else if (n < 0)
				err_sys("my_str_echo: read error");
}

void str_echo_sum_two(int sockfd)
{
		long arg1, arg2;
		ssize_t n;
		char line[MAXLINE];

		for ( ; ; )
		{
				if ( (n = Readline(sockfd, line, MAXLINE)) == 0)
						return; /* connection closed by other end */

				if (sscanf(line, "%ld%ld", &arg1, &arg2) == 2)
						snprintf(line, sizeof(line), "%ld\n", arg1 + arg2);
				else
						snprintf(line, sizeof(line), "input error\n");

				n = strlen(line);
				Writen(sockfd, line, n);
		}
}

void str_echo_binary(int sockfd)
{
		ssize_t n;
		struct args args;
		struct result result;

		for ( ; ; )
		{
				if ( (n = Readn(sockfd, &args, sizeof(args))) == 0 )
						return; /* connection closed by other end */

				result.sum = args.arg1 + args.arg2;
				Writen(sockfd, &result, sizeof(result));
		}
}

void sig_chld(int signo)
{
		pid_t pid;
		int stat;

		pid = wait(&stat);
		printf("child %d terminated\n", pid);
		return;
}

void good_sig_chld(int signo)
{
		pid_t pid;
		int stat;

		while ( (pid = waitpid(-1, &stat, WNOHANG)) > 0 )
				printf("child %d terminated\n", pid);
		return;
}

int main(int argc, char **argv)
{
		int listenfd, connfd;
		pid_t childpid;
		socklen_t chilen;
		struct sockaddr_in cliaddr, servaddr;

		listenfd = Socket(AF_INET, SOCK_STREAM, 0);

		bzero(&servaddr, sizeof(servaddr));
		servaddr.sin_family = AF_INET;
		servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
		servaddr.sin_port = htons(SERV_PORT);

		Bind(listenfd, (SA *) &servaddr, sizeof(servaddr));

		Listen(listenfd, LISTENQ);

		Signal(SIGCHLD, good_sig_chld);
		for ( ; ; )
		{
				chilen = sizeof(cliaddr);
				connfd = Accept(listenfd, (SA *) &cliaddr, &chilen);

				if ( (childpid = Fork()) == 0)
				{
						Close(listenfd);
					    my_str_echo(connfd);
						exit(0);
				}

				Close(connfd);
		}
}
