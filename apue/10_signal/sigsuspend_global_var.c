/* Ubuntu 16.04 x64 automatic reset the signal handler to default when a signal occurs(only reset the one occurs), 
* when a signal occurs during a signal handling and they are the same signal, my sys immediately call the default handler of this signal
*/
#include "apue.h"

volatile sig_atomic_t quitflag; // set nonzero by signal handler

static void sig_int(int signo) // one signal handler for SIGINT and SIGQUIT
{
		if (signo == SIGINT)
		{
				printf("\ninterrupt\n");
				if (signal(SIGINT, sig_int) == SIG_ERR)
					err_sys("signal(SIGINT) error");
		}
		else if (signo == SIGQUIT)
		{
				quitflag = 1; // set flag for main loop
				if (signal(SIGQUIT, sig_int) == SIG_ERR)
					err_sys("signal(SIGQUIT) error");
		}
}

int main(void)
{
		sigset_t newmask, oldmask, zeromask;

		if (signal(SIGINT, sig_int) == SIG_ERR)
				err_sys("signal(SIGINT) error");
		if (signal(SIGQUIT, sig_int) == SIG_ERR)
				err_sys("signal(SIGQUIT) error");

		sigemptyset(&zeromask);
		sigemptyset(&newmask);
		sigaddset(&newmask, SIGQUIT);

		// Block SIGQUIT and save current signal mask
		if (sigprocmask(SIG_BLOCK, &newmask, &oldmask) < 0)
				err_sys("SIG_BLOCK error");
		while (quitflag == 0)
				sigsuspend(&zeromask);

		// SIGQUIT has been caught and is now blocked; Do whatever
		quitflag = 0;

		// Reset signal mask which unblocks SIQUIT
		if (sigprocmask(SIG_SETMASK, &oldmask, NULL) < 0)
				err_sys("SIG_SETMASK error");
		exit(0);
}
