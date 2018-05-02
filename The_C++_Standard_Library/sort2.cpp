#include <algorithm>
#include <deque>
#include <string>
#include <iostream>

class Person
{
		public:
			std::string firstname() const { return FirstName; }
			std::string lastname() const { return LastName; }
			Person(const std::string& lastname, const std::string& firstname): FirstName(firstname), LastName(lastname) {}
		private:
			std::string FirstName;
			std::string LastName;
};

template <typename T>
void PRINT_PERSON_CONTAINER(const T& CONTAINER, const std::string& tip="")
{
		std::cout << tip << ": \n";
		for (const auto& i : CONTAINER)
				std::cout << i.lastname() << ", " << i.firstname() << "\n";
		std::cout << std::endl;
}

int main()
{
		std::deque<Person> coll{Person("m", "b"), Person("aa", "bb"), Person("aa", "cc"), Person("x", "c")};
        PRINT_PERSON_CONTAINER(coll, "before sort");
		std::sort(coll.begin(), coll.end(), [] (const Person& p1, const Person& p2) 
												{ return p1.lastname()<p2.lastname() || (p1.lastname() == p2.lastname() && p1.firstname()<p2.firstname()); });
		PRINT_PERSON_CONTAINER(coll, "after sort");
		return 0;
}
