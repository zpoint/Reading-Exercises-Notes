#include <stdio.h>
#include <string.h>
#define BUFSIZE 4

void print_char(char *ptr, int size)
{
		for (int i = 0; i < size; i++)
				printf("%02x ", *(ptr++));
		putchar('\n');
}

int main(void)
{
		int a;
		char line[BUFSIZE], c;
		printf("Enter an integer, I will print it in byte order:\n");
		while(fgets(line, BUFSIZE, stdin))
		{
				//printf("line: %s, strlen(line): %d\n", line, strlen(line));
				if (sscanf(line, "%d", &a))
						break;
				if (strlen(line) == BUFSIZE - 1)
						if (line[BUFSIZE - 2] != '\n')
							while ((c = getchar()) != '\n' && c != EOF);
				printf("Invalid input, Please enter an integer again!!!\n");
		}
		printf("a(hex value): %0x\na(byte order): ", a);
		print_char((char *)&a, sizeof(a));
		return(0);
}
		
