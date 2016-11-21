#include <iostream>
#include <string>
#include <cctype>

void pr_string(const std::string s, const std::string literal)
{
		std::cout << literal << std::endl;
		std::cout << s << std::endl;
}

bool contain_capital(const std::string s)
{
		for (auto i : s)
				if (std::isupper(i))
						return true;
		return false;
}

void to_lower(std::string& s)
{
		for (auto& i : s)
				i = std::tolower(i);
}

int main()
{
		std::string str;
		std::cout << "Enter a string" << std::endl;
		std::cin >> str;
		pr_string(str, "The string you input is:");
		std::cout << "Contain capital ? ===> " << (contain_capital(str) ? "True" : "False") << std::endl;
		to_lower(str);
		pr_string(str, "After to lower:");
		return 0;
}
