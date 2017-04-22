#include <iostream>

// http://stackoverflow.com/questions/33640144/sum-function-with-return-type-large-enough-to-hold-result

template <typename T>
auto sum(const T var1, const T var2) -> decltype(var1 + var2)
{
		return var1 + var2;
}

int main()
{
		std::cout << unsigned(-1) << std::endl;
		std::cout << sum(unsigned(-1), unsigned(-1)) << std::endl;
		return 0;
}
