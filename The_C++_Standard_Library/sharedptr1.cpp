#include <iostream>
#include <string>
#include <vector>
#include <memory>

int main()
{
		std::shared_ptr<std::string> pNico(new std::string("nico"), [] (std::string *p) { std::cout << "delete " << *p << std::endl; delete p;});
		std::shared_ptr<std::string> pJutta(new std::string("jutta"));

		(*pNico)[0] = 'N';
		pJutta->replace(0, 1, "J");

		std::vector<std::shared_ptr<std::string>> whoMadeCoffee;
		whoMadeCoffee.push_back(pJutta);
		whoMadeCoffee.push_back(pJutta);
		whoMadeCoffee.push_back(pNico);
		whoMadeCoffee.push_back(pJutta);
		whoMadeCoffee.push_back(pNico);

		for (auto ptr : whoMadeCoffee)
				std::cout << *ptr << "  ";
		std::cout << std::endl;

		*pNico = "Nicolai";
		std::cout << "use_count of whoMadeCoffee[2]: " << whoMadeCoffee[2].use_count() << std::endl;
		std::cout << "use_count of pNico: " << pNico.use_count() << " pNico: " << *pNico << std::endl;
		pNico = nullptr;
		pNico.reset(new std::string("NNN"));
		std::cout << "use_count of whoMadeCoffee[2]: " << whoMadeCoffee[2].use_count() << std::endl;
		std::cout << "use_count of pNico: " << pNico.use_count() << " pNico: " << *pNico << std::endl;

		for (auto ptr : whoMadeCoffee)
				std::cout << *ptr << "  ";
		std::cout << std::endl;

		whoMadeCoffee.resize(2);
		std::cout << "use_count: " << whoMadeCoffee[0].use_count() << std::endl;
		return 0;
}
