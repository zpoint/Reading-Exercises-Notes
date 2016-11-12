#include "csapp.c"
sigjmp_buf buf;
int n,b;
char buff[MAXBUF];
pid_t pid;
void handler(int sig)
{
	siglongjmp(buf,1);
}
void handler1(int sig)
{
	siglongjmp(buf,2);
}
int main()
{
	Signal(SIGINT,handler);
	Signal(SIGUSR1,handler1);
	if(sigsetjmp(buf,1))
	{
		printf("restarting 1\n");
		b = 1;
	}
	else if(sigsetjmp(buf,2))
	{
		waitpid(pid,NULL,0);
		printf("%d reaped\n",pid);
	}
	else
		printf("starting\n");
	if(b != 1 && ((pid = fork()) == 0))
		{
			while((n = read(STDIN_FILENO,buff,sizeof(buff))) > 0)
			{
				kill(pid,SIGUSR1);
			}
		}
	while(1)
	{
		Sleep(1);
		printf("Processing monther!\n");
	}
	exit(0);
}
