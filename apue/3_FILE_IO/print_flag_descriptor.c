#include "apue.h"
#include <fcntl.h>

int main(int argc, char *argv[])
{
		int val;
		if (argc != 2)
				err_quit("usage: a.out <descriptor#>");
		if ((val = fcntl(atoi(argv[1]), F_GETFL, 0)) < 0)
				err_sys("fcntl error for fd %d", atoi(argv[1]));
		switch (val & O_ACCMODE)
		{
				case O_RDONLY:
						printf("read only");
						break;
				case O_WRONLY:
						printf("write only");
						break;
				case O_RDWR:
						printf("read write");
						break;
				default:
						err_dump("unknown access mode");
		}
		if (val & O_APPEND)
				printf(", append");
		if (val & O_NONBLOCK)
				printf(", nonblocking");
		if (val & O_SYNC)
				printf(", synchronous writes");

#if !defined(_POSIX_C_SOURCE) && defined(O_FSYNC) && (OFSYNC != O_SYNC)
		if (val & O_FSYNC)
				printf(", synchronous write for O_FSYNC");
#endif
		putchar('\n');
		exit(0);
}
/*
./a.out 0 < /dev/tty
./a.out 1 > temp.foo
cat temp.foo
./a.out 2 2>>temp.foo
./a.out 5 5<>temp.foo
*/

void set_fl(int fd, int flags)
{
		int val;
		if ((val = fcntl(fd, F_GETFL, 0)) < 0)
				err_sys("fcntl F_GETFL error");
		val |= flags; //turn on flags
		// val &= flags; // to turn off flags
		if (fcntl(fd, F_SETFL, val) < 0)
				err_sys("fcntl F_SETFL error");
}
