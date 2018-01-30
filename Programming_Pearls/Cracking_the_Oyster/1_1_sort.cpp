#include <set> 
#include <iostream>

int main(void)
{
		std::set<int> s;
		int i;
		while (std::cin >> i)
				s.insert(i);
		for (auto j = s.begin(); j != s.end(); ++j)
				std::cout << *j << "\n";
		return 0;
}
