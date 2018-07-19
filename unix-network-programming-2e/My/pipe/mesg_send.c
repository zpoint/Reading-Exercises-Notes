#include "mesg.h"

ssize_t mesg_send(int fd, struct mymesg *mptr)
{
		return (write(fd, mptr, MESGHDRSIZE + mptr->mesg_len));
}

void Mesg_send(int fd, struct mymesg *mptr)
{
		mesg_send(fd, mptr);
}
