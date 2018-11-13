#include <boost/filesystem.hpp>
#include <iostream>

using namespace boost::filesystem;

int main()
{
		path p{"/Users/zpoint/Desktop"};
		for (const path&pp : p)
				std::cout << pp << '\n';
}
