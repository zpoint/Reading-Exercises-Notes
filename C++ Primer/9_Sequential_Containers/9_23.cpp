#include <vector>
#include <iostream>

int main()
{
		std::vector<int> c(1);
		std::cout << "c.size(): " << c.size();
		std::cout << " c[0]:" << c[0] << std::endl;
		if (!c.empty())
		{
				auto val = *c.begin(), val2 = c.front(); // 1, 1
				auto last = c.end(); // one behind last
				auto val3 = *(--last); // 1
				auto val4 = c.back();  // 1
				std::cout << "val: " << val << " val2: " << val2 << " val3: " << val3 << " val4: " << val4 << std::endl;
		}
		return 0;

}
