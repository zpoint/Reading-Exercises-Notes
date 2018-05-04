#include <iostream>
#include <forward_list>

namespace t1 
{
		void aa() { std::cout << "t1::a()" << std::endl; }
}

void aa1()
{
		std::cout << "global aa()" << std::endl;
}

int main()
{
		using namespace t1;
		aa();
		std::forward_list<int> fw1 = {1,2,3,4};
		std::forward_list<int>::iterator iter = fw1.begin();
		++iter;
		return 0;
}
