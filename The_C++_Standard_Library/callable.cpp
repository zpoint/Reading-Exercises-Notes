#include <iostream>
#include <future>

void func (int x, int y)
{
		std::cout << "In func: " << " x: " << x << " y: " << y << std::endl;
}

auto l = [] (int x, int y)
{
		std::cout << "In auto l: " << " x: " << x << " y: " << y << std::endl;
};

class C
{
		public:
			void operator() (int x, int y) const
			{
					std::cout << "class C operator() x: " << x << " y: " << y << std::endl;
			}
			void memfunc(int x, int y) const
			{
					std::cout << " class C memfunc x: " << x << " y: " << y << std::endl;
			}
};

int main(int argc, char *argv [])
{
		C c;
		c(1, 2);
		C()(1,2);
		std::shared_ptr<C> sp(new C);

		std::bind(func, 77, 33)();
		std::bind(l, 77, 33)();
		std::bind(C(), 77, 33);
		std::bind(&C::memfunc, c, 77, 33)(); 
		std::bind(&C::memfunc, sp, 77, 33)();

		std::async(func, 1, 1);
		std::async(l, 2, 2);
		std::async(c, 3, 3);
		std::async(&C::memfunc, &c, 4, 4);
		std::async(&C::memfunc, sp, 5, 5);
		return 0;
}
