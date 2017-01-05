#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <functional>
#include "Sales_item.h"

bool _compareIsbn(const Sales_item &item1, const Sales_item &item2)
{
				return item1.isbn() < item2.isbn();
}

bool sameitem(const Sales_item &item1, const Sales_item &item2)
{
		return item1.isbn() != item2.isbn();
}

int main()
{
		Sales_item item1;
		std::vector<Sales_item> item_vec;
		std::cout << "please enter transactions:" << std::endl;
		std::istream_iterator<Sales_item> istream_item(std::cin), eof;
		while (istream_item != eof)
				item_vec.push_back(*istream_item++);
		std::sort(item_vec.begin(), item_vec.end(), _compareIsbn);
		
		std::vector<Sales_item>::iterator item_begin = item_vec.begin(), item_curr;
		while (item_begin != item_vec.end())
		{
				Sales_item empty;
				auto new_same_item = std::bind(sameitem, std::placeholders::_1, *item_begin);
				item_curr = std::find_if(item_begin, item_vec.end(), new_same_item);
				std::cout << std::accumulate(item_begin, item_curr, empty) << std::endl;
				item_begin = item_curr;
		}
		return 0;
}
				
