/*	CmSc 117 Exercise 1
*	Name: Gisselle Derije
*	Date: 28 September 2020
*	Software: Visual Studio 2019
*/

//Implementation of Quartic Calculator
#include <iomanip>
#include "quartic.hpp"

int main() {
	complex_d_t x[4];																																	//Pre-allocate array of solutions
	double a = 2.0, b = 3.0, c = 4.0, d = 5.0, e = 6.0;																									//Coefficients of a) 2x^4 + 3x^3 + 4x^2 + 5x + 6 = 0

	char item;																																			//Variable to allocate user choice
	std::cout << "Which equation do you want to solve? " << std::endl;
	std::cout << "1. 2x^4 + 3x^3 + 4x^2 + 5x + 6" << std::endl << "2.  x^4 - 2x^3 + 3x^2 - 4x" << std::endl << "3. 4x^4 - 9x^2 + 2" << std::endl;
	std::cout << "1, 2 or 3? ";
	std::cin >> item;

	switch (item) {
	case '1':
		quartic(a, b, c, d, e, x);																														//Apply quartic calculator
		std::cout << std::endl << "The solutions of the quartic equation f(x) = " << a << "x^4 + " << b << "x^3 + " << c << "x^2 + " << d << "x + " << e << " = 0 " << "are:" << std::endl;
			//Print solutions and function values
		std::cout << std::scientific << std::setprecision(8);
		for (int k = 0; k < 4; k++) {
			std::cout << "x = " << x[k] << "\t";
			std::cout << "f(x) = " << evalQuartPoly(a, b, c, d, e, x[k]) << std::endl;
		}
		break;
	case '2':
		a = 1.0, b = -2.0, c = 3.0, d = -4.0, e = 0.0;																									//Coefficients of x^4 - 2x^3 + 3x^2 - 4x = 0
		quartic(a, b, c, d, e, x);																														//Apply quartic calculator
		std::cout << std::endl << "The solutions of the quartic equation f(x) = " << "x^4 + " << b << "x^3 + " << c << "x^2 + " << d << "x" << " = 0 " << "are:" << std::endl;
			//Print solutions and function values
		std::cout << std::scientific << std::setprecision(8);
		for (int k = 0; k < 4; k++) {
			std::cout << "x = " << x[k] << "\t";
			std::cout << "f(x) = " << evalQuartPoly(a, b, c, d, e, x[k]) << std::endl;
		}
		break;
	case '3':
		a = 4.0, b = 0.0, c = -9.0, d = 0.0, e = 2.0;																									//Coefficients of 4x^4 - 9x^2 + 2 = 0
		quartic(a, b, c, d, e, x);																														//Apply quartic calculator
		std::cout << std::endl << "The solutions of the quartic equation f(x) = " << a << "x^4 + " << c << "x^2 + " << e << " = 0 " << "are:" << std::endl;
			//Print solutions and function values
		std::cout << std::scientific << std::setprecision(8);
		for (int k = 0; k < 4; k++) {
			std::cout << "x = " << x[k] << "\t";
			std::cout << "f(x) = " << evalQuartPoly(a, b, c, d, e, x[k]) << std::endl;
		}
		break;
	default:
		std::cout << std::endl << "Error! Invalid input!" << std::endl;
		break;
	}
	return 0;
}