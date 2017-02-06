#include <iostream>
#include <fstream>
#include "strblob.h"

int main(int argc, char **argv)
{
		if (argc != 2)
				throw std::runtime_error("Usage: program_name filename");

		std::string filename = argv[1];
		std::string buffer;
		std::ifstream input_file(filename);
		StrBlob blob;
		StrBlobPtr ptrblob;
		if (!input_file.good())
				throw std::runtime_error("Unable to open file: " + filename);

		while (input_file >> buffer)
				blob.push_back(buffer);

		ptrblob = blob.begin();
		while (true)
		{
				std::cout << ptrblob.deref() << std::endl;
				ptrblob.incr(); // throw out of range when out of range
		}

		return 0;
}

