#include "apue.h"
#define maxline 4
int main(void)
{
		char buf[maxline];
		while (fgets(buf, maxline, stdin) != NULL)
				if (fputs(buf, stdout) == EOF)
						err_sys("output error");

		if (ferror(stdin))
				err_sys("input error");

		exit(0);
}
