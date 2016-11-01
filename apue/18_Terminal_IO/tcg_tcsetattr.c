#include "apue.h"
#include <termios.h>

int main(void)
{
		struct termios term;

		if (tcgetattr(STDIN_FILENO, &term) < 0)
				err_sys("tcgetattr error");

		printf("term.c_cflag: %x\n", term.c_cflag);
		printf("CSIZE: %x\n", CSIZE);
		printf("CS5: %x\n", CS5);
		printf("CS6: %x\n", CS6);
		printf("CS7: %x\n", CS7);
		printf("CS8: %x\n", CS8);
		switch (term.c_cflag & CSIZE)
		{
				case CS5:
						printf("5 bits/byte\n");
						break;
				case CS6:
						printf("6 bits/byte\n");
						break;
				case CS7:
						printf("7 bits/byte\n");
						break;
				case CS8:
						printf("8 bits/byte\n");
						break;
				default:
						printf("unknown bits/byte\n");
		}

		term.c_cflag &= ~CSIZE; // zero out the bits
		term.c_cflag |= CS8; // set 8 bits/byte
		if (tcsetattr(STDIN_FILENO, TCSANOW, &term) < 0)
				err_sys("tcsetattr error");
		exit(0);
}
