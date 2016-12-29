#include <string>
#include <iostream>
const std::string number = "0123456789";
const std::string alpha_upper = "ABCDEFGHIJKLNMOPQRSTUVWXYZ";
const std::string alpha_lower = "abcdefghijklnmopqrstuvwxyz";

int main()
{
		std::string sample = "ab2c3d7R4E6";
		std::string::size_type pos = 0;
		// find number, find_first_of
		std::cout << "find number, find_first_of" << std::endl;
		while ((pos = sample.find_first_of(number, pos)) != std::string::npos)
		{
				std::cout << sample[pos] << " ";
				++pos;
		}
		std::cout << std::endl;
		
		// find number, find_first_not_of
		std::cout << "find number, find_first_not_of" << std::endl;
		pos = 0;
		while ((pos = sample.find_first_not_of(alpha_upper + alpha_lower, pos)) != std::string::npos)
		{
				std::cout << sample[pos] << " ";
				++pos;
		}
		std::cout << std::endl;
		
		// find alpha, find_first_of
		std::cout << "find alpha, find_first_of: " << std::endl;
		pos = 0;
		while ((pos = sample.find_first_of(alpha_upper + alpha_lower, pos)) != std::string::npos)
		{
				std::cout << sample[pos] << " ";
				++pos;
		}
		std::cout << std::endl;
		
		// find alpha, find_first_not_of
		std::cout << "find alpha, find_first_not_of: " << std::endl;
		pos = 0;
		while ((pos = sample.find_first_not_of(number, pos)) != std::string::npos)
		{
				std::cout << sample[pos] << " ";
				++pos;
		}
		std::cout << std::endl;
		
		return 0;
}
