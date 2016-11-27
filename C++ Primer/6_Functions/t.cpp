#include <initializer_list>

std::initializer_list<int> t(std::initializer_list<int> i)
{
		return i;
}

int main()
{
		t({1, 2, 3, 4});
		return 0;
}
