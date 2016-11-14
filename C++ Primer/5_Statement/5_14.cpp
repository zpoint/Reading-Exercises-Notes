#include <iostream>
#include <string>

int main()
{
	std::string str, prevstr, repeatstr;
	unsigned repeat_times = 0, current_repeat_times = 0;
	std::cout << "EOF to terminate, I will report the longest repeat word!" << std::endl;
	std::cin >> prevstr;
	while (std::cin >> str)
	{
		if (str == prevstr)
			++current_repeat_times;
		else
			current_repeat_times = 0;
		if (current_repeat_times >= repeat_times)
		{
			repeat_times = current_repeat_times;
			repeatstr = str;
		}
		prevstr = str;
	}
	if (repeat_times == 0)
		std::cout << "No repeat strings!!!" << std::endl;
	else
		std::cout << "Maax repeat string: " << repeatstr << "\nRepeat: " << repeat_times + 1 << " times" << std::endl;
	return(0);
}