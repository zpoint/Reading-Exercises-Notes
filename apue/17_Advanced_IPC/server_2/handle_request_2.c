#include "opend.h"
#include "apue.h"
#include <fcntl.h>
#include "send_fd.c"
#include "send_err.c"
#include "serv_accept.c"
#include "client.c"
#define MAXARGC 50 // max number of arguments in buf
#define WHITE "\t\n"  // white space for tokenizing arguments

int buf_args(char *buf, int (*optfunc)(int, char **))
{
		/*
		 * buf[] contains whilt-space-separated arguments. We convert it to an
		 * argv-style array of pointers, and call the user's function (optfunc) to
		 * process the array. We return -1 if there's a problem parsing buf,
		 * else we return whatever optfunc() returns. Note that user's buf[] array
		 * is modified (nulls placed after each token)
		 */
		char *ptr, *argv[MAXARGC];
		int argc;

		if (strtok(buf, WHITE) == NULL) // an argv[0] is required
				return(-1);
		argv[argc = 0] = buf;
		while ((ptr = strtok(NULL, WHITE)) != NULL)
		{
				if (++argc >= MAXARGC-1)  // -1 for room for NULL at end
						return(-1);
				argv[argc] = ptr;
		}

		argv[++argc] = NULL;
		/* Since argv[] pointers point into the user's buf[],
		 * user's function can just copy the pointers, even though
		 * argv[] array will disappear on return. */
		return((*optfunc)(argc, argv));
}

int cli_args(int argc, char **argv)
{
		/* This function is called by buf_args(), which is called by
		 * handle_request(). buf_args() has broken up the client's buffer
		 * into an argv[]-style array, which we now process.
		 */

		if (argc != 3 || strcmp(argv[0], CL_OPEN) != 0)
		{
				strcpy(errmsg, "usage: <pathname> <oflag>\n");
				return(-1);
		}
		pathname = argv[1]; // save ptr to pathname to open
		oflag = atoi(argv[2]);
		return(0);
}

void handle_request(char *buf, int nread, int clifd, uid_t uid)
{
		int newfd;

		if (buf[nread-1] != 0)
		{
				snprintf(errmsg, MAXLINE-1, "request from uid %d not null terminated: %*.*s\n", uid, nread, nread, buf);
				send_err(clifd, -1, errmsg);
				return;
		}

		log_msg("request: %s, from uid: %d", buf, uid);
		// parse the arguments, set options
		if (buf_args(buf, cli_args) < 0)
		{
				send_err(clifd, -1, errmsg);
				log_msg(errmsg);
				return;
		}

		if ((newfd = open(pathname, oflag)) < 0)
		{
				snprintf(errmsg, MAXLINE-1, "can't open %s: %s\n", pathname, strerror(errno));
				send_err(clifd, -1, errmsg);
				log_msg(errmsg);
				return;
		}

		// send the descriptor
		if (send_fd(clifd, newfd) < 0)
				log_sys("send_fd error");
		log_msg("sent fd %d over fd %d for %s", newfd, clifd, pathname);
		close(newfd);  // we're done with descriptor
}
