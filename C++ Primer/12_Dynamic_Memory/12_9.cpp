#include <iostream>
#include <memory>

int main()
{
		int *q = new int(42), *r = new int(100);
		std::cout << "r: " << r << " " << *r << std::endl;
		std::cout << "q: " << q << " " << *q << std::endl;
		std::cout << "Now, r = q\n";
		r = q;  // r point to q, r and q both same address ===> q   the initial r's address is missing
		std::cout << "r: " << r << " " << *r << std::endl;
		std::cout << "q: " << q << " " << *q << std::endl;

		auto q2 = std::make_shared<int>(42), r2 = std::make_shared<int>(100);
		std::cout << "q2: " << q2.get() << " " << *q2  << " q2.use_count(): " << q2.use_count() << std::endl;
		std::cout << "r2: " << r2.get() << " " << *r2 << " r2.use_count(): " << r2.use_count() << std::endl;
		r2 = q2; // decrement a count of r2, increment a count of q2, r2 count is 0, free it automatically
		std::cout << "After r2 = q2: \n";
		std::cout << "q2: " << q2.get() << " " << *q2  << " q2.use_count(): " << q2.use_count() << std::endl;
		std::cout << "r2: " << r2.get() << " " << *r2 << " r2.use_count(): " << r2.use_count() << std::endl;
		return 0;
}
