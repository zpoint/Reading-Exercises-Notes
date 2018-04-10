/* covert little-endian to big-endian order */
#include <stdio.h>
#include "./TCP/Practical.h"

void pr_order(unsigned long val)
{
		char *ptr_c = (char *)&val;
		for (size_t i = 0; i < sizeof(unsigned long); ++i)
				printf("%2x ", *(ptr_c + i));
		printf("\n");
}

int main(int argc, char *argv[])
{
		// assume in little-endian machine
		if (argc != 2)
				DieWithUserMessage("Parameter(s)", "<int64_t>");

		unsigned long val = atol(argv[1]), dest_val = 0;
		if (val == 0)
				DieWithUserMessage("Bad parameter", "Unable to convert parameter to long");

		char *ptr_c = (char *)&val;
		char *ptr_d = (char *)&dest_val;
		for (size_t i = 0; i < sizeof(unsigned long); ++i)
				*(ptr_d + sizeof(unsigned long) - i - 1) = *(ptr_c + i);

		pr_order(dest_val);
		printf("origin_val: %lx, %ld\n", val, val);
		printf("dest_val: %lx, %ld\n", dest_val, dest_val);
		printf("Original: \n");
		pr_order(val);
		printf("Coverted: \n");
		pr_order(dest_val);

		return 0;
}
