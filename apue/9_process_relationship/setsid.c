#include "apue.h"
static void pr_ids(char *name)
{
		printf("%s: pid = %ld, ppid = %ld, pgrp = %ld, tpgrp = %ld, sid = %ld\n", 
						name, (long)getpid(), (long)getppid(), (long)getpgrp(), (long)tcgetpgrp(STDIN_FILENO), (long)getsid(0));
}
int main(void)
{
		pid_t pid;
		char c;
		pr_ids("before fork");
		if ((pid = fork()) < 0)
				err_sys("fork error");
		else if (pid == 0)
		{
				pr_ids("child before setsid");
				setsid();
				pr_ids("child after setsid");
				if (read(STDIN_FILENO, &c, 1) != 1)
						printf("read error %d on controlling TTY\n", errno);
		}
		else
				pr_ids("Parent");
		exit(0);
}
