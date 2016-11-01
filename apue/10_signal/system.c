#include "apue.h"
#include "system.h"
static void sig_int(int signo)
{
		printf("caught SIGINT\n");
}

static void sig_chld(int signo)
{
		printf("caught SIGCHLD\n");
}

static void sig_quit(int signo)
{
		printf("caught SIGQUIT\n");
}

int main(void)
{
		if (signal(SIGINT, sig_int) == SIG_ERR)
				err_sys("signal(SIGINT) error");
		if (signal(SIGCHLD, sig_chld) == SIG_ERR)
				err_sys("signal(SIGCHLD) error");
		if (signal(SIGQUIT, sig_quit) == SIG_ERR)
				err_sys("signal(SIGQUIT) error");
		if (system2("/bin/ed") < 0)
				err_sys("system() error");
		exit(0);
}
