#include "algostuff.hpp"


// function object to process the mean value
class MeanValue
{
		private:
			long num; // number of elements
			long sum; // sum of element values
		public:
			// constructor
			MeanValue () : num(0), sum(0) { }

			// function call
			// - process one more element of the sequence
			void operator() (int elem)
			{
					num++; // increment count
					sum += elem; // add value
			}

			// return mean value (implicit type conversion)
			operator double()
			{
					return static_cast<double>(sum) / static_cast<double>(num);
			}
};

int main()
{
		std::vector<int> coll;

		INSERT_ELEMENTS(coll, 1, 8);

		// process and print mean value
		double mv = std::for_each(coll.begin(), coll.end(), MeanValue());
		std::cout << "mean value: " << mv << std::endl;
		return 0;
}
