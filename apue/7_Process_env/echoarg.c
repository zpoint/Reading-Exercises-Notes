#include "apue.h"

int main(int argc, char *argv[])
{
		int i;
		extern char **environ;
		printf("########argv##########\n");
		for(i = 0; i < argc; i++)
				printf("argv[%d]: %s\n", i, argv[i]);
		printf("\n########env###########\n");
		for(i = 0; environ[i] != NULL; i++)
				printf("environ[%d]: %s\n", i, environ[i]);
		exit(0);
}
