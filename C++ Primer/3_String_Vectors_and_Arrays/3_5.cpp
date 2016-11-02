#include <iostream>
#include <string>

int main()
{
		std::string str1, str2;
		std::cout << "Input two string" << std::endl;
		std::cin >> str1 >> str2;
		str1 += str2;
		std::cout << "After concatenated: " << str1 << std::endl;

		std::cout << "Now enter several strings seperate by new line" << std::endl;
		std::getline(std::cin, str1); // newline charcter still in buffer
		std::getline(std::cin, str1);
		for (unsigned i = 0; i < str1.size(); i++)
		{
				if (str1[i] == ' ')
						std::cout << "\n";
				else
						std::cout << str1[i];
		}
		std::cout << std::endl;
		return(0);
}
