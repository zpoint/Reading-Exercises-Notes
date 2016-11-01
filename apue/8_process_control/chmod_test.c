#include "apue.h"

int main(void)
{
		if (chmod("/home/mimic/Desktop/awkexample", S_IRWXU | S_IRWXG | S_IRWXO) < 0)
				err_sys("chmod error for file");
		printf("changed\n");
		exit(0);
}
