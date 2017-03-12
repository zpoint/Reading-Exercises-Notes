#include "strblob.h"

int main()
{
		StrBlob blob = {"aa", "bb", "cc", "dd"};
		StrBlobPtr ptr(blob);
		ConstStrBlobPtr cptr(blob);
		std::cout << *ptr << std::endl;
		std::cout << *(ptr->begin()) << std::endl;

		std::cout << *cptr << std::endl;
		std::cout << *(cptr->begin()) << std::endl;
		return 0;
}
