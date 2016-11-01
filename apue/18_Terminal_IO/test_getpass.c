#include "apue.h"
#include "getpass.c"

int main(void)
{
		char *ptr;

		if ((ptr = getpass("Enter password:")) == NULL)
				err_sys("getpass error");
		printf("password: %s\n", ptr);

		// now use password (probably encrypt it) ...
		while (*ptr != 0)
				*ptr++ = 0; // zero it out when we're done with it
		exit(0);
}
