#include <iostream>
#include <utility>
#include <tuple>

using namespace std;

class Foo
{
		public:
			Foo(tuple<int, float>) { std::cout << "Foo::Foo(tuple)" << std::endl;}
			template <typename... Args> Foo(Args... args) { std::cout << "Foo:Foo(args...)" << std::endl;}
};

int main()
{
		// create tuple t:
		tuple<int, float> t(1, 2.22);
		// pass the tuple as a whole to the constructor of Foo:
		pair<int, Foo> p1(42, t);
		// pass the elements of the tuple to the constructor of Foo
		pair<int, Foo> p2(piecewise_construct, make_tuple(42), t);
		std::tuple<int> i(std::make_tuple(42));
		std::cout << std::get<0>(i) << std::endl;
		return 0;
}
