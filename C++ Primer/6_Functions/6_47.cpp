#include <iostream>
#include <vector>
#include <string>

void pr_rec(std::vector<int> &ivec, std::vector<int>::iterator &iter)
{
		if (iter != ivec.cend())
		{
				std::cout << *iter << std::endl;
#ifndef NDEBUG
				std::cout << "__FILE__: " << __FILE__ << "\n"
						<< "__func__: " << __func__ << "\n"
						<< "__LINE__: " << __LINE__ << "\n"
						<< "__DATE__: " << __DATE__ << "\n"
						<< "__TIME__: " << __TIME__ << "\n"
						<< "iter: " << *iter << std::endl;
#endif
				pr_rec(ivec, ++iter);
		}
}

int main()
{
		std::vector<int> ivec{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
		/*
		std::vector<std::string> istr{"1", "2", "3", "4", "5"};
		std::string str = "0123456789";
		for (auto i = str.cbegin(); i != str.cend(); ++i)
				std::cout << *i << std::endl;
		*/
		std::cout << "Calling pr_rec(ivec, ivec.cbegin()): " << std::endl;
		auto begin_iterator = ivec.begin();
		auto &i = begin_iterator;
		pr_rec(ivec, i);
		return 0;
}	
