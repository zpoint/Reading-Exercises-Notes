#include <map>
#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>

namespace MyLib
{
		template <typename Cont>
		inline bool replace_key (Cont& c, const typename Cont::key_type& old_key, const typename Cont::key_type& new_key)
		{
				typename Cont::iterator pos;
				pos = c.find(old_key);
				if (pos != c.end())
				{
						// insert new element with value of old element
						c.insert(typename Cont::value_type(new_key, pos->second));
						// remove old element
						c.erase(pos);
						return true;
				}
				else
				{
						// key not found
						return false;
				}
		}
}


int main()
{
		std::map<std::string, float> coll1 = {{"old key", 11.2}};
		MyLib::replace_key(coll1, "old_key", "new_key");

		std::map<std::string, double> coll { { "tim", 9.9 },
											 { "struppi", 11.77 }
											};
		// square the value of each element
		std::for_each(coll.begin(), coll.end(),
					  [] (std::pair<const std::string, double>& elem) { elem.second *= elem.second; });
		// print each element
		std::for_each(coll.begin(), coll.end(), [] (const std::map<std::string, double>::value_type& elem)
						{ std::cout << elem.first << ": " << elem.second << std::endl; } );

		/* * * * * * *
		* map2.cpp *
		* * * * * * */
		typedef std::map<std::string, float> StringFloatMap;

		StringFloatMap stocks; // create empty container

		// insert some elements
		stocks["BASF"] = 369.50;
		stocks["VW"] = 413.50;
		stocks["Daimler"] = 819.00;
		stocks["BMW"] = 834.00;
		stocks["Siemens"] = 842.20;

		// print all elements
		StringFloatMap::iterator pos;
		std::cout << std::left; // left-adjust values
		for (pos = stocks.begin(); pos != stocks.end(); ++pos)
		{
				std::cout << "stock: " << std::setw(12) << pos->first
						  << "price: " << pos->second << std::endl;
		}
		std::cout << std::endl;

		// boom(all prices doubled)
		for (pos = stocks.begin(); pos != stocks.end(); ++pos)
				pos->second *= 2;

		// print all elements
		for (pos = stocks.begin(); pos != stocks.end(); ++pos)
		{
				std::cout << "stock: " << std::setw(12) << pos->first
						  << "price: " << pos->second << std::endl;
		}
		std::cout << std::endl;

		// rename keyfrom "Vw" to "Volkswagen"
		// - provided only by exchanging element
		stocks["Volkswagen"] = stocks["VW"];
		stocks.erase("VW");

		// print all elements
		for (pos = stocks.begin(); pos != stocks.end(); ++pos)
		{
				std::cout << "stock: " << std::setw(12) << pos->first
						  << "price: " << pos->second << std::endl;
		}

		return 0;
}
