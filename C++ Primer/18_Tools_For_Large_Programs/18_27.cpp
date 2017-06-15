#include <iostream>
#include <vector>

struct Base1
{
		void print(int) const
		{
				std::cout << "Base1 void print(int) const" << std::endl;
		}
		protected:
			int ival;
			double dval;
			char cval;
		private:
			int *id;
};

struct Base2
{
		void print(double) const
		{
				std::cout << "Base2 void print(double) const" << std::endl;
		}
		protected:
			double fval;
			double dval;
};

struct Derived : public Base1
{
		void print(std::string) const
		{
				std::cout << "Derived : public Base1 void print(std::string) const" << std::endl;
		}
		protected:
			std::string sval;
			double dval;
};

struct MI : public Derived, public Base2
{
		
		void print(std::vector<double>)
		{
				std::cout << "MI : public Derived, public Base2 print(std::vector<double>)" << std::endl;
		}
		void foo(double);
		protected:
			int *ival;
			std::vector<double> dvec;
};

int ival;
double dval;
void MI::foo(double cval)
{
		int dval;
		dval = Derived::Base1::dval + Base2::dval;
		std::cout << dval << std::endl;
  		if (dvec.size())
			dvec.pop_back();
	    dvec.push_back(Base2::fval);

		Derived::sval[0] = Base1::cval;
}
int main()
{
		MI mi;
		mi.foo(2);
		return 0;
}
