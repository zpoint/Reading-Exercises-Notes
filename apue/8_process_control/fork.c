/* in command line
 *
 * ./a.out
 * ./a.out > temp.out
 *
 * sizeof calculats buf size at compile time, strlen require a function call
 * as the buffer is initialized with a known string and it's size is fixed
 *
 * write is not buffered
 * stdio library is buffered, line buffered if it's connected to a terminal device, otherwise, it's fully buffered.
 * In the terminal, standard output buffer is flushed by the newline
 *
 * When redirect stdout to a file, it's fully buffered. 
 * The line remains in the buffer when fork is called. 
 * This buffer is then copied into the child when parent's data space is
 * copied to the child, Both parent and child now have stdio buffer with this line in it
 */
#include "apue.h"

int globvar = 6;
char buf[] = "a write to stdout\n";

int main(void)
{
		int var; // automatic variable on the stack
		pid_t pid;

		var = 88;
		if (write(STDOUT_FILENO, buf, sizeof(buf) - 1) != sizeof(buf) - 1)
				err_sys("write error");
		printf("before fork\n"); // don't flush stdout

		if ((pid = fork()) < 0)
				err_sys("fork error");
		else if (pid == 0) // child
		{
				globvar++;
				var++;
		}
		else
				sleep(2); //prent

		printf("pid = %ld, glob = %d, var = %d\n", (long)getpid(), globvar, var);
		exit(0);
}
