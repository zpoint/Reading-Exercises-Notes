void set_fl(int fd, int flags) // flags are file status to turn on
{
		int val;

		if ((val = fcntl(fd, F_GETFL, 0)) < 0)
				err_sys("fcntl F_GETFL error");

		val |= flags; // turn on flags

		if (fcntl(fd, F_SETFL, val) < 0)
				err_sys("fcntl F_SETFL error");
}

void clr_fl(int fd, int flags)
{
		int val;

		if ((val = fcntl(fd, F_GETFL, 0)) < 0)
				err_sys("fcntl F_GETFL error");

		val &= ~flags; // turn off flags

		if (fcntl(fd, F_SETFL, val) < 0)
				err_sys("fcntl F_SETFL error");
}

int lock_reg(int fd, int cmd, int type, off_t offset, int whence, off_t len)
{
		struct flock lock;

		lock.l_type = type; // F_RDLCK, F_WRLCK, F_UNLCK
		lock.l_start = offset; // byte offset, relative to l_whence
		lock.l_whence = whence; // SEEK_SET, SEEK_CUR, SEEK_END
		lock.l_len = len;  // #bytes (0 means to EOF)

		return(fcntl(fd, cmd, &lock));
}
