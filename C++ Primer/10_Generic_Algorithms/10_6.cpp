#include <algorithm>
#include <iostream>

int main()
{
		int ai[10];
		std::fill_n(std::begin(ai), sizeof(ai) / sizeof(*ai), 10);
		for (const auto i : ai)
				std::cout << i << " " << std::endl;
		return 0;
}
