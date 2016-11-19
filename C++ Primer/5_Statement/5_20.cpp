#include <iostream>
#include <string>

int main()
{
	std::string str, prev = "";
	bool isrepeat = false;
	std::cout << "Enter several string, terminate when encounter same word occurs twice in succession or EOF" << std::endl;
	while (std::cin >> str)
	{
		if (str == prev)
		{
			isrepeat = true;
			break;
		}
		prev = str;
	}

	std::cout << (isrepeat ? str + " repeat twice!!!" : "No word was repeated!!!") << std::endl;
	return(0);
}