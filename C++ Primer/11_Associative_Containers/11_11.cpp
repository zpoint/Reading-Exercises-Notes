#include <set>
#include <string>

class Sales_data {
		public:
			std::string ISBN;
			std::string isbn() const { return this->ISBN; }
};

bool compareIsbn(const Sales_data &lhs, const Sales_data &rhs)
{
		return lhs.isbn() < rhs.isbn();
}

int main()
{
		Sales_data S;
		std::multiset<Sales_data, bool (*) (const Sales_data&, const Sales_data &)> bookstore(compareIsbn);
		bookstore.insert(S);
		return 0;
}
