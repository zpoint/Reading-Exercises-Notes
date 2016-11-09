#include <iostream>
#include <vector>
#include <string>

int main()
{
		std::vector<std::string> vstr(10, "string  ");
		for (auto i = 0; i < vstr.size(); ++i)
				vstr[i][7] = '0' + i;
		auto iter = vstr.begin();

		std::cout << "*iter++: " << *iter++ << std::endl;
		std::cout << "(*iter)++ is error, *iter: " << *iter << std::endl;
		std::cout << "*iter.empty() error, (*iter).empty(): " << (*iter).empty() << std::endl;
		std::cout << "iter->empty(): " << iter->empty() << std::endl;
		std::cout << "++*iter is error, *++iter: " << *++iter << std::endl;
		std::cout << "iter++->empty(): " << iter++->empty() << std::endl;
		return(0);
}
