#include <iostream>
#include <cstring>
int main()
{
		const char ca[] = {'h', 'e', 'l', 'l', 'o'}; // buggy , no null terminate
		const char *cp = ca;
		while (*cp)
		{
				std::cout << *cp << std::endl;
				++cp;
		}
		return(0);
}
