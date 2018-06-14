#include "../../lib/unp.h"

void my_sig_chld(int signal)
{
		pid_t pid;
		int stat;

		while ((pid = waitpid(-1, &stat, WNOHANG)) > 0)
				printf("child %d terminate\n", pid);
		return;
}

void my_str_echo(int connfd)
{
		ssize_t n;
		char buffer[MAXLINE];

again:
		while ((n = read(connfd, buffer, MAXLINE)) > 0)
				Writen(connfd, buffer, n);
		if (n < 0 && errno == EINTR)
				goto again;
		else if (n < 0)
				err_sys("my_str_echo error");
}

int main(int argc, char **argv)
{
		int listenfd, connfd;
		pid_t childpid;
		socklen_t clilen;
		struct sockaddr_un cliaddr, servaddr;

		listenfd = Socket(AF_LOCAL,SOCK_STREAM, 0);

		unlink(UNIXSTR_PATH);
		bzero(&servaddr, sizeof(servaddr));
		servaddr.sun_family = AF_LOCAL;
		strcpy(servaddr.sun_path, UNIXSTR_PATH);

		Bind(listenfd, (SA *)&servaddr, sizeof(servaddr));

		Listen(listenfd, LISTENQ);

		Signal(SIGCHLD, my_sig_chld);

		for ( ; ; )
		{
				clilen = sizeof(cliaddr);
				if ( (connfd = accept(listenfd, (SA *) &cliaddr, &clilen)) < 0 )
				{
						if (errno == EINTR)
								continue;  /* back to for */
						else
								err_sys("accept error");
				}
				if ( (childpid = Fork()) == 0 )
				{
						/* child process */
						Close(listenfd); /* close listening socket */
						my_str_echo(connfd); /* process request */
						exit(0);
				}
				Close(connfd); /* parent closes connected socket */
		}
}
