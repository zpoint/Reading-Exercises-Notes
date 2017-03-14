#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

class test {
		public:
			bool operator()(const std::string &str1, const std::string &str2) { return str1.size() < str2.size(); }
};

class test2 {
		public:
			test2(std::size_t s): sz(s) { }
			bool operator()(const std::string &str) { return str.size() >= sz; }
		private:
			std::size_t sz;
};

class test3 {
		public:
			void operator()(const std::string &str) { std::cout << str << " "; }
};

void biggies(std::vector<std::string> &words, std::vector<std::string>::size_type sz)
{
		std::stable_sort(words.begin(), words.end(), test());
		auto wc = std::find_if(words.begin(), words.end(), test2(sz));
		std::for_each(wc, words.end(), test3());
		std::cout << std::endl;
}

int main()
{
		std::vector<std::string> vec = { "123", "fdsaf", "cx", "dfsaf" };
		biggies(vec, 4);
		return 0;
}
