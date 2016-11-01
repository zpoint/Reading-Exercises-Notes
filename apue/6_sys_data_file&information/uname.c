#include "apue.h"
#include <sys/utsname.h>

int main(void)
{
		struct utsname uname_struct;

		if (uname(&uname_struct) < 0)
				err_sys("uname error ");
		printf("os name:         %s\n", uname_struct.sysname);
		printf("node name:       %s\n", uname_struct.nodename);
		printf("current release: %s\n", uname_struct.release);
		printf("current version: %s\n", uname_struct.version);
		printf("hardware type:   %s\n", uname_struct.machine);
		exit(0);
}
