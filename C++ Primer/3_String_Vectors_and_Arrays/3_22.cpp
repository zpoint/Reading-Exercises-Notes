#include <iostream>
#include <string>
#include <vector>

int main()
{
		std::string str;
		std::vector<std::string> vec_str;
		std::cout << "Enter several strings, I will capatilize them" << std::endl;
		while (std::cin >> str)
				vec_str.push_back(str);
		for (auto each_str = vec_str.begin(); each_str != vec_str.end(); each_str++)
		{
				for (auto each_chr = (*each_str).begin(); each_chr != (*each_str).end(); each_chr++)
						*each_chr = std::toupper(*each_chr);
				std::cout << *each_str << std::endl;
		}
		return(0);
}
