#include <iostream>
#include <string>

int main()
{
	std::string str;
	int aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0, other = 0, cblank_space = 0, ctabs = 0, cnewlines = 0, fCnt = 0;
	int ffCnt = 0, flCnt = 0, fiCnt = 0;
	std::string::size_type length = 0;
	std::cout << "please input strings, I will count the vowels (EOF to terminate)" << std::endl;
	while (std::getline(std::cin, str))
	{
		length += str.size();
		str += '\n';
		for (auto c : str)
		{
			if (fCnt == 1 && c != 'f')
				fCnt = 0;
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
				if (fCnt == 1)
				{
					++fiCnt;
					fCnt = 0;
				}
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
			case 'f':
				++fCnt;
				if (fCnt == 2)
				{
					++ffCnt;
					fCnt = 0;
				}
				break;
			case 'l':
				if (fCnt == 1)
				{
					++flCnt;
					fCnt = 0;
				}
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
		<< "Number of ff: \t" << ffCnt << "\n"
		<< "Number of fl: \t" << flCnt << "\n"
		<< "Number of fi: \t" << fiCnt << "\n"
		<< "Number of blank space: \t" << cblank_space << "\n"
		<< "Number of tabs: \t" << ctabs << "\n"
		<< "Number of newline: \t" << cnewlines << "\n"
		<< "Total length: \t" << length << "\n";
	return(0);
}