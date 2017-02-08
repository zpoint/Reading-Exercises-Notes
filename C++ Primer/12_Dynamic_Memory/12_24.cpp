#include <string>
#include <memory>
#include <iostream>

int main()
{
		std::cout << "Please input a string literal:" << std::endl;
		std::string str;
		std::cin >> str;
		std::unique_ptr<char []> uni_str(new char[str.size()]);
		for (std::size_t index = 0; index < str.size(); ++index)
				uni_str[index] = str[index];
		for (std::size_t index = 0; index < str.size(); ++index)
				std::cout << uni_str[index];
		std::cout << std::endl;
		return 0;
}
