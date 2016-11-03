#include <iostream>
#include <string>
#include <vector>

int main()
{
		std::vector<int> vec_int(10);
		int val;
		std::cout << "Enter 10 int I will double them" << std::endl;
		for (auto i = vec_int.begin(); i != vec_int.end(); i++)
		{
				std::cin >> val;
				*i = val;
		}
		for (auto i = vec_int.begin(); i != vec_int.end(); i++)
		{
				*i = *i * 2;
				std::cout << *i << " ";
		}
		std::cout << std::endl;
		return(0);
}
