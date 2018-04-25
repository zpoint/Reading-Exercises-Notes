#include <memory>
#include <iostream>

class A
{
		public:
			A(std::string str = ""): s(str) {}
		    std::string s;	
};

void sink(std::unique_ptr<A> up)
{
		std::cout << (*up).s << std::endl;
}

void test(A &a)
{
}

int main()
{
		std::unique_ptr<A> a(new A("I am A"));
		std::unique_ptr<A> b(std::move(a));
		sink(std::move(b));
		b.reset(new A("I am B"));
		test(*b.get());
		return 0;
}
