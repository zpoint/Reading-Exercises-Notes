#include <algorithm>
#include <deque>
#include <iostream>

int main()
{
		std::deque<int> coll = { 1, 3, 19, 5, 13, 7, 11, 2, 17 };
		int x = 5;
		int y = 12;
		auto pos = std::find_if(coll.cbegin(), coll.cend(), [=](int i){return i > x && i < y;});
		std::cout << "first elem >5 and <12: " << *pos << std::endl;

		int id = 0;
		auto f = [id] () mutable {
				std::cout << "id: " << id << std::endl;
				++id;
		};
		id = 42;
		f();
		f();
		f();
		std::cout << "id out: " << id << std::endl;
		return 0;
}
