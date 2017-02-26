#include <iostream>
#include <string>

class Employee {
		public:
				Employee(): ID(++id_generator) { };
				Employee(std::string emp_name): name(emp_name), ID(++id_generator) { }
				Employee &operator=(const Employee &re) { ID = re.ID; name = re.name; return *this; }
				std::string name;
				std::size_t ID;
		private:
				static std::size_t id_generator;
};

std::size_t Employee::id_generator = 0;

void pr_employee(Employee e)
{
		std::cout << "name: " << e.name << " ID: " << e.ID << std::endl;
}

int main()
{
		Employee e1("e1"), e2("e2"), e3, e4 = e3;
		e3 = e2; // need copy assigned constructor
		pr_employee(e1);
		pr_employee(e2);
		pr_employee(e3);
		pr_employee(e4);
		return 0;
}
