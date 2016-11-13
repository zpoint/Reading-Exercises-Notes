#include <iostream>
#include <vector>

void clear_cin()
{
	if (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
}

int main()
{
	unsigned aCnt = 0, eCnt = 0, iouCnt = 0;
	char ch;
	std::cout << "char ch: " << std::endl;
	while (std::cin >> ch)
	{
		switch (ch)
		{
		case 'a': ++aCnt; break; // miss the break
		case 'e': ++eCnt; break;
		default: ++iouCnt;
		}
	}

	unsigned b;
	std::vector<unsigned> uvec(10, 0);
	clear_cin();
	std::cout << "unsigned b: " << std::endl;
	while (std::cin >> b)
	{
		switch (b)
		{
		case 1:
			size_t ix; // should not initialize
			std::cin >> ix;
			break;
		default:
			ix = uvec.size() - 1;
			uvec[ix] = b;
			break;
		}
	}
	
	// c 
	unsigned evenCnt = 0, oddCnt = 0;
	int num = 0;
	std::cout << "Enter an integer for num: " << std::endl;
	clear_cin();
	std::cin >> num;
	int digit = num % 10;
	switch (digit)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 9:
		++oddCnt;
		break;
	case 2:
	case 4:
	case 6:
	case 8:
	case 10:
		++evenCnt;
		break;
	default:
		break;
	}
	std::cout << "oddCnt: " << oddCnt << std::endl;
	std::cout << "evenCnt: " << evenCnt << std::endl;

	// d
	const unsigned ival = 512, jval = 1024, kval = 4096;
	unsigned bufsize;
	unsigned swt;
	std::cout << "Enter unsigned swt:" << std::endl;
	clear_cin();
	std::cin >> swt;
	switch (swt)
	{
	case ival: // need to be constant
		bufsize = ival * sizeof(int);
		break;
	case jval:
		bufsize = jval * sizeof(int);
		break;
	case kval:
		bufsize = kval * sizeof(int);
		break;
	}
	return(0);
}