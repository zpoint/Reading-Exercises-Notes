#include <fstream>
#include <iostream>

int main()
{
		std::cout << "Enter a file name, I will open it, show position of each new line at the end of file" << std::endl;
		std::string filename;
		std::cin >> filename;
		std::fstream inOut(filename, std::fstream::ate | std::fstream::in | std::fstream::out);
		if (!inOut)
		{
				std::cerr << "Unable to open file!" << std::endl;
				return EXIT_FAILURE;
		}
		auto end_mark = inOut.tellg();
		inOut.seekg(0, std::fstream::beg);
		std::size_t cnt = 0;
		std::string line;
		while (inOut && inOut.tellg() != end_mark && std::getline(inOut, line))
		{
				cnt += line.size() + 1;
				auto mark = inOut.tellg();
				inOut.seekg(0, std::fstream::end);
				inOut << cnt;
				if (mark != end_mark)
						inOut << " ";
				inOut.seekg(mark);
		}
		inOut.seekp(0, std::fstream::end);
		inOut << "\n";
		return 0;
}
