#include <iostream>
#include <regex>
#include <string>

bool valid(const std::smatch& m)
{
		if (m[1].matched)
				return m[3].matched && (m[4].matched == 0 || m[4].str() == " ");
		else
				return !m[3].matched && m[4].str() == m[6].str();
}

int main()
{
		std::string phone = "(\\()?(\\d{3})(\\))?([-. ]|\\s+)?(\\d{3})([-. ]|\\s+)?(\\d{4})";
		std::regex r(phone);
		std::smatch m;
		std::string s;
		bool matched = false;
		while (std::getline(std::cin, s))
		{
				matched = false;
				for (std::sregex_iterator it(s.begin(), s.end(), r), end_it;
								it != end_it; ++it)
				{
						matched = true;
						if (valid(*it))
								std::cout << "valid: " << it->str() << std::endl;
						else
								std::cout << "not valid: " << it->str() << std::endl;
				}
				if (not matched)
						std::cout << "No match for: " << s << std::endl;
		}
		return 0;
}
