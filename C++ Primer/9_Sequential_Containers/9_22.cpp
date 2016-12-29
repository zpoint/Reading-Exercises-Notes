#include <vector>
#include <iostream>

int main()
{
		int some_val = 2;
		std::vector<int> iv{1,2,3,4,5,6,7,8};
		std::vector<int>::iterator iter = iv.begin(),
								   mid = iv.begin() + iv.size() / 2;
		std::vector<int>::size_type half_size = iv.size() / 2;
		while (iter != mid)
		{
				if (*iter == some_val)
						iter = ++iv.insert(iter, 2 * some_val);  // need to reassign, or iter may be invalid
				++iter; // need to go ahead
				mid = iv.end() - half_size; // need to recalaulate, because it may be invalid
		}

		for (const auto i : iv)
				std::cout << i << " ";
		std::cout << std::endl;
		return 0;
}
