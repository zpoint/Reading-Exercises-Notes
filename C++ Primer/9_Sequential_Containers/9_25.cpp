#include <iostream>
#include <list>

void pr_li(std::list<int> li, const char *str)
{
		std::cout << str << "\n";
		std::cout << "Elements in li: ";  
		for (const auto i : li)
				std::cout << i << " ";
		std::cout << std::endl;
}

int main()
{
		std::list<int> l1 = {1, 2};
		std::list<int>::iterator elem1, elem2;
		pr_li(l1, "Before operating");

		elem1 = elem2 = l1.begin();
		std::cout << "elem1, elem2 both denote to the first element" << std::endl;
		l1.erase(elem1, elem2);
		pr_li(l1, "After erase from elem1 to elem2: ");
		
		elem1 = elem2 = l1.end();
		std::cout << "elem1, elem2 both denote the off-the-end iterator" << std::endl;
		l1.erase(elem1, elem2);
		pr_li(l1, "After erase from elem1 to elem2: ");

		elem1 = elem2 = l1.begin();
		++elem2;
		std::cout << "elem1 is the 1th element in li, elem2 is the second" << std::endl;
		l1.erase(elem1, elem2);
		pr_li(l1, "After erase from elem1 to elem2: ");
		return 0;
}
