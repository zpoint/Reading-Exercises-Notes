#include <iostream>
#include <vector>

int main()
{
		std::vector<int> ivec(10);
		for (auto i = 0; i < ivec.size(); i++)
				ivec[i] = i;
		for (auto &item : ivec)
				if (item % 2 != 0) // odd
						item *= 2;
		for (auto item : ivec)
				std::cout << item << " ";
		std::cout << std::endl;
		return(0);
}
