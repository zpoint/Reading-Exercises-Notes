#include "apue.h"
int sig2str(int signo, char *str);

extern const char *const sys_siglist[];

int main(void)
{
		printf("I am going to print signal name and number in the sys_siglist:\n");
		int i = 1;
		char name[100];
		while (sys_siglist[i] != NULL)
		{
				sig2str(i, name);
				printf("%s : %d\n", name, i);
				++i;
		}
}

int sig2str(int signo, char *str)
{
		const char *ptr = sys_siglist[signo];
		if (ptr != NULL)
		{
				int i = 0;
				for (; ptr[i] != '\0'; i++)
						str[i] = ptr[i];
				str[i] = '\0';
		}
		else
		{
				char *nil = "NULL";
				for (int i = 0; i < 4; i++)
						str[i] = nil[i];
		}
		return(0);
}
