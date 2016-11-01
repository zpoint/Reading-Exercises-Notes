// send data from parent to child over a pipe
#include "apue.h"

int main(void)
{
		int n;
		int fd[2];
		pid_t pid;
		char buf[MAXLINE];
		char line[MAXLINE];

		if (pipe(fd) < 0)
				err_sys("pipe error");
		if ((pid = fork()) < 0)
				err_sys("fork error");
		else if (pid > 0) // parent
		{
				close(fd[0]);
				snprintf(buf, 41, "hello, I am parent, writing to fd[1]: %d\n", fd[1]);
				write(fd[1], buf, strlen(buf));
				//printf("writed to fd[1]: %s\n", buf);
		}
		else // child
		{
				close(fd[1]);
				n = read(fd[0], line, MAXLINE);
				write(STDOUT_FILENO, line, n);
				//printf("readed in child: %s\n", line);
		}
		exit(0);
}
