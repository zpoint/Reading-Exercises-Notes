#include <functional>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

std::size_t count(std::vector<int> ivec)
{
		std::size_t count = 0;
		std::greater<int> gt;
		for (const auto &item : ivec)
				if (gt(item, 1024))
						count += 1;
		return count;
}

std::string nequal(std::vector<std::string> str_vec)
{
		std::not_equal_to<std::string> neq;
		auto fn = std::bind(neq, std::placeholders::_1, std::string("pooh"));
		auto item = std::find_if(str_vec.begin(), str_vec.end(), fn);
		if (item != str_vec.end())
		{
				std::cout << *item << std::endl;
				return *item;
		}
		else
		{
				std::cout << "not found" << std::endl;
				return "";
		}

}

int multi(const int &val)
{
		std::multiplies<int> func_mult;
		return func_mult(val, 2);
}

int main()
{
		// a
		std::vector<int> ivec(10, 1025);
		ivec.push_back(10);
		std::cout << count(ivec) << std::endl;

		// b
		std::vector<std::string> svec{"pooh", "12", "sda", "dasd"};
		nequal(svec);

		// c
		std::vector<int> iivec(10, 3);
		for (auto &item: iivec)
				item = multi(item);
		for (const auto &item : iivec)
				std::cout << item << " ";
	   	std::cout << std::endl;	
		return 0;
}
