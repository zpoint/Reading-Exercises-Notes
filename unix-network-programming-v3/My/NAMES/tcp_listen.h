#include "../../lib/unp.h"

int my_tcp_listen(const char *host, const char *serv, socklen_t *addrlenp)
{
		int listenfd, n;
		const int on = 1;
		struct addrinfo hints, *res, *ressave;
		char buffer[MAXLINE];

		bzero(&hints, sizeof(struct addrinfo));
		hints.ai_flags = AI_PASSIVE;
		hints.ai_family = AF_UNSPEC;
		hints.ai_socktype = SOCK_STREAM;

		if ( (n = getaddrinfo(host, serv, &hints, &res)) != 0 )
				err_quit("tcp_listen error for %s, %s: %s", host, serv, gai_strerror(n));
		ressave = res;

		do
		{
				listenfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
				if (listenfd < 0)
						continue;  /* error, try next one */

				Setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on));
				if (bind(listenfd, res->ai_addr, res->ai_addrlen) == 0)
				{
						printf("Connect to %s successfully\n", Inet_ntop(res->ai_family, res->ai_addr, buffer, MAXLINE));
						break; /* success */
				}

				Close(listenfd); /* bind error, close and try next one */
		} while ( (res = res->ai_next) != NULL );

		if (res == NULL)
				err_sys("my)tcp_listen error for %s, %s", host, serv);
		Listen(listenfd, LISTENQ);
		
		if (addrlenp)
				*addrlenp = res->ai_addrlen; /* return size of protocol address */

		freeaddrinfo(ressave);
		return (listenfd);
}
