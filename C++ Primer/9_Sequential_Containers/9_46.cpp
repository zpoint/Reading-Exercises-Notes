#include <string>
#include <iostream>

std::string add_xfix(std::string str, std::string prefix, std::string sufix)
{
		str = str.insert(0, prefix + " ");
		str = str.insert(str.size(), " " + sufix);
		return str;
}

int main()
{
		std::string name = "zpoint";
		std::cout << add_xfix(name, "Mr", "Js") << std::endl;
		return 0;
}
