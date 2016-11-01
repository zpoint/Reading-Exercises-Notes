#ifndef SALES_DATA_H
#define SALES_DATA_H
#include <string>
struct Sales_data
{
		std::string ISBN;
		unsigned unit_sold = 0;
		double revenue = 0.0;
};
#endif
