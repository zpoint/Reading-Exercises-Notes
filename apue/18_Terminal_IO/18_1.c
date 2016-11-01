#include "cbreak_craw.c"
#include <stdio.h>

int main(void)
{
		int i;
		char c;
		if (tty_raw(STDIN_FILENO) < 0)
				err_sys("tty_raw error");
		printf("Raw mode, print DELETE to terminate me\n");
		while ((i = read(STDIN_FILENO, &c, 1)) == 1)
		{
				if ((c &= 255) == 0177)
						exit(0);
				printf("%o\n", c);
		}
}
