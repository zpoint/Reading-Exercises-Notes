/*
 * Command line
 * ./a.out
 * ./a.out </etc/passwd
 * ./a.out </etc/passwd 2>/dev/nukk
 * To see the result
 */

#include "apue.h"
#include "isatty.c"

int main(void)
{
		printf("fd 0: %s\n", isatty(0) ? "tty" : "not a tty");
		printf("fd 1: %s\n", isatty(1) ? "tty" : "not a tty");
		printf("fd 2: %s\n", isatty(2) ? "tty" : "not a tty");
		exit(0);
}
