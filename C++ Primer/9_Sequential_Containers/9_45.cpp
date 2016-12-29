#include <string>
#include <iostream>

std::string add_xfix(std::string str, std::string prefix, std::string sufix)
{
		return str.insert(0, prefix + " ").append(" " + sufix);
}

int main()
{
		std::string name = "zpoint";
		std::cout << add_xfix(name, "Mr", "Js") << std::endl;
		return 0;
}
