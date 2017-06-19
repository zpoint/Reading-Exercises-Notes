#include <iostream>

class Class
{
		public:
		Class()
		{
				std::cout << "Constructor of Class" << std::endl;
		}
		~Class()
		{
				std::cout << "Destructor of Class" << std::endl;
		}
};

class Base : public Class
{
		public:
		Base()
		{
				std::cout << "Constructor of Base" << std::endl;
		}
		~Base()
		{
				std::cout << "Destructor of Base" << std::endl;
		}
};

class D1 : virtual public Base
{
		public:
			D1()
			{
					std::cout << "Constructor of D1" << std::endl;
			}
			~D1()
			{
					std::cout << "Destructor of D1" << std::endl;
			}
};

class D2 : virtual public Base
{
		public:
			D2()
			{
					std::cout << "Constructor of D2" << std::endl;
			}
			~D2()
			{
					std::cout << "Destructor of D2" << std::endl;
			}
};

class MI : public D1, public D2
{
		public:
			MI()
			{
					std::cout << "Constructor of MI" << std::endl;
			}
			~MI()
			{
					std::cout << "Destructor of MI" << std::endl;
			}
};

class Final : public MI, public Class
{
		public:
			Final()
			{
					std::cout << "Constructor of Final" << std::endl;
			}
			~Final()
			{
					std::cout << "Destructor of FInal" << std::endl;
			}
};

int main()
{
		Final f;  // a
		std::cout << "***************" << std::endl;
		Base *pb;
		Class *pc;
		MI *pmi;
		D2 *pd2;
		// pb = new Class; error
		// pc = new Final; error ambigious Class
		// pmi = pb; // cannot convert from pointer to base class ‘Base’ to pointer to derived class ‘MI’ because the base is virtual
		pd2 = pmi;
		return 0;
}
