#include <iostream>
#include <fstream>

int main()
{
		// open file "example.dat" for reading and writing
		std::filebuf buffer;
		std::ostream output(&buffer);
		std::istream input(&buffer);
		buffer.open("example.dat", std::ios::in | std::ios::out | std::ios::trunc);

		for (int i = 1; i <= 4; i++)
		{
				// write one line
				output << i << ". line" << std::endl;

				// print all file contents
				input.seekg(0); // seek to beginning
				char c;
				while (input.get(c))
						std::cout.put(c);
				std::cout << std::endl;
				input.clear();
		}
}
