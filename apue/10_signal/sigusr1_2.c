/*
 * ./a.out &
 * 7216
 * kill -USR1 7216
 * kill -USR2 7216
 * kill 7216
 */
#include "apue.h"
static void sig_usr(int);

int main(void)
{
		if (signal(SIGUSR1, sig_usr) == SIG_ERR)
				err_sys("can't catch SIGUSR1");
		if (signal(SIGUSR2, sig_usr) == SIG_ERR)
				err_sys("can't catch SIGUSR2");
		for ( ; ; )
				pause(); // simply suspends the calling process until a signal is received
}

static void sig_usr(int signo)
{
		if (signo == SIGUSR1)
				printf("received SIGUSR1\n");
		else if (signo == SIGUSR2)
				printf("receieved SIGUSR2\n");
		else
				err_dump("receieved signal %d\n", signo);
}
