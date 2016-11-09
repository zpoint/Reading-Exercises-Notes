#include <iostream>
#include <vector>

int main()
{
		int p = 0, ival = 0, *ptr = &p;
		std::vector<int> vec(10, 0);
		if (ptr != 0 && *ptr++);
		if (ival++ && ival);
		// error if (vec[ival++] <= vec[ival]);
		if (vec[ival + 1] < vec[ival]);
		return(0);
}
