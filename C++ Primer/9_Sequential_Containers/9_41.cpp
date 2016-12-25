#include <iostream>
#include <vector>
#include <string>

int main()
{
		std::vector<char> cvec(10, 'a');
		std::string str(cvec.begin(), cvec.end());
		std::cout << str << std::endl;
		return 0;
}
