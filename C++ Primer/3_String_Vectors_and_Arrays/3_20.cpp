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
		for (auto &item : vec_int)
				num += item;
		std::cout << "Total: " << num << std::endl;
		
		// print sum for first && last, second && second-to-last, etc..
		num = vec_int.size();
		for (auto i = 0; i < num / 2; i++)
				std::cout << "Sum of " << i + 1 << "th(" << vec_int[i] <<") and " 
						<< num - i << "th(" << vec_int[num - i - 1] << ") is " 
						<< vec_int[i] + vec_int[num - i - 1] << std::endl;
		// the middle one, only odd situation
		num = num / 2;
		if (vec_int.size() % 2 != 0) // odd
				std::cout << " " << num + 1 << "th("<< vec_int[num] << ")" << " is in middle, No need to sum, value: " << vec_int[num] << std::endl;
		return(0);
}
