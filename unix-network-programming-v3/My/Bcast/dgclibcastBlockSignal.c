#include "../../lib/unp.h"

static void recvfrom_alarm(int signo)
{
		return;
}

void my_dg_cli(FILE *fp, int sockfd, const SA *pservaddr, socklen_t servlen)
{
		int n;
		const int on = 1;
		char sendline[MAXLINE], recvline[MAXLINE + 1];
		sigset_t sigset_alrm;
		socklen_t len;
		struct sockaddr *preply_addr;

		preply_addr = (SA *)Malloc(servlen);

		Setsockopt(sockfd, SOL_SOCKET, SO_BROADCAST, &on, sizeof(on));

		Sigemptyset(&sigset_alrm);
		Sigaddset(&sigset_alrm, SIGALRM);
		Signal(SIGALRM, recvfrom_alarm);

		while (Fgets(sendline, MAXLINE, fp) != NULL)
		{
				Sendto(sockfd, sendline, strlen(sendline), 0, pservaddr, servlen);

				alarm(5);
				for ( ; ; )
				{
						len = servlen;
						Sigprocmask(SIG_UNBLOCK, &sigset_alrm, NULL);
						n = recvfrom(sockfd, recvline, MAXLINE, 0, preply_addr, &len);
						Sigprocmask(SIG_BLOCK, &sigset_alrm, NULL);
						if (n < 0)
						{
								if (errno == EINTR)
								{
										printf("time's up\n");
										break;
								}
								else
										err_sys("recvfrom error");
						}
						else
						{
								recvline[n] = 0; /* null terminate */
								printf("from %s: %s", Sock_ntop_host(preply_addr, len), recvline);
						}
				}
		}
		free(preply_addr);
}

int main(int argc, char **argv)
{
		struct sockaddr_in servaddr;
		int sockfd;

		if (argc != 2)
				err_quit("usage: <IPaddress>");

		bzero(&servaddr, sizeof(servaddr));
		servaddr.sin_family = AF_INET;
		servaddr.sin_port = htons(13);
		Inet_pton(AF_INET, argv[1], &servaddr.sin_addr.s_addr);

		sockfd = Socket(AF_INET, SOCK_DGRAM, 0);
		my_dg_cli(stdin, sockfd, (SA *)&servaddr, sizeof(servaddr));
}
