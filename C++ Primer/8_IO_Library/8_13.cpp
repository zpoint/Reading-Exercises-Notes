#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cassert>
#include <fstream>


struct PersonInfo {
		std::string name;
		std::vector<std::string> phones;
};

int main(int argc, char **argv)
{
		assert(argc == 2);
		std::fstream fin(argv[1]);
		std::string line, word;
		std::vector<PersonInfo> people;
		std::istringstream record;
		while (std::getline(fin, line))
		{
				if (line == "")
						continue;
				PersonInfo info;
				record.clear(); // necessary
				record.str(line);
				record >> info.name;
				while (record >> word)
						info.phones.push_back(word);
				people.push_back(info);
		}
		std::cout << "Size of people: " << people.size() << "\n";
		for (auto person : people)
		{
				std::cout << person.name << "\n";
				for (auto phone : person.phones)
						std::cout << phone << "\t";
				std::cout <<"\n";
		}
		return 0;
}
