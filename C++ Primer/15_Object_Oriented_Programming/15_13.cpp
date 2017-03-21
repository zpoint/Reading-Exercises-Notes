#include <iostream>
#include <string>

class base
{
		public:
			std::string name() { return basename; }
			virtual void print(std::ostream &os) { os << "base version: " << basename; }

		private:
			std::string basename;
};

class derived : public base
{
		public:
			// all path through this function will call itself
			void print(std::ostream &os) { base::print(os); os << " " << i; }
		private:
			int i;
};

int main()
{
		derived d;
		d.print(std::cout);
		std::cout << std::endl;
		return 0;
}
