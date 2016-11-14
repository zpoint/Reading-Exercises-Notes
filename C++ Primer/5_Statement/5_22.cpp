#include <iostream>

int get_size()
{
	int sz;
	std::cin >> sz;
	return(sz);
}

int main()
{
	int sz;
	do
	{
		sz = get_size();
	} while (sz < 0);
	return(0);
}