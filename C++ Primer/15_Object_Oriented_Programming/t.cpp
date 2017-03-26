#include <set>

bool compare(int i, int j)
{
		return i < j;
}

int main()
{
		std::multiset<int, decltype(&compare)> items(compare);
		return 0;
}
