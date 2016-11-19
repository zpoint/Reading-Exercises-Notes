#include "csapp.c"
int main(int argc, char **argv)
{
	if(argc != 2)
	{
		fprintf(stderr,"usage %s <dotted-decimal>\n",argv[0]);
		exit(0);
	}
	struct in_addr inadd;
	//unsigned int uadd;
	//sscanf(argv[1],"%x",&uadd);
	//inadd.s_addr = htonl(uadd);
	if(inet_aton(argv[1],&inadd) == 0)
	{
		app_error("inet_aton error");
	}
	printf("0x%x\n",ntohl(inadd.s_addr));
	exit(0);
}
