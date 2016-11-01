/* avoid zombie processes by calling fork twice */
#include "apue.h"
#include <sys/wait.h>

int main(void)
{
		pid_t pid;
		if ((pid = fork()) < 0)
				err_sys("fork error");
		else if (pid == 0)
		{
				if ((pid = fork()) < 0)
						err_sys("fork error");
				else if (pid > 0)
						exit(0); // parent from second fork == first child

				/*We're the swcond child; our parent becomes init as soon as our real 
				 * parent calls exit() in the statement above. Here's where we'd continue
				 * executing, knowing that when we're done, init will reap our status
				 */
				sleep(2);
				printf("second child, parent pid = %ld\n", (long)getppid());
				exit(0);
		}

		if (waitpid(pid, NULL, 0) != pid)
				err_sys("waitpid error");

		//parent (original process)
		exit(0);
}
