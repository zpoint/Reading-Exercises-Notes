#include <iostream>
#include <sstream>
#include <stack>
#include <string>

int main(int argc, char **argv)
{
		// test it iwth command: ./a.out "(123 456)"
		std::string str(argv[1]), word;
		std::string::size_type pos = str.find_first_of('(') + 1, pos_end = str.find_first_of(')');
		if (pos == std::string::npos || pos_end == std::string::npos)
		{
				// throw exceptions here
		}
		str = str.substr(pos, pos_end - pos);
		std::istringstream istring(str);
		std::stack<std::string> stak_str;
		stak_str.push("(");
		while (istring >> word)
				stak_str.push(word);
		stak_str.push(")");
		std::cout << "stack: \n";
		while (!stak_str.empty())
		{
				const auto i = stak_str.top();
				stak_str.pop();
				std::cout << i << " ";
		}
		std::cout << std::endl;
		return 0;
}

