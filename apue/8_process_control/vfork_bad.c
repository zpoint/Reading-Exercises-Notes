#include "apue.h"
int fork_fun(void);

int main(void)
{
		int i;
		printf("IN main, caling fork_fun...\n");
		i = fork_fun();
		printf("fork_fun:%d\n", i);
		_exit(0);
}

int fork_fun(void)
{
		pid_t pid;
		if ((pid = vfork()) < 0)
				err_sys("vfork error");
		printf("pid: %d\n", pid);
		if (pid != 0)
		{
				printf("vfork parent pid: %d\n", pid);
				sleep(3);
				printf("after sleep\n");
				return 1;
		}
		else
		{
				printf("child pid: %d\n", pid);
				return 2;
		}
		
}

