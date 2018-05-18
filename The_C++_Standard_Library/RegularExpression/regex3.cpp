#include <string>
#include <regex>
#include <iostream>

int main()
{
		std::string data = "<person>\n"
						   " <first>Nico</first>\n"
						   " <last>Josuttis</last>\n"
						   " </person>\n";

		std::regex reg("<(.*)>(.*)</(\\1)>");

		// iterate over all matches
		auto pos = data.cbegin();
		auto end = data.cend();
		std::smatch m;

		for (; std::regex_search(pos, end, m, reg); pos = m.suffix().first)
		{
				std::cout << "match:   " << m.str() << std::endl;
				std::cout << "tag:     " << m.str(1) << std::endl;
				std::cout << "value:   " << m.str(2) << std::endl;
				std::cout << "m.suffix(): " << m.suffix() << std::endl;
				std::cout << "m.suffix().first: " << *(m.suffix().first) << std::endl;
			    std::cout << "m[0].second: " << *(m[0].second) << std::endl;	
		}

		return 0;
}
