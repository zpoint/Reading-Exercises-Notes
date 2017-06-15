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
		private:
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
		
		void print(double d)
		{
				Base2::print(d);
		}
		
		protected:
			int *ival;
			std::vector<double> dvec;
};

int main()
{
		MI mi;
		mi.print(42);
		return 0;
}
