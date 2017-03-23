#include <iostream>

class Base
{
		public:
			void pub_mem() {std::cout << "pub_mem in Base" << std::endl;};
		protected:
			int prot_mem;
		private:
			char priv_mem;
};

struct Pub_Derv : public Base
{
		int f() { return prot_mem; }
		void memfcn(Base &b) { b = *this; }
};

struct Priv_Derv : private Base
{
		int f1() const { return prot_mem; }
		void memfcn(Base &b) { b = *this; }
};

struct Prot_Derv : protected Base
{
		int f1() const { return prot_mem; }
		void memfcn(Base &b) { b = *this; }
};

struct Derived_from_Public : public Pub_Derv
{
		int use_base() { return prot_mem; }
		void memfcn(Base &b) { b = *this; }
};

struct Derived_from_Private : public Priv_Derv
{
		// base is inaccessible for here
		/*
		void memfcn(Base &b) { b = *this; }
		*/
};

struct Derived_from_Protected : public Prot_Derv
{
		int use_base() { return prot_mem; }
		void memfcn(Base &b) { b = *this; }
};

int main()
{
		Base b;
		Pub_Derv d1;
		Priv_Derv d2;
		Prot_Derv d3;
		Derived_from_Public dd1;
		Derived_from_Private dd2;
		Derived_from_Protected dd3;
		Base *p = &d1;
		Base &rp = d1;
		// p = &d2; // error
		// p = &d3; // error
		p = &dd1;
		// p = &dd2; // error
		// p = &dd3; // error
		// good
		//d1.memfcn(rp);
		// d2.memfcn(b);
		d3.memfcn(b);
		dd1.memfcn(b);
		dd3.memfcn(b);		
		return 0;
}
