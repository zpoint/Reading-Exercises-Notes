#include "../lib/unp.h"

#define NDG 2000 /* datagram to send */
#define DGLEN 1400 /* length of each datagram */

void my_dg_cli(FILE *fp, int sockfd, const SA *pservaddr, socklen_t servlen)
{
		int i, n;
		int sendline[DGLEN];

		n = 220 * 1024;
		Setsockopt(sockfd, SOL_SOCKET, SO_RCVBUF, &n, sizeof(n));
		for (i = 0; i < NDG; ++i)
				Sendto(sockfd, sendline, DGLEN, 0, pservaddr, servlen);
		printf("send %d datagram, each length: %d\n", NDG, DGLEN);
}


int main(int argc, char **argv)
{
		struct sockaddr_in servaddr;
		int sockfd;

		if (argc != 2)
				err_quit("usage: udpechoclioop <IPaddress>");

		bzero(&servaddr, sizeof(servaddr));
		servaddr.sin_family = AF_INET;
		servaddr.sin_port = htons(SERV_PORT);
		Inet_pton(AF_INET, argv[1], &servaddr.sin_addr);

		sockfd = Socket(AF_INET, SOCK_DGRAM, 0);
		my_dg_cli(stdin, sockfd, (SA *) &servaddr, sizeof(servaddr));
		return 0;
}
