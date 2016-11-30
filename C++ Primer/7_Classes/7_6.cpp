#include <iostream>
#include <string>

struct Sales_data
{
		std::string ISBN;
		unsigned units_sold = 0;
		double revenue = 0.0;

		std::string isbn() const
		{
				return ISBN;
		}

		Sales_data &combine(const Sales_data sdata)
		{
				if (ISBN != sdata.ISBN)
						std::cout << "Combing different ISBN" << std::endl;
				units_sold += sdata.units_sold;
				revenue += sdata.revenue;
				return *this;
		}
		void pr_elements()
		{
				std::cout << "ISBN: " << ISBN << std::endl;
				std::cout << "units_sold: " << units_sold << std::endl;
				std::cout << "revenue: " << revenue << std::endl;
		}
};

Sales_date add(Sales_data &dataA, Sales_data &dataB)
{
		Sales_data new_data = dataA;
		new_data.units_sold += dataB.units_sold;
		new_data.revenue += dataB.revenue;
		return new_data;
}

std::istream &read(std::istream &cin, Sales_data &item)
{
		double price = 0.0;
		cin >> item.ISBN >> item.units_sold >> price;
		item.revenue = item.units_sold * price;
		return cin;
}

std::ostream &print(std::ostream &cout, const Sales_data &item)
{
		cout << item.isbn() << " " << item.units_sold << " " << item.revenue << " " << (item.units_sold == 0 ? 0 : (item.revenue / item.units_sold));
		return cout;
}

int main()
{
		Sales_data a;
		Sales_data b;
		b.units_sold = 10;
		std::cout << "a: ";
		a.pr_elements();
		std::cout << "a after combine b: ";
		a.combine(b);
		a.pr_elements();
		return 0;
}

