#include "apue.h"
#include "pr_mask.h"

static void sig_usr1(int);
static void sig_int(int);

int main(void)
{
		if (signal(SIGUSR1, sig_usr1) == SIG_ERR)
				err_sys("signal(SIGUSR1) error");
		if (signal(SIGINT, sig_int) == SIG_ERR)
				err_sys("signal(SUGINT) error");
		pr_mask("starting main: ");
		while(1)
				pause();
		return(0);
}

static void sig_usr1(int signo)
{
		pr_mask("Inside sig_usr1: ");
		printf("going to sleep for 5 seconds\n");
		sleep(5);
}

static void sig_int(int singo)
{
		pr_mask("Inside sig_int: ");
		printf("going to sleep for 5 seconds\n");
		sleep(5);
}
