#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "Sales_date.h"

bool compareIsbn(const Sales_data &lhs, const Sales_data &rhs)
{
				return lhs.bookNo < rhs.bookNo;
}

typedef std::pair<std::vector<Sales_data>::const_iterator, std::vector<Sales_data>::const_iterator> iter_pair_t;

typedef std::pair<std::vector<Sales_data>::size_type, iter_pair_t> matches;

std::vector<matches>
findBook(const std::vector<std::vector<Sales_data>> &files, const std::string &book)
{
		std::vector<matches> ret;
		for (auto it = files.cbegin(); it != files.cend(); ++it)
		{
				auto found = std::equal_range(it->cbegin(), it->cend(), book, compareIsbn);
				if (found.first != found.second)
				{
						iter_pair_t iter_pair = std::make_pair(found.first, found.second);
						ret.push_back(std::make_pair(it - files.cbegin(), iter_pair));
				}
		}
		return ret;
}

void reportResults(std::istream &in, std::ostream &os,
				   const std::vector<std::vector<Sales_data>> &files)
{
		std::string s;
		while (in >> s)
		{
				auto trans = findBook(files, s);
				if (trans.empty())
				{
						std::cout << s << " not found in any stores" << std::endl;
						continue;
				}
				for (const auto &store : trans)
				{
						os << "store " << store.first << " sales: " << 
						std::accumulate(store.second.first, store.second.second, Sales_data(s)) << std::endl;
				}
		}
}

int main()
{
		std::vector<Sales_data> sv1{Sales_data("aa"), Sales_data("bb"), Sales_data("cc")};
		std::vector<Sales_data> sv2{Sales_data("vvv"), Sales_data("xxx"), Sales_data("sss")};
		std::vector<std::vector<Sales_data>> files = {sv1, sv2};
		reportResults(std::cin, std::cout, files);
		return 0;
}
