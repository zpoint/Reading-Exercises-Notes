#include <map>
#include <vector>
#include <list>
#include <iostream>

int main()
{
		std::vector<int> ivec{1, 2};
		std::cout << (ivec.end() < ivec.begin()) << std::endl;
		std::list<int> lst{1, 2};
		// std::cout << (lst.end() < lst.begin()) << std::endl;
		std::map<std::vector<int>::iterator, int> vec_iter_map;
		std::map<std::list<int>::iterator, int> lst_iter_map;
		vec_iter_map[ivec.begin()] = 5;
		lst_iter_map[lst.begin()] = 6;  // error, iterator of list has not < experssion, need to define a predicate manually
		/*
		std::cout << "vec: " << vec_iter_map[ivec.begin()];
		std::cout << "lst: " << lst_iter_map[lst.begin()];
		ivec.push_back(2);
		ivec.push_back(3);
		lst.push_back(2);
		lst.push_back(3);
		std::cout << "After push back: \n";
		std::cout << "vec: " << lst_iter_map[lst.begin()] << std::endl;
		std::cout << "lst: " << vec_iter_map[ivec.begin()] << std::endl;
		*/
		return 0;
}
