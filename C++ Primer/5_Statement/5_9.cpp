#include <iostream>
#include <string>

int main()
{
	std::string str;
	int aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0, other = 0;
	std::cout << "please input a line, I will count the vowels" << std::endl;
	std::getline(std::cin, str);
	for (auto c : str)
	{
		if (c == 'a')
			++aCnt;
		else if (c == 'e')
			++eCnt;
		else if (c == 'i')
			++iCnt;
		else if (c == 'o')
			++oCnt;
		else if (c == 'u')
			++uCnt;
		else
			++other;
	}
	std::cout << "Number of vowel a: \t" << aCnt << "\n"
		<< "Number of vowel e: \t" << eCnt << "\n"
		<< "Number of vowel i: \t" << iCnt << "\n"
		<< "Number of vowel o: \t" << oCnt << "\n"
		<< "Number of vowel u: \t" << uCnt << "\n"
		<< "Number of other: \t" << other << "\n"
		<< "Total characters: \t" << str.size() << "\n";
	return(0);
}