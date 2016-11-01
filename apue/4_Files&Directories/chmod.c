#include "apue.h"
int main(void)
{
		struct stat statbuf;
		if (stat("foo", &statbuf) < 0)
				err_sys("stat error for foo");
		if (chmod("foo", (statbuf.st_mode & S_IXGRP) |  S_ISGID) < 0)
				err_sys("chmod error for foo");
		if (chmod("bar", S_IRWXU | S_ISGID | S_ISUID | S_ISVTX) < 0)
				err_sys("chmod erro for bar");
		if (chmod("group_id", S_ISGID) < 0)
				err_sys("chmod erro for group_id");
		if (chmod("user_id", S_ISUID) < 0)
				err_sys("chmod erro for user_id");
		exit(0);
}

