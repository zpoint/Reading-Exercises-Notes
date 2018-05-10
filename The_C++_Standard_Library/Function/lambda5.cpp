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
			Person(const std::string& n): name(n) { }

			void print() const { std::cout << name << std::endl; }

			void print2(const std::string& prefix) const { std::cout << prefix << name << std::endl; }
};

int main()
{
		std::vector<Person> coll = { Person("Tick"), Person("Trick"),Person("Track") };
		Person t1("t1");
		Person t2("t2");

		// call member function print() for each person
		std::for_each(coll.begin(), coll.end(), [] (const Person& p) { p.print(); });
		std::cout << std::endl;

		auto f = [] (const Person& p) { p.print2("Person: "); };
		f(t1);

		std::for_each(coll.begin(), coll.end(), f);

		return 0;
}
