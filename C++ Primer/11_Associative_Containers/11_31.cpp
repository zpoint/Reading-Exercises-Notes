#include <iostream>
#include <map>
#include <string>
#include <limits>

int main()
{
		std::multimap<std::string, std::string> author_works;
		std::string author, work;
		while (std::cin >> author >> work)
				author_works.insert({author, work});
		std::cout << "\n\n\n";
		for (const auto &i : author_works)
				std::cout << i.first << ":  " << i.second << std::endl;
		std::cout << "\n\n\n";
		
		std::cout << "Now enter an element to find: " << std::endl;
		std::cin.clear();
		std::cin >> author;
		auto iter = author_works.find(author);
		/*
		std::cout << "Use key: " << author << " to search" << std::endl;
		std::cout << "Find: " << iter->first << ": " << iter->second << std::endl;
		*/
		std::cout << "\n\n\n";
		if (iter == author_works.end())
				std::cout << "Author not in map!!!!!" << std::endl;
		else
		{
				author_works.erase(iter);
				std::cout << "After erase: \n";
				for (const auto &i : author_works)
						std::cout << i.first << ":  " << i.second << std::endl;
		}		
		return 0;
}
