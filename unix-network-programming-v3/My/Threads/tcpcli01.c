#include "../../lib/unp.h"
#include "strclithread.c"

int main(int argc, char **argv)
{
		int sockfd;
		if (argc == 2)
				sockfd = Tcp_connect(NULL, argv[1]);
		else if (argc == 3)
				sockfd = Tcp_connect(argv[1], argv[2]);
		else
				err_quit("usage: tcpcli01 [ <host> ] port");

		my_str_cli(stdin, sockfd);
		exit(0);
}
