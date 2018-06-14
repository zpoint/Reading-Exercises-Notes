#include "../../lib/unp.h"

void my_str_cli(FILE *fp, int sockfd)
{
		char sendline[MAXLINE], recvline[MAXLINE];

		while (Fgets(sendline, MAXLINE, fp) != NULL)
		{
				Writen(sockfd, sendline, strlen(sendline));
				if (Readline(sockfd, recvline, MAXLINE) == 0)
						err_quit("my_str_cli: server terminate prematurely");
				Fputs(recvline, stdout);
		}
}

int main(int argc, char **argv)
{
		int sockfd;
		struct sockaddr_un servaddr;

		sockfd = Socket(AF_LOCAL, SOCK_STREAM, 0);
		bzero(&servaddr, sizeof(servaddr));
		servaddr.sun_family = AF_LOCAL;
		strcpy(servaddr.sun_path, UNIXSTR_PATH);

		Connect(sockfd, (SA *) &servaddr, sizeof(servaddr));

		my_str_cli(stdin, sockfd);
		exit(0);
}
