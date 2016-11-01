#include "apue.h"
int main(void)
{
		printf("_SC_VERSION: %d\n", _SC_VERSION);
		printf("sysconf(_SC_XOPEN_VERSION): %ld \n", sysconf(_SC_XOPEN_VERSION));
		printf("sysconf(_SC_VERSION): %ld\n", sysconf(_SC_VERSION));
		printf("pathconf(\"/dev/con1\", _PC_PIPE_BUF): %ld\n", pathconf("/dev/con1", _PC_PIPE_BUF));
		return 0;
}

