#include <string>
#include <iostream>

class HasPtr {
		public:
				friend void swap(HasPtr&, HasPtr&);

				HasPtr(const std::string &s = std::string()): ps(new std::string(s)), i(0) { }
				HasPtr(const HasPtr &p): ps(new std::string(*p.ps)), i(p.i) { }
				HasPtr& operator=(const HasPtr &);
				~HasPtr() { delete ps; }
		private:
				std::string *ps;
				int i;
};

HasPtr& HasPtr::operator=(const HasPtr &rhs)
{
		auto newp = new std::string(*rhs.ps);
		delete ps;
		ps = newp;
		i = rhs.i;
		return *this;
}

void swap(HasPtr &hp1, HasPtr &hp2)
{
		using std::swap;
		std::cout << "In swap!!!" << std::endl;
		swap(hp1.ps, hp2.ps);
		swap(hp1.i, hp2.i);
}

int main()
{
		// if don't have destructor, ps allocated by new can't be freed until the process exit
		// if don't have copy constructor, ps , the synthesize one will copy ps instead of create a new one
		HasPtr p1("p1"), p2("p2");
		using std::swap;
		swap(p1, p2);
		return 0;
}
