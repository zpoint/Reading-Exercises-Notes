#include <iostream>
#include <fstream>
#include <string>
#include <cassert>

int main(int argc, char **argv)
{
		assert(argc == 2);
		std::ofstream fout(argv[1]);
		std::string buffer;
		std::cout << "Enter sth";
		std::cin >> buffer;
		fout << buffer;
		fout.close();
		std::cout << "buffer wrrite to " << argv[1] << "Open again!\n";
		fout.open(argv[1], std::ofstream::app);
		std::cout << "Enter sth again";
		std::cin >> buffer;
		fout << buffer;
		fout.close();
		std::cout << "Write Done, try cat the file" << std::endl;
		return 0;
}
