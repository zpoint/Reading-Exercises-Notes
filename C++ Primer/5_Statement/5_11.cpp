#include <iostream>
#include <string>

int main()
{
	std::string str, prestr;
	int aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0, other = 0, cblank_space = 0, ctabs = 0, cnewlines = 0;
	std::cout << "please input strings, I will count the vowels (EOF to terminate)" << std::endl;
	while (std::getline(std::cin, str))
	{
		str += '\n';
		prestr = str;
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
			case ' ':
				++cblank_space;
				break;
			case '\t':
				++ctabs;
				break;
			case '\n':
				++cnewlines;
				break;
			default:
				++other;
				break;
			}
		}
	}

	std::cout << "Number of vowel a: \t" << aCnt << "\n"
		<< "Number of vowel e: \t" << eCnt << "\n"
		<< "Number of vowel i: \t" << iCnt << "\n"
		<< "Number of vowel o: \t" << oCnt << "\n"
		<< "Number of vowel u: \t" << uCnt << "\n"
		<< "Number of nonvowel: \t" << other << "\n"
		<< "Number of blank space: \t" << cblank_space << "\n"
		<< "Number of tabs: \t" << ctabs << "\n"
		<< "Number of newline: \t" << cnewlines << "\n"
		<< "Total length: \t" << prestr.size() - 1 << "\n";
	return(0);
}