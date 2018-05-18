#include <string>
#include <regex>
#include <iostream>

int main()
{
		// case-insensitive find LaTeX index entries
		std::string pat1 = R"(\\.*index\{([^}]*)\})"; // first capture group
		std::string pat2 = R"(\\.*index\{(.*)\}\{(.*)\})"; // 2nd and 3rd capture group
		std::regex pat(pat1 + "\n" + pat2, std::regex_constants::egrep | std::regex_constants::icase);

		// initialize string with characters from standard input:
		std::string data((std::istreambuf_iterator<char>(std::cin)), std::istreambuf_iterator<char>());

		// search and print matching index entries:
		std::smatch m;
		std::string::const_iterator pos = data.cbegin();
		std::string::const_iterator end = data.cend();
		for (; std::regex_search(pos, end, m, pat); pos = m.suffix().first)
		{
				std::cout << "match:  " << m.str() << std::endl;
				std::cout << "  val:  " << m.str(1) + m.str(2) << std::endl;
				std::cout << "  see:  " << m.str(3) << std::endl; 
		}

		return 0;
}
