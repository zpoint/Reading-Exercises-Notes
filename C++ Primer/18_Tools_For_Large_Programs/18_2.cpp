#include <iostream>
#include <vector>
#include <fstream>

void exercise(int *b, int *e)
{
		std::vector<int>  v(b, e);
		int *p = new int(v.size());
		std::ifstream in("ints");
		std::cout << "In function: " << p << " " << *p << std::endl;
		std::cout << "in closed" << std::endl;
		throw p;
}

int main()
{
		int iarr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
		try
		{
				exercise(&iarr[0], &iarr[8]);
		}
		catch (int *p)
		{
				std::cout << "catched: " << p << " " << *p << std::endl;
		}
		return 0;
}
