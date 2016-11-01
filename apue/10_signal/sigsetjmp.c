/* ./a.out &
* kill -USR1 531
* press Enter
* It doesn't block same signal when handling signal, compile the aupe source code results the same, Don't know why
* But the compiled program mask, When I run it, it does block signal when handling it (kill twice)
* Other example calling sigprocmask function behave correctly
*/ 


#include "apue.h"
#include "pr_mask.h"
#include <setjmp.h>
#include <time.h>

static void sig_usr1(int);
static void sig_alrm(int);

static sigjmp_buf jmpbuf;
static volatile sig_atomic_t canjump;

int main(void)
{
		if (signal(SIGUSR1, sig_usr1) == SIG_ERR)
				err_sys("signal(SIGUSR1) error");
		if (signal(SIGALRM, sig_alrm) == SIG_ERR)
				err_sys("signal(SIGALRM) error");
		pr_mask("staring main: ");
		if (sigsetjmp(jmpbuf, 1))
		{
			pr_mask("ending main: ");
			exit(0);
		}
		canjump = 1; // now sigsetjmp() is OK
		for ( ; ; )
				pause();
}

static void sig_usr1(int signo)
{
		time_t starttime;
		if (canjump == 0)
				return; // unexpected signal, ignore
		pr_mask("starting sig_usr1: ");
		alarm(3); // SIGALRM in 3 seconds
		starttime = time(NULL);  // busy wait for 5 seconds
		for ( ; ; )
				if (time(NULL) > starttime + 5)
						break;
		pr_mask("finishing sig_usr1: ");
		canjump = 0;
		siglongjmp(jmpbuf, 1); // jump back to main, don't return
}

static void sig_alrm(int signo)
{
		pr_mask("in sig_alrm: ");
}
