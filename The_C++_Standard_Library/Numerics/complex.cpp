#include <iostream>
#include <complex>

int main()
{
		// complex number with real and imaginary parts
		// - real part 4.0
		// - imaginary part 3.0
		std::complex<double> c1(4.0, 3.0);

		// create complex number from polar coordinates
		// - magnitude: 5.0
		// - phase angle: 0.75
		std::complex<float> c2(std::polar(5.0, 0.75));

		// print complex number with real and imaginary parts
		std::cout << "c1: " << c1 << std::endl;
		std::cout << "c2: " << c2 << std::endl;

		// print complex numbers as polar coordinates
		std::cout << "c1: magnitude: " << std::abs(c1)
				  << " (squared magnitude: " << std::norm(c1) << ") "
				  << " phase angle: " << std::arg(c1) << std::endl;
		std::cout << "c2: magnitude: " << std::abs(c2)
				  << "(squared magnitude: " << std::norm(c2) << ") "
				  << " phase angle: " << std::arg(c2) << std::endl;

		// print complex conjugates
		std::cout << "c1 conjugated: " << std::conj(c1) << std::endl;
		std::cout << "c2 conjugated: " << std::conj(c2) << std::endl;

		// print result of a computation
		std::cout << "4.4 + c1 * 1.8: " << 4.4 + c1 * 1.8 << std::endl;

		// print sum of c1 and c2:
		// - note: different types
		std::cout << "c1 + c2:        "
				  << c1 + std::complex<double>(c2.real(), c2.imag()) << std::endl;

		// add square root of c1 to c1 and print the result
		std::cout << "c1 += sqrt(c1): " << (c1 += std::sqrt(c1)) << std::endl;

		return 0;
}
