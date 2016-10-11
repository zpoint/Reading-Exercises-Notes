#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
		int n = argc > 1 ? atoi(argv[1]) : 4;

		for (int j = 1; j <= n; j++)
		{
				int s = 1 << j, k = (1 << n) - s, x;
				//printf("In loop:(j) %d, s: %d, k: %d, x: %d\n", j, s, k, x);
				for (int y = s - j; y >= 0; y--, putchar('\n'))
				{
						//printf("y: %d\n", y);
						for (x = 0; x < y + k; x++)
								printf("  ");
						for (x = 0; x + y < s; x++)
								printf("%c ", '!' ^ y & x);
						for (x = 1; x + y < s; x++)
								printf("%c ", '!' ^ y & (s - y - x - 1));
				}
		}
}
