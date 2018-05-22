#include <iostream>
#include <fstream>
#include <memory>

void redirect(std::ostream&);

int main()
{
		std::cout << "the first row" << std::endl;

		redirect(std::cout);

		std::cout << "the last row" << std::endl;

		return 0;
}

void redirect(std::ostream& strm)
{
		// save output buffer of the stream
		// - use unique pointer with deleter that ensures to restore
		// the original output buffer at the end of the function
		auto del = [&] (std::streambuf *p) { strm.rdbuf(p); };
		std::unique_ptr<std::streambuf, decltype(del)> origBuffer(strm.rdbuf(), del);

		// redirect output into the file redirect.txt
		std::ofstream file("redirect.txt");
		strm.rdbuf(file.rdbuf());

		file << "one row for the file" << std::endl;
		strm << "one row for the stream" << std::endl;
} // close file AND its buffer automatically
