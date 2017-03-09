#include <iostream>
#include <vector>
#include <algorithm>

class Foo {
		public:
				Foo sorted() &&;
				Foo sorted() const &;
		private:
				std::vector<int> data;
};

Foo Foo::sorted() &&
{
		std::cout << "Calling rvalue sorted" << std::endl;
		std::sort(data.begin(), data.end());
		return *this;
}

Foo Foo::sorted() const & 
{
		std::cout << "Calling lvalue sorted" << std::endl;
		/*
		Foo ret(*this);
		return ret.sorted();
		*/
		return Foo(*this).sorted();
}


int main()
{
		Foo f = Foo();
		f.sorted();
		return 0;
}
