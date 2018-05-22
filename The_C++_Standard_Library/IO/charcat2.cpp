#include <iostream>
#include <iterator>

int main()
{
		// input stream buffer iterator for cin
		std::istream_iterator<char> inpos(std::cin);

		// end-of-stream iterator
		std::istream_iterator<char> endpos;

		// output stream buffer iterator for cout
		std::ostreambuf_iterator<char> outpos(std::cout);

		// while inout iterator is valid
		while (inpos != endpos)
		{
				*outpos = *inpos; // assign its value to the output iterator
				++inpos;
				++outpos;
		}

		return 0;
}
