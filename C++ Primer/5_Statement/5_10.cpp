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
		switch (c)
		{
		case 'a':
		case 'A':
			++aCnt;
			break;
		case 'e':
		case 'E':
			++eCnt;
			break;
		case 'i':
		case 'I':
			++iCnt;
			break;
		case 'o':
		case 'O':
			++oCnt;
			break;
		case 'u':
		case 'U':
			++uCnt;
			break;
		default:
			++other;
			break;
		}
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