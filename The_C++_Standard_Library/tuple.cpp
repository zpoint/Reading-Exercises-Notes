#include <iostream>
#include <utility>

class A
{
		public:
			A(int i = int()): a(i) {}
			A(A&rhs): a(rhs.a) {}
			A(const A&rhs): a(rhs.a) {}
		private:
			int a;
};

int main(int argc, char * argv[])
{
		typedef std::pair<int,float> IntFloatPair;
		IntFloatPair p(42, 3.14);
		std::cout << "get<0>: " << std::get<0>(p) << std::endl;
		std::cout << "get<1>: " << std::get<1>(p) << std::endl;
		std::cout << "tuple_size<>::value: " << std::tuple_size<IntFloatPair>::value << std::endl;
		std::tuple_element<0, IntFloatPair>::type a = p.first;
		std::cout << "tuple_element<0, IntFloatPair>: " << a << std::endl;

		std::pair<A, int> t2;
		return 0;	
}
