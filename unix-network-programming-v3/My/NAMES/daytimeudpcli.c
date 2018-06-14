#include "../../lib/unp.h"
#include "udp_client.h"

int main(int argc, char **argv)
{
		int sockfd, n;
		char recvline[MAXLINE + 1];
		socklen_t salen;
		struct sockaddr *sa;

		if (argc != 3)
				err_quit("usage: daytimeudpcli <hostname/IPaddress> <service/port#>");

		sockfd = my_udp_client(argv[1], argv[2], (SA **) &sa, &salen);

		printf("sendting to %s\n", Sock_ntop_host(sa, salen));

		Sendto(sockfd, "", 1, 0, sa, salen); /* send 1-byte datagram */

		n = Recvfrom(sockfd, recvline, MAXLINE, 0, NULL, NULL);
		recvline[n] = '\0';
		Fputs(recvline, stdout);

		return 0;
}
