#include <boost/filesystem.hpp>
#include <iostream>

using namespace boost::filesystem;

int main()
{
		path p{"/Users/zpoint/Desktop/"};
		std::cout << p.root_name() << '\n';
		std::cout << p.root_directory() << '\n';
		std::cout << p.root_path() << '\n';
		std::cout << p.relative_path() << '\n';
		std::cout << p.parent_path() << '\n';
		std::cout << p.filename() << '\n';
		return 0;
}

