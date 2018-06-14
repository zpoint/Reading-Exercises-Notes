#include "../../lib/unp.h"
#include "readcred.c"

void str_echo_cred(int sockfd)
{
		ssize_t n;
		int i;
		char buf[MAXLINE];
		struct cmsgcred cred;

again:
		while ( (n = my_read_cred(sockfd, buf, MAXLINE, &cred)) > 0 )
		{
				if (cred.cmcred_ngroups == 0)
						printf("no credentials retuened\n");
				else
				{
						printf("PID of sender = %d\n", cred.cmcred_pid);
						printf("real user ID = %d\n", cred.cmcred_uid);
						printf("real group ID = %d\n", cred.cmcred_gid);
						printf("effective user ID = %d\n", cred.cmcred_euid);
						printf("%d groups: ", cred.cmcred_ngroups - 1);
						for (i = 1; i < cred.cmcred_ngroups; ++i)
						{
								printf(" %d", cred.cmcred_groups[i]);
						}
						printf("\n");
				}
		}
		if (n < 0 && errno == EINTR)
				goto again;
		else if (n < 0)
				err_sys("str_echo: read error");
}
