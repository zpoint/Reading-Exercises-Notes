#include "strblob.h"

int main()
{
		StrBlob blob = {"abc", "def", "ghi"};
		StrBlobPtr ptr(blob);
		std::cout << ++ptr << std::endl;
		std::cout << ptr++ << std::endl;
		return 0;
}
