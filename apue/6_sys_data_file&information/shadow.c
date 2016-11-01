#include "apue.h"
#include <shadow.h>
#define maxchar 5
int main(void)
{
		struct spwd *spwd_ptr;
		/*
		char buf[maxchar];
		printf("Enter user name to get shadow password:\n");
		if (fgets(buf, maxchar, stdin) != NULL)
				printf("User: %s\n", buf);
		*/
		if ((spwd_ptr = getspnam("root")) == NULL)
				err_sys("getspnam error");
		printf("user: root\n");
		printf("shadow password: %s\n", spwd_ptr->sp_pwdp == NULL || spwd_ptr->sp_pwdp[0] == 0 ? "(NULL)" : spwd_ptr->sp_pwdp);
		if ((spwd_ptr = getspnam("mimic")) == NULL)
				err_sys("getspnam error");
		printf("user: mimic\n");
		printf("shadow password: %s\n", spwd_ptr->sp_pwdp == NULL || spwd_ptr->sp_pwdp[0] == 0 ? "(NULL)" : spwd_ptr->sp_pwdp);
		exit(0);
}
