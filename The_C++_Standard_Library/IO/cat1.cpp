#include <fstream>
#include <iostream>

// for all filenames passed as command-line arguments
// -open, print contents, and close file
int main(int argc, char **argv)
{
		std::ifstream file;

		// for all command-line arguments
		for (int i = 1; i < argc; ++i)
		{
				// open file
				file.open(argv[i]);

				// write file contents to cout
				char c;
				while (file.get(c))
						std::cout.put(c);

				// clear eofbit and failbir set due to end-of-file
				file.clear();

				// close file
				file.close();
		}

		return 0;
}
