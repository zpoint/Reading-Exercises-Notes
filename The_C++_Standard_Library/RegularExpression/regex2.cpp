#include <string>
#include <regex>
#include <iostream>
#include <iomanip>

int main()
{
		std::string data = "XML tag: <tag-name>the value</tag-name>.";
		std::cout <<       "data:                        " << data << "\n\n";

		std::smatch m; // for retuened details of the match
		bool found = std::regex_search(data,
									   m,
									   std::regex("<(.*)>(.*)</(\\1)>"));

		// print match details:
		std::cout <<        "m.empty():                   " << std::boolalpha << m.empty() << std::endl;
		std::cout <<        "m.size():                    " << m.size() << std::endl;
		if (found)
		{
				std::cout << "m.str():                    " << m.str() << std::endl;
				std::cout << "m.length():                 " << m.length() << std::endl;
				std::cout << "m.position():               " << m.position() << std::endl;
				std::cout << "m.prefix().str():           " << m.prefix().str() << std::endl;
				std::cout << "m.suffix().str():           " << m.suffix().str() << std::endl;
				std::cout << std::endl;

				// iterating over all matches (using the match index):
				for (std::size_t i = 0; i < m.size(); ++i)
				{
						std::cout << "m[" << i << "].str():     " << m[i].str() << std::endl;
						std::cout << "m.str(" << i << "):       " << m.str(i) << std::endl;
						std::cout << "m.position(" << i << "):  " << m.position(i) << std::endl;
				}
				std::cout << std::endl;

				// iterating over all matches (using iterators)
				std::cout << "matches: " << std::endl;
				for (std::smatch::iterator pos = m.begin(); pos != m.end(); ++pos)
				{
						std::cout << " " << *pos << " ";
						std::cout << "(length: " << pos->length() << ")" << std::endl;
				}
		}

		return 0;
}
