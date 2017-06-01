#include <iostream>
#include <regex>

int main()
{
		std::string word;
		std::string rgx_str = "(i.*?e)|(ce.*?i)";
		std::cout << "Enter a word, I will exam whether the word is 'i before e except after c'" << std::endl;
		while (std::cin >> word)
		{
				try
				{
						std::regex r(rgx_str, std::regex::icase);
						std::smatch results;
						if (std::regex_search(word, results, r))
								std::cout << "Matched: " << results.str() << std::endl;
						else
								std::cout << "No match!" << std::endl;
				}
				catch (std::regex_error e)
				{
						std::cout << e.what() << "\n code: " << e.code() << std::endl;
				}
		}
		return 0;
}
