#include "../../lib/unp.h"

int my_udp_server(const char* host, const char* serv, socklen_t *addrlenp)
{
		int sockfd, n;
		struct addrinfo hints, *res, *ressave;
		char buffer[MAXLINE];

		bzero(&hints, sizeof(struct addrinfo));
		hints.ai_flags = AI_PASSIVE;
		hints.ai_family = AF_UNSPEC;
		hints.ai_socktype = SOCK_DGRAM;

		if ( (n = getaddrinfo(host, serv, &hints, &res)) != 0 )
				err_quit("my_udp_server error for %s, %s: %s", host, serv, gai_strerror(n));
		ressave = res;

		do
		{
				sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
				if (sockfd < 0)
						continue;  /* error - try next one */

				if (bind(sockfd, res->ai_addr, res->ai_addrlen) == 0)
				{
						/* success */
						printf("bind to %s successfully\n", Inet_ntop(res->ai_family, res->ai_addr, buffer, res->ai_addrlen));
						break;
				}

				Close(sockfd);
		} while ( (res = res->ai_next) != NULL );

		if (res == NULL)
				err_sys("my_udp_server error for %s, %s", host, serv);

		if (addrlenp)
				*addrlenp = res->ai_addrlen; /* return size of protocol addres */

		freeaddrinfo(ressave);

		return (sockfd);
}
