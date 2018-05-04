#include <forward_list>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <string>

void printLists (const std::string& s, const std::forward_list<int>& l1, const std::forward_list<int>& l2)
{
		std::cout << s << std::endl;
		std::cout << " list1: ";
		std::copy(l1.cbegin(), l1.cend(), std::ostream_iterator<int>(std::cout, " "));
		std::cout << std::endl << " list2: ";
		std::copy(l2.cbegin(), l2.cend(), std::ostream_iterator<int>(std::cout, " "));
		std::cout << std::endl;
}

int main()
{
		// create two forward lists
		std::forward_list<int> list1 = { 1, 2, 3, 4 };
		std::forward_list<int> list2 = { 77, 88, 99 };
		printLists("initial: ", list1, list2);

		// insert six new element at the beginning of list2
		list2.insert_after(list2.before_begin(), 99);
		list2.push_front(10);
		list2.insert_after(list2.before_begin(), { 10, 11, 12, 13});
		printLists("6 new elems: ", list1, list2);

		// insert all elements of list2 at the beginning of list1
		list1.insert_after(list1.before_begin(), list2.begin(), list2.end());
		printLists("list2 into list1: ", list1, list2);

		// delete second element and elements after element with value 99
		list2.erase_after(list2.begin());
		list2.erase_after(std::find(list2.begin(), list2.end(), 99));
		printLists("delete 2nd and after 99:", list1, list2);

		// sort list1, assign it to list2, and remove duplicates
		list1.sort();
		list2 = list1;
		list2.unique();
		printLists("sorted and unique:", list1, list2);

		// merge both sorted list into list1
		list1.merge(list2);
		printLists("merged:", list1, list2);
		return 0;
}
