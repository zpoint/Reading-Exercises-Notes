#include "strblob.h"

int main()
{
		StrBlob blob = {"123", "fd", "sdsds", "dfdsf"};
		StrBlobPtr ptr(blob);
		std::cout << ptr + 2 << std::endl;
		std::cout << ptr << std::endl;
		return 0;
}
