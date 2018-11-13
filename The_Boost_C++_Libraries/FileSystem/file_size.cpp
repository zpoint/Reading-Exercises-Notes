#include <boost/filesystem.hpp>
#include <iostream>

using namespace boost::filesystem;

int main()
{
		path p{"/Users/zpoint/Desktop/t.cpp"};
		boost::system::error_code ec;
		boost::uintmax_t filesize = file_size(p, ec);
		if (!ec)
				std::cout << filesize << '\n';
		else
				std::cout << ec << '\n';
		return 0;

}
