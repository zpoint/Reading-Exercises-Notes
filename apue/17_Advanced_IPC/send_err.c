#include "apue.h"

ssize_t writen(int, const void *, size_t);
/*
 * Used when we had planned to send an fd using send_fd(),
 * but encountered an error instead. We send the error back
 * using the send_fd()/recv_fd() protocol
 */

int send_err(int fd, int errcode, const char *msg)
{
		int n;
		if ((n = strlen(msg)) > 0)
				if (writen(fd, msg, n) != n) // send the error message
						return(-1);
		if (errcode >= 0)
				errcode = -1; // must be negative
		if (send_fd(fd, errcode) < 0)
				return(-1);

		return(-1);
}

ssize_t             /* Write "n" bytes to a descriptor  */
writen(int fd, const void *ptr, size_t n)
{
	size_t		nleft;
	ssize_t		nwritten;

	nleft = n;
	while (nleft > 0) {
		if ((nwritten = write(fd, ptr, nleft)) < 0) {
			if (nleft == n)
				return(-1); /* error, return -1 */
			else
				break;      /* error, return amount written so far */
		} else if (nwritten == 0) {
			break;
		}
		nleft -= nwritten;
		ptr   += nwritten;
	}
	return(n - nleft);      /* return >= 0 */
}
