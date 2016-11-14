#include <iostream>
#include <vector>

int main()
{
	std::vector<int> ivec1{ 0, 1, 1, 2 }, ivec2{ 0, 1, 1, 2, 3, 5, 8 };
	std::cout << "ivec1: ";
	for (auto i : ivec1)
		std::cout << i << " ";
	std::cout << std::endl;
	std::cout << "ivec2: ";
	for (auto i : ivec2)
		std::cout << i << " ";
	std::cout << std::endl;

	bool sub = true;
	for (std::vector<int>::size_type i = 0; i < ivec1.size(); ++i)
		if (ivec1[i] != ivec2[i])
		{
			sub = false;
			break;
		}
	std::cout << "ivec1 " << (sub ? "is " : "is not ") <<  "prefix of ivec2"  << std::endl;
	return(0);
}