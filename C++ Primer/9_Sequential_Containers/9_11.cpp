#include <vector>
#include <iostream>
using std::vector;

void pr_vector(const vector<int> vec, const char *str)
{
		auto begin = vec.cbegin(), end = vec.cend();
		std::cout << str << ": ";
		while (begin != end)
				std::cout << *begin++ << " ";
		std::cout << std::endl;
}

int main()
{
		vector<int> v1;
		vector<int> v2{1,2,3,4,5};
		vector<int> v3(v2);
		vector<int> v4 = {1, 2, 3, 4, 5, 6};
		vector<int> v5(++v2.begin(), --v2.end());
		vector<int> v6(3);
		vector<int> v7(3, 99);
		pr_vector(v1, "v1");
		pr_vector(v2, "v2");
		pr_vector(v3, "v3");
		pr_vector(v4, "v4");
		pr_vector(v5, "v5");
		pr_vector(v6, "v6");
		pr_vector(v7, "v7");
		return 0;
}
