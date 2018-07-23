#pragma once
#include "../../lib/unpipc.h"

Sigfunc_rt *signal_rt(int signo, Sigfunc_rt *func, sigset_t *mask)
{
		struct sigaction act, oact;

		act.sa_sigaction = func; /* must store function addr here */
		act.sa_mask = *mask; /* signals to block */
		act.sa_flags = SA_SIGINFO; /* must specify this for realtime */
		if (signo == SIGALRM)
		{
#ifdef SA_INTERRUPT
				act.sa_flags |= SA_INTERRUPT; /* SunOS 4.x */
#endif 
	    } else {
#ifdef SA_RESTART
			act.sa_flags |= SA_RESTART; /* SVR4, 4.4BSD */
#endif
			if (sigaction(signo, &act, &oact) < 0)
					return ( (Sigfunc_rt *) SIG_ERR);
			return (oact.sa_sigaction);
}
