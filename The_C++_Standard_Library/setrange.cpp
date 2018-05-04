#include <iostream>
#include <set>

int main()
{
		std::set<int> c;

		c.insert(1);
		c.insert(2);
		c.insert(3);
		c.insert(4);
		c.insert(5);
		c.insert(6);

		std::cout << "lower_bound(3): " << *c.lower_bound(3) << std::endl;
		std::cout << "upper_bound(3): " << *c.upper_bound(3) << std::endl;
		std::cout << "equal_range(3): " << *c.equal_range(3).first << " " 
									    << *c.equal_range(3).second << std::endl;
		std::cout << std::endl;
		std::cout << "lower_bound(5): " << *c.lower_bound(5) << std::endl;
		std::cout << "upper_bound(5): " << *c.upper_bound(5) << std::endl;
		std::cout << "equal_range(5): " << *c.equal_range(5).first << " "
										<< *c.equal_range(5).second << std::endl;

		return 0;
}
