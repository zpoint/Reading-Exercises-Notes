#include <memory>
#include <iostream>

void process(std::shared_ptr<int> sp)
{
		std::cout << "Processing: " << *sp << std::endl;
		std::cout << sp.get() << " " << " sp.use_count() " << sp.use_count() << std::endl;
}

void pi(unsigned x)
{
		std::cout << x << std::endl;
}

int main()
{
		int i = -1;
		auto p = new int();
		auto sp = std::make_shared<int>();
		process(sp);
		// process(new int()); // error
		// process(p); // error
		process(std::shared_ptr<int>(p));
		pi(unsigned(i));
		return 0;
}
