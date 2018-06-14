#include "../../lib/unp.h"

void my_dg_cli(FILE *fp, int sockfd, SA *pservaddr, socklen_t servlen)
{
		char sendline[MAXLINE], recvline[MAXLINE];
		int n;

		while (Fgets(sendline, MAXLINE, fp) != NULL)
		{
				Sendto(sockfd, sendline, strlen(sendline), 0, pservaddr, servlen);
				n = Recvfrom(sockfd, recvline, MAXLINE, 0, NULL, NULL);
				recvline[n] = 0;
				Fputs(recvline, stdout);
		}
}

int main(int argc, char **argv)
{
		int sockfd;
		struct sockaddr_un cliaddr, servaddr;

		sockfd = Socket(AF_LOCAL, SOCK_DGRAM, 0);

		bzero(&cliaddr, sizeof(cliaddr)); /* bind an address for us */
		cliaddr.sun_family = AF_LOCAL;
		strcpy(cliaddr.sun_path, tmpnam(NULL));

		Bind(sockfd, (SA *) &cliaddr, sizeof(cliaddr)); 
		bzero(&servaddr, sizeof(servaddr)); /* fill in server's address */
		servaddr.sun_family = AF_LOCAL;
		strcpy(servaddr.sun_path, UNIXDG_PATH);

		my_dg_cli(stdin, sockfd, (SA *) &servaddr, sizeof(servaddr));
		exit(0);

}
