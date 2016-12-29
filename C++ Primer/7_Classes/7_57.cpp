#include <string>
#include <iostream>

class Account {
		public:
				static double rate() { return interestRate; }
				static void rate(double);
		private:
				static double interestRate;
				static double initRate();
				static constexpr int period = 30;
				double daily_tbl[period];
};

double Account::interestRate = 0.3;
double Account::initRate()
{
		std::cout << "initRate" << std::endl;
}

void Account::rate(double newRate)
{
		interestRate = newRate;
}



int main()
{
		Account ac;
		return 0;
}
