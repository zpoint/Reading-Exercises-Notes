#include "apue.h"
#include "pr_exit.h"
/*
 * tsys printuids
 * su
 * chown root tsys
 * chmod u+s tsys
 * ls -l tsys
 * exit
 * tsys printuids
 */

int main(int argc, char *argv[])
{
		int status;

		if (argc < 2)
				err_quit("command-line argument required");

		if ((status = system(argv[1])) < 0)
				err_sys("system() error");
		printf("real uid = %d, effective uid = %d\n", getuid(), geteuid());
		pr_exit(status);
		exit(0);
}
