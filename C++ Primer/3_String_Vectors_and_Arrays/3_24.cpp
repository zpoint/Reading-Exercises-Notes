#include <iostream>
#include <string>
#include <vector>

int main()
{
		std::vector<int> vec_int;
		int num;
		std::cout << "Enter a set of numbers, nondigital input to terminate" << std::endl;
		while (std::cin >> num)
				vec_int.push_back(num);
		// print sum
		num = 0;
		for (auto item = vec_int.begin(); item < vec_int.end(); ++item)
				num += *item;
		std::cout << "Total: " << num << std::endl;
		
		// print sum for first && last, second && second-to-last, etc..
		num = vec_int.size();
		for (auto i = vec_int.cbegin(); i != vec_int.cbegin() + (vec_int.cend() - vec_int.cbegin()) / 2; ++i)
				std::cout << "Sum of " << *i << " and " << *(vec_int.cend() - 1 - (i - vec_int.cbegin())) << " is " 
						<< *i + *(vec_int.cend() - 1 - (i - vec_int.cbegin())) << std::endl;
		// the middle one, only odd situation
		num = vec_int.size() / 2;
		if (vec_int.size() % 2 != 0) // odd
				std::cout << " " << num + 1 << "th("<< vec_int[num] << ")" << " is in middle, No need to sum, value: " << vec_int[num] << std::endl;
		return(0);
}
