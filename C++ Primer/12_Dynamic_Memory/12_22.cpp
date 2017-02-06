#include <iostream>
#include "strblob.h"

int main(int argc, char **argv)
{
		const StrBlob blob = {"abc", "def", "hij"};
		blob.push_back("13");
		ConstStrBlobPtr cptr_blob = blob.cbegin();
		while (true)
		{
				std::cout << cptr_blob.deref() << std::endl;
				cptr_blob.incr();
		}
		return 0;
}

