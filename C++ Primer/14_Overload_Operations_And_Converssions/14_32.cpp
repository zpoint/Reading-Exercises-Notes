#include "strblob.h"

// bad class
class StrBlobPtrPtr {
		public:
				StrBlobPtrPtr(StrBlobPtr &blobptr): ptr(&blobptr) { }
				StrBlobPtr operator->() const
				{
						return *ptr;
				}
		private:
				StrBlobPtr *ptr;
};

int main()
{
		StrBlob b = {"1", "ds", "ddsa"};
		StrBlobPtr ptr(b);
		StrBlobPtrPtr pptr(ptr);
		std::cout << pptr.operator->()->size() << std::endl;
		return 0;
}
