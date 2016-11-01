#include "tell.h"

void get_and_increase(const char *filename, const char *who);

int main(void)
{
		pid_t pid;
		int n = 0, maxiter = 1000;

		FILE *f = fopen("temp", "w");
		fputs("0", f);
		fclose(f);

		TELL_WAIT();
		if ((pid = fork()) < 0)
				err_sys("fork error");
		else if (pid == 0)
		{
				while (n < maxiter)
				{
						if (n != 0)
								WAIT_PARENT();
						get_and_increase("temp", "child");
						++n;
						TELL_PARENT(getppid());
				}
		}
		else
		{
				while (n < maxiter)
				{
						WAIT_CHILD();
						get_and_increase("temp", "parent");
						++n;
						TELL_CHILD(pid);
				}
		}
}

void get_and_increase(const char *filename, const char *who)
{
		char buf[MAXLINE];
		int length = 0, count = 0, tens_val = 1;
		FILE *f = fopen(filename, "r");
		fseek(f, 0, SEEK_SET);
		fgets(buf, MAXLINE, f);
		while (buf[length] != '\0')
				++length;
		for (int i = length; i >= 1; i--)
		{
				if (i == length)
						tens_val = 1;
				else
						tens_val *= 10;
				count += (buf[i - 1] - '0') * tens_val;
		}
		fclose(f);
		f = fopen(filename, "w");
		sprintf(buf, "%d", ++count);
		fputs(buf, f);
		fclose(f);
		printf("%-7s : writing count %d to file\n", who, count);
}

