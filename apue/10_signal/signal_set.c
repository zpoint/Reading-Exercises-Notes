#include <signal.h>
#include <errno.h>

/*
 * <signal.h> usually defined NSIG to include signal number 0
 * not able to compile in Ubuntu, the implemention of sigset_t is a struct contaning unsigned long array, not an int.
 */

#define SIGBAD(signo) ((signo) <= 0 || (signo) >= NSIG)

int sigaddset(sigset_t *set, int signo)
{
		if (SIGBAD(signo))
		{
				errno = EINVAL;
				return(-1);
		}
		*set |= 1 << (signo - 1); // turn bit on
		return(0);
}

int sigdelset(sigset_t *set, int signo)
{
		if (SIGBAD(signo))
		{
				errno = EINVAL;
				return(-1);
		}
		*set &= ~(1 << (signo - 1));
		return(0);
}

int sigsmember(const sigset_t *set, int signo)
{
		if (SIGBAD(signo))
		{
				errno = EINVAL;
				return(-1);
		}
		return((*set & (1 << (signo - 1))) != 0);
}
