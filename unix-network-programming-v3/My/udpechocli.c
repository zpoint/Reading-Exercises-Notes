#include "../lib/unp.h"

void my_dg_cli(FILE *fp, int sockfd, const SA *pservaddr, socklen_t servlen)
{
		int n;
		char sendline[MAXLINE], recvline[MAXLINE + 1];

		while (Fgets(sendline, MAXLINE, fp) != NULL)
		{
				Sendto(sockfd, sendline, strlen(sendline), 0, pservaddr, servlen);

				n = Recvfrom(sockfd, recvline, MAXLINE, 0, NULL, NULL);

				recvline[n] = 0; // null terminate
				Fputs(recvline, stdout);
		}
}

void my_dg_cli_robust(FILE *fp, int sockfd, const SA *pservaddr, socklen_t servlen)
{
		int n;
		char sendline[MAXLINE], recvline[MAXLINE + 1];
		socklen_t len;
		struct sockaddr *preply_addr;

		preply_addr = (struct sockaddr *)Malloc(servlen);

		while (Fgets(sendline, MAXLINE, fp) != NULL)
		{
				Sendto(sockfd, sendline, strlen(sendline), 0, pservaddr, servlen);
				len = servlen;
				n = Recvfrom(sockfd, recvline, MAXLINE, 0, preply_addr, &len);
				if (len != servlen || memcmp(pservaddr, preply_addr, len) != 0)
				{
						printf("len: %u, servlen: %u\n", len, servlen);
						printf("reply from %s (ignored)\n", Sock_ntop(preply_addr, len));
						continue;
				}
				else
						printf("reply from %s accepted\n", Sock_ntop(preply_addr, len));
		}
}

void my_dg_cli_bind(FILE *fp, int sockfd, const SA *pservaddr, socklen_t servlen)
{
		int n;
		char sendline[MAXLINE], recvline[MAXLINE + 1];

		Connect(sockfd, (SA *) pservaddr, servlen);

		while (Fgets(sendline, MAXLINE, fp) != NULL)
		{
				Write(sockfd, sendline, strlen(sendline));
				n = Read(sockfd, recvline, MAXLINE);
				recvline[n] = 0; /* null terminate */
				Fputs(recvline, stdout);
		}
}

int main(int argc, char **argv)
{
		int sockfd;
		struct sockaddr_in servaddr;

		if (argc != 2)
				err_quit("usage: udpcli <IPaddress>");

		bzero(&servaddr, sizeof(servaddr));
		servaddr.sin_family = AF_INET;
		servaddr.sin_port = htons(SERV_PORT);
		Inet_pton(AF_INET, argv[1], &servaddr.sin_addr);

		sockfd = Socket(AF_INET, SOCK_DGRAM, 0);

		my_dg_cli_bind(stdin, sockfd, (SA *) &servaddr, sizeof(servaddr));
		return 0;
}
