#include <memory>
#include <iostream>

void process(std::shared_ptr<int> sp)
{
		std::cout << "Processing: " << *sp << std::endl;
		std::cout << sp.get() << " " << " sp.use_count() " << sp.use_count() << std::endl;
}

int main()
{
		std::shared_ptr<int> p(new int(42));
		process(std::shared_ptr<int>(p));
		return 0;
}
