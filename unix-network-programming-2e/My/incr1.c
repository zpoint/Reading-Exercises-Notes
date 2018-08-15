#include "../../lib/unpipc.h"

#define SEM_NAME "mysem"

int count = 0;

int main(int argc, char **argv)
{
		int i, nloop;
		sem_t *mutex;

		if (argc != 2)
				err_quit("usage: incr <#loops>");
		nloop = atoi(argv[1]);

		/* create, initialize, and unlink semaphore */
		mutex = Sem_open(Px_ipc_name(SEM_NAME), O_CREAT | O_EXCL, FILE_MODE, 1);
		Sem_unlink(Px_ipc_name(SEM_NAME));

		setbuf(stdout, NULL); /* stdout is unbiffered */
		if (Fork() == 0)
		{
				/* child */
				for (i = 0; i < nloop; i++)
				{
						Sem_wait(mutex);
						printf("child: %d\n", count++);
						Sem_post(mutex);
				}
				exit(0);
		}
		/* parent */
		for (i = 0; i < nloop; i++)
		{
				Sem_wait(mutex);
				printf("parent: %d\n", count++);
				Sem_post(mutex);
		}
		exit(0);
}
