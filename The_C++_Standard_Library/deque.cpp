#include <deque>
#include <iostream>

int main()
{
		std::deque<float> coll; // deque container for floating-point elements
		// insert elements from 1.1 to 6.6 each at the front
		for (int i = 1; i < 6; ++i)
				coll.push_front(i*1.1); // insert at front
		// print all elements followed by a space
		for (std::size_t i = 0; i < coll.size(); ++i)
				std::cout << coll[i] << ' ';
		std::cout << std::endl;
		return 0;
}
