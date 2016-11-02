#include <iostream>
#include <string>

int main()
{
		std::string str, tmp;
		std::cout << "Input a string, I will remove the punctuation" << std::endl;
		std::cin >> str;
		for (auto &c : str)
				if (!std::ispunct(c))
						tmp += c;
		std::cout << tmp << std::endl;
		return(0);
}
