#include <iostream>
#include <string>
#include <unordered_set>
#include "Sales_date.h"

namespace std {
		template <>
		struct hash<Sales_data>
		{
				typedef size_t result_type;
				typedef Sales_data arugment_type;
				size_t operator() (const Sales_data& s) const;
		};

		size_t hash<Sales_data>::operator() (const Sales_data& s) const
		{
				return hash<string>() (s.bookNo) ^
					   hash<unsigned>() (s.units_sold) ^
					   hash<double>() (s.revenue);
		}
}

int main()
{
		Sales_data d1("d1");
		Sales_data d2("d2");
		Sales_data d3("d3");
		std::unordered_multiset<Sales_data> unoreder_set({d1, d2, d3});
		for (const auto &item : unoreder_set)
				std::cout << item.bookNo << " ";
		std::cout << std::endl;
		return 0;
}
