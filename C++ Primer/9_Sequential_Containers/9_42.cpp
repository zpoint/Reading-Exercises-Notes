#include <iostream>
#include <string>

int main()
{
		char arr[100];
		unsigned index = 0;
		std::string str;
		while (std::cin >> arr[index])
		{
				if (index >= 100)
				{
						std::string buf(arr, 100);
						str += buf;
						index = 0;
				}
				++index;
		}
		std::string buf(arr, index);
		str += buf;
		std::cout << str << std::endl;
		return 0;
};
