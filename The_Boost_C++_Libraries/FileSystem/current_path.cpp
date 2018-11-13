#include <boost/filesystem.hpp>
#include <iostream>

using namespace boost::filesystem;

int main()
{
		try
		{
				std::cout << current_path() << '\n';
				current_path("/Users/zpoint/Desktop/");
				std::cout << current_path() << '\n';
		}
		catch (filesystem_error &e)
		{
				std::cerr << e.what() << '\n';
		}
		return 0;
}
