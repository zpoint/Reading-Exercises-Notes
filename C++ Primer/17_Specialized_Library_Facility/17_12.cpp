#include <bitset>
#include <iostream>
#define Q_SIZE 10

template <size_t sz>
void set_question(std::istream &cin, std::bitset<sz> &quiz)
{
		std::cout << "Max Limit: " << Q_SIZE << "\nEnter position of question, and T/F to indicate True or False, Q to quit, example: 3 T" << std::endl;
		size_t pos;
		std::string val;
		while (cin >> pos >> val)
		{
				if (val == "T")
						quiz.set(pos, true);
				else if (val == "F")
						quiz.set(pos, false);
				else if (val == "Q")
						break;
				else
						throw std::runtime_error("Out of range, Please enter T or F");
		}

}

int main()
{
		std::bitset<Q_SIZE> quiz;
		set_question(std::cin, quiz);
		std::cout << quiz << std::endl;
		// just change Q_SIZE
		return 0;
}
