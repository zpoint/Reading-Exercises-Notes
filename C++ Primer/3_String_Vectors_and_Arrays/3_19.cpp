#include <iostream>
#include <string>
#include <vector>
using std::vector;
int main()
{
		vector<int> v1(10, 42);
		vector<int> v2{42, 42, 42, 42, 42, 42, 42, 42, 42, 42};
		vector<int> v3 = {42, 42, 42, 42, 42, 42, 42, 42, 42, 42};
		vector<std::string> v4 = {10, "hi"};
		std::cout << v4.size() << std::endl;
		return(0);
}
