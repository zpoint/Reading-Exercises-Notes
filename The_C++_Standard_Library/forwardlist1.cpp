#include <forward_list>
#include <iostream>

template <typename T>
void PRINT_ELEMENTS(const T& CONTAINER, const std::string str="")
{
		std::cout << str << ": ";
		for (const auto &i : CONTAINER)
				std::cout << i << " ";
		std::cout << std::endl;
}

template <typename InputIterator, typename Tp>
inline InputIterator find_before(InputIterator first, InputIterator last, const Tp& val)
{
		if (first == last)
				return first;
		InputIterator next(first);
		++next;
		while (next != last and !(*next == val))
		{
				++next;
				++first;
		}
		return first;
}

template <typename InputIterator, typename Pred>
inline InputIterator find_before_if(InputIterator first, InputIterator last, Pred pred)
{
		if (first == last)
				return first;

		InputIterator next(first);
		++next;
		while (next != last && !pred(*next))
		{
				++next;
				++first;
		}
		return first;
}

int main()
{
		/* * * * * *
		 * FIND * *
		 * * * * * */
		std::forward_list<int> list = { 1, 2, 3, 4, 5, 97, 98, 99 };

		// find the position before the first even element
		std::forward_list<int>::iterator posBefore = list.before_begin();
		for (std::forward_list<int>::iterator pos = list.begin(); pos != list.end(); ++pos, ++posBefore)
		{
				if (*pos % 2 == 0)
						break; // element found
		}

		// and insert a new element in front of the first even element
		list.insert_after(posBefore, 42);
		PRINT_ELEMENTS(list);

		posBefore = find_before_if(list.before_begin(), list.end(), [] (int i) { return i % 2 == 0; });
		list.insert_after(posBefore, 42);
		PRINT_ELEMENTS(list);

		/* * * * * *
		 * SPLICE * *
		 * * * * * */
		std::forward_list<int> l1{ 1, 2, 3, 4, 5 }, l2{ 97, 98, 99 };
		PRINT_ELEMENTS(l1);
		PRINT_ELEMENTS(l2);
		std::forward_list<int>::iterator pos1 = l1.before_begin();
		for (std::forward_list<int>::iterator pb1 = l1.begin(); pb1 != l1.end(); ++pb1, ++pos1)
		{
				if (*pb1 == 3)
						break; // found
		}
		// find 99 in l2
		std::forward_list<int>::iterator pos2 = find_before(l2.before_begin(), l2.end(), 99);

		// splice 3 from l1 to l2 before 99
		l2.splice_after(pos2, l1, pos1);
		// l1.splice_after(pos2, l2, pos1); // ??? l2.splice_after(pos2, l1, pos1);
		PRINT_ELEMENTS(l1);
		PRINT_ELEMENTS(l2);
		return 0;
}
