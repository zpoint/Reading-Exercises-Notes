#include <string>
#include <iostream>

struct Person {
		std::string name;
		std::string address;

		std::string get_name() const;
		std::string get_address() const;
};

std::string Person::get_name() const
{
		return name;
}

std::string Person::get_address() const
{
		return address;
}

std::istream &read(std::istream &cin, Person p)
{
		cin >> p.name >> p.address;
		return cin;
}

std::ostream &print(std::ostream &cout, const Person p)
{
		cout << p.name << " " << p.address;
		return cout;
}
