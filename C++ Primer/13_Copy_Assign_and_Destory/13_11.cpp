#include <iostream>
#include <string>

class HasPtr {
		public:
				HasPtr(const std::string &s = std::string()): ps(new std::string(s)), i(0) { }
				HasPtr(const HasPtr&);
				HasPtr& operator=(const HasPtr&);
				~HasPtr();
				std::string *ps;
				int i;
};

HasPtr::HasPtr(const HasPtr &hp)
{
		ps = new std::string(*hp.ps);
		i = hp.i;
}

HasPtr& HasPtr::operator=(const HasPtr &rh)
{
		ps = new std::string(*rh.ps);
		i = rh.i;
		return *this;
}

HasPtr::~HasPtr()  // destructor
{
		delete ps;
}

int main()
{
		HasPtr p1("HasPtr1");
		HasPtr p2 = p1;
		std::cout << *p2.ps << std::endl;
		return 0;
}
