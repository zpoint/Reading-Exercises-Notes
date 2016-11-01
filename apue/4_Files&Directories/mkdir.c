/*in the command line
./a.out my_directory
The loop will create directory named my_directory and change dir to my_directory
until meet filename limit
*/
#include "apue.h"
#include <error.h>
#include <limits.h>

#ifdef PATH_MAX
static long pathmax = PATH_MAX;
#else
static long pathmax = 0;
#endif

static long posix_version = 0;
static long xsi_version = 0;
static size_t path_add_len = 0;
static size_t current_path_len = 0;
static char *path_add;
char *path_alloc(size_t *sizep);
char *path_realloc(char *path, size_t *sizep);
#define PATH_MAX_GUESS 1024

int main(int argc, char *argv[])
{
		char *cwd;
		size_t size;
		long n = 0;
		int len, i;
		if (argc != 2)
				err_quit("usage: expect 1 arguments, %d find\n", argc);
		cwd  = path_alloc(&size);
		if (getcwd(cwd, size) == NULL)
				err_sys("getcwd failed");

		/* make my_dir become /my_dir */
		len = strlen(argv[1]);
		path_add = malloc(len + 2); // count '/0' and '/'
		path_add[len + 1] = '\0';
		for (i = len; i > 0; i--)
				path_add[i] = argv[1][i - 1];
		path_add[0] = '/';

		path_add_len = strlen(path_add);
		current_path_len = strlen(cwd);
		size = strlen(cwd);
		
		while(1)
		{
				n += 1;
				cwd = path_realloc(cwd, &size);
				if (mkdir(cwd, S_IRWXU | S_IRWXG | S_IRWXO) < 0)
						err_sys("mkdir fail in %d times", n);
				if (chdir(cwd) < 0)
						err_sys("chdir fail in %d times", n);
		}

		exit(0);
}


char *path_alloc(size_t *sizep)
{
		char *ptr;
		size_t size;

		if (posix_version == 0)
				posix_version = sysconf(_SC_VERSION);

		if (xsi_version == 0)
				xsi_version = sysconf(_SC_XOPEN_VERSION);

		if (pathmax == 0)
		{
				errno = 0;
				if ((pathmax = pathconf("/", _PC_PATH_MAX)) < 0)
					if (errno == 0)
							pathmax = PATH_MAX_GUESS;
					else
							err_sys("pathconf error for _PC_PATH_MAX");
				else
						pathmax++;
		}

		if ((posix_version < 200112L) && (xsi_version < 4))
				size = pathmax + 1;
		else
				size = pathmax;

		if ((ptr = malloc(size)) == NULL)
				err_sys("malloc error for pathname");

		if (sizep != NULL)
				*sizep = size;
		return(ptr);
}

char *path_realloc(char *path, size_t *sizep)
{
		char *ptr;
		size_t i = 0;
		if (*sizep < (path_add_len + current_path_len + 1))
		{
				*sizep *= 2;
				if ((ptr = (char *)realloc(path, sizeof(char) * (*sizep))) == NULL)
						err_sys("realloc error");
		}
		else
				ptr = path;

		for (; i < path_add_len; i++)
				ptr[current_path_len + i] = path_add[i];
		ptr[current_path_len + i] = '\0';
		current_path_len += path_add_len;
		return ptr;
}



