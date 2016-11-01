#include "apue.h"

int main(void)
{
		int a = 10;
		while (a > -1)
				if (a < 0)
						printf("a < 0");
				else
						printf("a: %d\n", a--);
}
