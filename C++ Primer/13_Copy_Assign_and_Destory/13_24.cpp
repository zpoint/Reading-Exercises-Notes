#include <string>

class HasPtr {
		public:
				HasPtr(const std::string &s = std::string()): ps(new std::string(s)), i(0) { }
				// HasPtr(const HasPtr &p): ps(new std::string(*p.ps)), i(p.i) { }
				HasPtr& operator=(const HasPtr &);
				// ~HasPtr() { delete ps; }
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

int main()
{
		// if don't have destructor, ps allocated by new can't be freed until the process exit
		// if don't have copy constructor, ps , the synthesize one will copy ps instead of create a new one
		HasPtr p1("p1"), p2 = p1;
		p2 = p1;
		return 0;
}
