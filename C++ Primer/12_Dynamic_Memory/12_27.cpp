#include "my_Query.h"

void runQuries(std::ifstream &infile)
{
		TextQuery tq(infile);
		while (true)
		{
				std::cout << "enter word to look for, or q to quit: ";
				std::string s;
				if (!(std::cin >> s) || s == "q") break;
				tq.query(s).print(std::cout);
		}
}

int main(int argc, char **argv)
{
		if (argc != 2)
				throw std::invalid_argument("Usage: program_name filename");
		std::ifstream infile(argv[1]);
		if (!infile.good())
				throw std::runtime_error("Unable to open file" + std::string(argv[1]));
		runQuries(infile);
		return 0;
}
