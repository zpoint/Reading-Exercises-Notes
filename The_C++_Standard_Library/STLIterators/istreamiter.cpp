#include <iostream>
#include <iterator>

int main()
{
		// create istream iterator that reads integers from cin
		std::istream_iterator<int> intReader(std::cin);

		// create end-of-stream iterator
		std::istream_iterator<int> intReaderEOF;

		// while able to read tokens with istream iterator
		// - write them twice
		while (intReader != intReaderEOF)
		{
				std::cout << "once:       " << *intReader << std::endl;
				std::cout << "once again: " << *intReader << std::endl;
				++intReader;
		}

		return 0;	
}
