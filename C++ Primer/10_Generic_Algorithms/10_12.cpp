#include "Sales_item.h"
#include <iostream>
#include <vector>
#include <algorithm>

bool _compareIsbn(const Sales_item &item1, const Sales_item &item2)
{
		return item1.isbn() < item2.isbn();
}

int main()
{
		Sales_item item1("888-999"), item2("55"), item3("66-77");
		std::vector<Sales_item> vec_items = {item1, item2, item3, item1};
		std::cout << "Before call stable_sort: \n";
		for (const auto &i : vec_items)
				std::cout << i.isbn() << " ";
		std::cout << std::endl;
		stable_sort(vec_items.begin(), vec_items.end(), _compareIsbn);
		std::cout << "After call stable_sort: \n";
		for (const auto &i : vec_items)
				std::cout << i.isbn() << " ";
		std::cout << std::endl;
		return 0;
}
