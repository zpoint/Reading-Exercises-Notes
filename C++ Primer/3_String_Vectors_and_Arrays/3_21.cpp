#include <iostream>
#include <string>
#include <vector>
using std::string;
using std::vector;

void pr_int(string str, vector<int> v)
{
		std::cout << str << " size: " << v.size() << std::endl;
		std::cout << "value: ";
		for (auto it = v.cbegin(); it != v.cend(); ++it)
				std::cout << *it << " ";
		std::cout << "\n" << std::endl;
}

void pr_str(string str, vector<string> v)
{
		std::cout << str << " size: " << v.size() << std::endl;
		std::cout << "value: ";
		for (auto it = v.cbegin(); it != v.cend(); ++it)
				std::cout << *it << " ";
		std::cout << "\n" << std::endl;
}

int main()
{
		vector<int> v1; // 0
		vector<int> v2(10); // 10
		vector<int> v3(10, 42); // 10
		vector<int> v4{10}; // 1
		vector<int> v5{10, 42}; // 2
		vector<string> v6{10}; // 10
		vector<string> v7{10, "hi"}; // 10
		pr_int("v1", v1);
		pr_int("v2", v2);
		pr_int("v3", v3);
		pr_int("v4", v4);
		pr_int("v5", v5);
		pr_str("v6", v6);
		pr_str("v7", v7);
		return(0);
}
