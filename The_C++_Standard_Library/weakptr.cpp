#include <iostream>
#include <string>
#include <vector>
#include <memory>

class Person
{
		public:
			std::string name;
			std::shared_ptr<Person> mother;
			std::shared_ptr<Person> father;
			std::vector<std::shared_ptr<Person>> kids;

			Person (const std::string& n, std::shared_ptr<Person> m = nullptr, std::shared_ptr<Person> f = nullptr): name(n), mother(m), father(f) {}
			~Person() { std::cout << "delete " << name << std::endl; }
};

class Person2: public Person, public std::enable_shared_from_this<Person>
{
		public:
			void setParentAndTheirKids (std::shared_ptr<Person> m = nullptr, std::shared_ptr<Person> f = nullptr)
			{
					mother = m;
					father = f;
					if (m != nullptr)
							m->kids.push_back(shared_from_this());
					if (f != nullptr)
							f->kids.push_back(shared_from_this());
			}
};

std::shared_ptr<Person> initFamily (const std::string& name)
{
		std::shared_ptr<Person> mom(new Person(name + "'s mom"));
		std::shared_ptr<Person> dad(new Person(name + "'s dad"));
		std::shared_ptr<Person> kid(new Person(name, mom, dad));
		mom->kids.push_back(kid);
		dad->kids.push_back(kid);
		return kid;
}

int main()
{
		std::shared_ptr<Person> p = initFamily("nico");

		std::cout << "nico's family exists" << std::endl;
		std::cout << "- nico is shared " << p.use_count() << " times" << std::endl;
		std::cout << "- name of 1st kid of nico's mom: " << p->mother->kids[0]->name << std::endl;

		p = initFamily("jim");
		std::cout << "jim's family exists" << std::endl;
		return 0;
}
