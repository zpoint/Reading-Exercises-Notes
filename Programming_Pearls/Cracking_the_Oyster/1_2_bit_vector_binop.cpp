#include <iostream>

class BitVector
{
		public:
			// assume size of vector is 32
			BitVector(int i): result(i) {}
			int get_result() { return this->result; }
			int size() { return 32; }
			// binary op
			BitVector operator& (BitVector& other) { return BitVector(this->get_result() & other.get_result());}
			BitVector operator| (BitVector& other) { return BitVector(this->get_result() | other.get_result());}
		private:
			int result = 0;
};

std::ostream& operator<< (std::ostream &os, BitVector &bv)
{
		int size = bv.size();
		int result = bv.get_result();
		while (size > 0)
		{
				// from highest bit to lowest bit
				int mask = 1 << --size;
				if (mask & result)
						os << size + 1 << " ";
		}
		return os;
}

int main()
{
		BitVector bv1 = BitVector(1);
		BitVector bv2 = BitVector(-2);
		BitVector bv3 = bv1 & bv2;
		BitVector bv4 = bv1 | bv2;
		std::cout << "bv1: " << bv1 << std::endl;
		std::cout << "bv2: " << bv2 << std::endl;
		std::cout << "bv1 & bv2: " << bv3 << std::endl;
		std::cout << "bv1 | bv2: " << bv4 << std::endl;
		return 0;
}
