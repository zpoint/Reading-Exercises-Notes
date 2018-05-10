#include <functional>
#include <algorithm>
#include <vector>
#include <iostream>
#include <string>

class Person
{
		private:
			std::string name;
		public:
			Person (const std::string& n): name(n) { }
			void print() const
			{
					std::cout << name << std::endl;
			}
			void print2 (const std::string& prefix) const
			{
					std::cout << prefix << name << std::endl;
			}
};

int main()
{
		std::vector<Person> coll = { Person("Tick"), Person("Trick"), Person("Track") };
		std::vector<Person*> cp;
		Person t1("t1");
		Person t2("t2");
		cp.push_back(&t1);
		cp.push_back(&t2);
		(**cp.begin()).print();

		// call member function print() for each person
		std::for_each(coll.begin(), coll.end(), std::bind(&Person::print2, std::placeholders::_1, "Person: "));
		std::cout << std::endl;

		// call prit2() for temporary Person
		std::bind(&Person::print2, std::placeholders::_1, "This is: ")(Person("nico"));

		auto f = std::bind(&Person::print2, std::placeholders::_1, "Person pointer: ");
		f(t1);
		f(&t1);
		f(cp[0]);
		std::for_each(cp.begin(), cp.end(), std::bind(&Person::print2, std::placeholders::_1, "Person pointer: "));

		return 0;
}
