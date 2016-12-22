#include <deque>
#include <list>
#include <iostream>

int main()
{
		std::list<int> li{1,2,3,4,5,6,7,8,9};
		std::deque<int> even_queue, odd_queue;
		for (const auto i : li)
		{
				if (i % 2)
						odd_queue.push_back(i);
				else
						even_queue.push_back(i);
		}
		std::cout << "odd_queue: ";
		for (const auto i : odd_queue)
				std::cout << i << " ";
		std::cout << std::endl;

		std::cout << "even_queue: ";
		for (const auto i : even_queue)
				std::cout << i << " ";
		std::cout << std::endl;

		return 0;
}
