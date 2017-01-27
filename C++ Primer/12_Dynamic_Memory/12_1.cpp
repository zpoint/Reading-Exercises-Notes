#include "strblob.h"
#include <iostream>

int main()
{
		StrBlob b1;
		b1.pr_data("b1");
		{
				std::cout << "Now in the scope\n";
				StrBlob b2 = {"a", "an", "the"};
				b1.pr_data("b1");
				b2.pr_data("b2");
				b1 = b2;
				std::cout << "After b1 = b2\n";
				b1.pr_data("b1");
				b2.pr_data("b2");

				b2.push_back("about");
				std::cout << "After b2.push_back(\"about\")";
				b1.pr_data("b1");
				b2.pr_data("b2");
		}

		std::cout << "Scope End!\n";
		b1.pr_data("b1");
		return 0;
}
