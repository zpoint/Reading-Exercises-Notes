#include <iostream>

struct Base1
{
		virtual void print()
		{
				std::cout << "print from Base1" << std::endl;
		}
		virtual ~Base1()
		{
				std::cout << "Base1 destructor" << std::endl;
		}

};

struct Base2
{
		virtual void print()
		{
				std::cout << "print from Base2" << std::endl;
		}
		virtual ~Base2()
		{
				std::cout << "Base2 destructor" << std::endl;
		}
};

class D1 : public Base1
{
		public:
			virtual void print() override
			{
					std::cout << "print from D1 : public Base1" << std::endl;
			}
			virtual ~D1() override
			{
					std::cout << "D1 : public Base1 destructor" << std::endl;
			}

};

class D2 : public Base2
{
		public:
			virtual void print() override
			{
					std::cout << "print from D2 : public Base2" << std::endl;
			}
			virtual ~D2() override
			{
					std::cout << "D2 : public Base2 destructor" << std::endl;
			}
};

class M1 : public D1, public D2
{
};
			

int main()
{
		Base1 *pb1 = new M1;
		Base1 *pb2 = new M1;
		D1 *pd1 = new M1;
		D2 *pd2 = new M1;
		pb1->print();
		pd1->print();
		pd2->print();
		delete pb2;
		delete pd1;
		delete pd2;
		return 0;
}
