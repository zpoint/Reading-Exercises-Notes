#include <iostream>
#include <sstream>
#include <string>
#include <tuple>
#include <utility>

std::tuple<std::string, std::string, std::string> parseName(std::string name)
{
		std::string s1, s2, s3;
		std::istringstream(name) >> s1 >> s2 >> s3;
		if (s3.empty())
				return std::tuple<std::string, std::string, std::string>(std::move(s1), "", std::move(s2));
		else
				return std::tuple<std::string, std::string, std::string>(std::move(s1), std::move(s2), std::move(s3));
}

int main()
{
		std::tuple<std::string, std::string, std::string> t1 = parseName("Nicolai M. Josuttis"), t2 = parseName("Nico Josuttis");
		std::cout << "firstname: " << std::get<0>(t1) << std::endl;
		std::cout << "middle:    " << std::get<1>(t1) << std::endl;
		std::cout << "lastname:  " << std::get<2>(t1) << std::endl;

		std::cout << "firstname: " << std::get<0>(t2) << std::endl;
		std::cout << "middle:    " << std::get<1>(t2) << std::endl;
		std::cout << "lastname:   " << std::get<2>(t2) << std::endl;
		return 0;	
}
