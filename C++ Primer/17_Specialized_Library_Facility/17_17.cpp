#include <iostream>
#include <regex>

int main()
{
		std::string word;
		std::string rgx_str = "[^c]ie";
		std::cout << "Enter a word, I will exam whether the word is 'i before e except after c'" << std::endl;
		while (std::getline(std::cin, word))
		{
				try
				{
						std::regex r(rgx_str, std::regex::icase);
						bool matched = false;
						for (std::sregex_iterator it(word.begin(), word.end(), r), end_it;
										it != end_it; ++it)
						{
								matched = true;
								auto pos = it->prefix().length();
								pos = pos > 40 ? pos - 40 : 0;
								std::cout << it->prefix().str().substr(pos)
										<< "\n\t>>> " << it->str() << " <<<\n"
										<< it->suffix().str().substr(0, 40) << std::endl;
						}
						if (!matched)
								std::cout << "No match!!!" << std::endl;

				}
				catch (std::regex_error e)
				{
						std::cout << e.what() << "\n code: " << e.code() << std::endl;
				}
		}
		return 0;
}
