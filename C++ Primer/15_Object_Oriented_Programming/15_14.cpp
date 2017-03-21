#include <iostream>
#include <string>

class base
{
		public:
			std::string name() { return basename; }
			virtual void print(std::ostream &os) { os << "base version: " << basename << std::endl; }

		private:
			std::string basename;
};

class derived : public base
{
		public:
			// all path through this function will call itself
			void print(std::ostream &os) { base::print(os); os << "derived version: " << i << std::endl; }
		private:
			int i;
};

int main()
{
		base bobj;
		base *bp1 = &bobj;
		base &br1 = bobj;
		derived dobj;
		base *bp2 = &dobj;
		base &br2 = dobj;
		// a
		bobj.print(std::cout);
		// b
		dobj.print(std::cout);
		// c
		bp1->print(std::cout);
		// d
		std::cout << bp2->name() << std::endl;
		// e
		br1.print(std::cout);
		// f
		br2.print(std::cout);
		return 0;
}
