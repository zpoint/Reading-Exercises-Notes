#include "../../lib/unp.h"
#include "write_fd.c"

int main(int argc, char **argv)
{
		int fd;

		if (argc != 4)
				err_quit("openfile <sockfd#> <filename> <mode>");

		if ( (fd = open(argv[2], atoi(argv[3]))) < 0 )
				exit(errno > 0 ? errno : 255);

		if ( my_write_fd(atoi(argv[1]), (void *)"", 1, fd) < 0 )
				exit((errno > 0) ? errno : 255);

		exit(0);
}
