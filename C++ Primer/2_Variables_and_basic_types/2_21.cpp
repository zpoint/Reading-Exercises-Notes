#include <iostream>

int main()
{
		int i = 0;
		// double* dp = &i; cannot convert
		// int *ip = i; invalid
		int *p = &i;
		return(0);
}
