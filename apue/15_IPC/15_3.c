#include "apue.h"

#define CMD "NONEXIST_COMMAND"

int main(void)
{
		FILE *fp;
		if ((fp = popen(CMD, "r")) == NULL)
				err_sys("popen error");
		if (pclose(fp) == -1)
				err_sys("pclose error");
		return(0);
}
