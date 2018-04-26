#include <iostream>

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
		return 0;
}
