#ifndef QUARTIC_HPP_INCLUDE
#define QUARTIC_HPP_INCLUDE

#include "complex.hpp"

//Evaluates az^4 + bz^3 + cz^2 + dz + e using nested multiplication
complex_d_t evalQuartPoly(double a, double b, double c, double d, double e, complex_d_t &z) {
	complex_d_t val;
	val = a * z + b;
	val = val * z + c;
	val = val * z + d;
	val = val * z + e;
	return val;
}

//quartic calculator
void quartic(double a, double b, double c, double d, double e, complex_d_t x[]) {
	//General parameters
	complex_d_t j = complex_d_t(0.0, 1.0);																												//Defined by j = sqrt(-1)
	complex_d_t discriminant = (256.0 * a * a * a * e * e * e) - (192.0 * a * a * b * d * e * e) - (128.0 * a * a * c * c * e * e) + (144.0 * a * a * c * d * d * e) - (27.0 * a * a * d * d * d * d) + (144.0 * a * b * b * c * e * e) - (6.0 * a * b * b * d * d * e) - (80.0 * a * b * c * c * d * e) + (18.0 * a * b * c * d * d * d) + (16.0 * a * c * c * c * c * e) - (4.0 * a * c * c * c * d * d) - (27.0 * b * b * b * b * e * e) + (18.0 * b * b * b * c * d * e) - (4.0 * b * b * b * d * d * d) - (4.0 * b * b * c * c * c * e) + (b * b * c * c * d * d);				  //Quartic discriminant
	complex_d_t P = (8.0 * a * c) - (3.0 * b * b);
	complex_d_t R = (b * b * b) + (8.0 * d * a * a) - (4.0 * a * b * c);
	complex_d_t delta = (c * c) - (3.0 * b * d) + (12.0 * a * e);
	complex_d_t D = (64.0 * a * a * a * e) - (16.0 * a * a * c * c) + (16.0 * a * b * b * c) - (16.0 * a * a * b * d) - (3.0 * b * b * b * b);
	complex_d_t s1 = (a + b + c + d + e) / a;
	complex_d_t k = a / a;																																//Simplify the whole equation to a = 1
	complex_d_t l = b / a;																																//Simplified b value
	complex_d_t m = c / a;																																//Simplified c value
	complex_d_t n = d / a;																																//Simplified d value
	complex_d_t o = e / a;																																//Simplified e value

	/*after simplifying the original equation we will get x^4 + hy^2 + fy + g = 0
	where:*/
	complex_d_t h = m - ((3.0 * l * l) / 8.0);
	complex_d_t f = n + ((l * l * l) / 8.0) - ((l * m) / 2.0);
	complex_d_t g = o - ((3.0 * l * l * l * l) / 256.0) + ((l * l * m) / 16.0) - ((l * n) / 4.0);
	
	/*There is a total of three cases and a special case, they happen if o = 0, g = 0, f = 0 or e, f and g are all nonzero.
	* Determine if the equation belong to any of the cases. Stated below are the cases for each equation:
	* a) o, f and g are all nonzero (o.real() != 0 && f.real() != 0 && g.real() != 0)
	* b) o is equal to 0 (o.real() == 0)
	* c) f is equal to 0 (f.real() == 0)
	All 4 cases are defined in this hpp file, as long as the numbers are mulitples of the equations stated in the exercise, there should be no problem in solving.
	*/
	if (o.real() != 0) {																																
		if (f.real() == 0) {																															//In this case c) 4x^4 - 9x^2 + 2 = 0
			//Computation of solutions for Case 3: f = 0
			x[0] = -2.0 / a;
			x[1] = 2.0 / a;
			x[2] = std::sqrt(4.0 / e);
			x[3] = -std::sqrt(4.0 / e);
			std::cout << std::endl << "Case 3: f = 0" << std::endl;
		}

		else {																																			//o, f and g are nonzero
			if (o.real() != 0 && f.real() != 0 && g.real() != 0) {																						//a) 2x^4 + 3x^3 + 4x^4 + 5x + 6 = 0
				//Parameter for Special Case: e, f & g are not equal to 0
				complex_d_t p = m - ((3.0 * b * b) / (8.0 * a * a));
				complex_d_t q = n - (b * c) / (2.0 * a * a) + (b * b * b) / (8.0 * a * a * a);
				complex_d_t r = o - ((b * d) / 4.0 * a * a) + ((b * b * c) / 16.0 * a * a * a) - ((3.0 * b * b * b * b) / (256.0 * a * a * a * a));
				complex_d_t beta = q * q;																												//An APPROXIMATION of the value beta, there are 3 beta values and beta = q * q is the closest to the root value from a quartic equation calculator
				//Computation of solutions for Special Case: e, f & g are not equal to 0
				x[0] = ((0.5) * (std::sqrt(beta) + std::sqrt(beta - 2.0 * (p + beta + (q / std::sqrt(beta)))))) - (b / (4.0 * a));						//Or in other notes assume x = y - a / 4
				x[1] = ((0.5) * (std::sqrt(beta) - std::sqrt(beta - 2.0 * (p + beta + (q / std::sqrt(beta)))))) - (b / (4.0 * a));
				x[2] = ((0.5) * (-std::sqrt(beta) + std::sqrt(beta - 2.0 * (p + beta - (q / std::sqrt(beta)))))) - (b / (4.0 * a));
				x[3] = ((0.5) * (-std::sqrt(beta) - std::sqrt(beta - 2.0 * (p + beta - (q / std::sqrt(beta)))))) - (b / (4.0 * a));
				std::cout << std::endl << "Special Case: e, f & g are not equal to 0" << std::endl;
			}
		}
	}

	else {	
		//Parameter for Case 1: e = 0 and Case 2: g = 0
		complex_d_t q = ((3.0 * k * m) - (l * l)) / (9.0 * k * k);																						//An application of cardano's formula
		complex_d_t r = ((9.0 * k * l * m) - (27.0 * k * k * n) - (2.0 * l * l * l)) / (54.0 * k * k * k);
		complex_d_t D = (q * q * q) + (r * r);
		complex_d_t u = r + std::sqrt(D);
		complex_d_t v = r - std::sqrt(D);
		complex_d_t s, t;

		if (u.real() >= 0.0)
			s = std::pow(u, 1.0 / 3.0);
		else
			s = -std::pow(-u, 1.0 / 3.0);
		if (v.real() >= 0.0)
			t = std::pow(v, 1.0 / 3.0);
		else
			t = -std::pow(-v, 1.0 / 3.0);	

		if (o.real() == 0) {																															//o.real() == 0	(e = 0)	
			//Computation of solutions for Case 1: e = 0
			x[0] = 0;																																	//b) x^4 - 2x^3 + 3x^2 - 4x = 0
			x[1] = s + t - b / (3.0 * a);
			x[2] = -0.5 * (s + t) - b / (3.0 * a) + std::sqrt(3.0) * j * (s - t) / 2.0;
			x[3] = -0.5 * (s + t) - b / (3.0 * a) - std::sqrt(3.0) * j * (s - t) / 2.0;
			std::cout << std::endl << "Case 1: e = 0" << std::endl;
		}

		else if (g.real() == 0) {
			//Computation of solutions for Case 2: g = 0
			x[0] = -a / 4.0;
			x[1] = s + t - b / (3.0 * a) - a / 4.0;
			x[2] = -0.5 * (s + t) - b / (3.0 * a) + std::sqrt(3.0) * j * (s - t) / 2.0 - a / 4.0;
			x[3] = -0.5 * (s + t) - b / (3.0 * a) - std::sqrt(3.0) * j * (s - t) / 2.0 - a / 4.0;
			std::cout << std::endl << "Case 2: g = 0" << std::endl;
		}

		else
			return;
	}

	/*NATURE OF ROOTS
	* The possible cases for the nature of the roots are as follows:
	* If ∆ < 0 then the equation has two distinct real roots and two complex conjugate non-real roots.
	* If ∆ > 0 then either the equation's four roots are all real or none is.
	*	If P < 0 and D < 0 then all four roots are real and distinct.
	*	If P > 0 or D > 0 then there are two pairs of non-real complex conjugate roots.
	* If ∆ = 0 then (and only then) the polynomial has a multiple root. Here are the different cases that can occur:
	*	If P < 0 and D < 0 and ∆0 ≠ 0, there are a real double root and two real simple roots.
	*	If D > 0 or (P > 0 and (D ≠ 0 or R ≠ 0)), there are a real double root and two complex conjugate roots.
	*	If ∆0 = 0 and D ≠ 0, there are a triple root and a simple root, all real.
	*	If D = 0, then:
	*		If P < 0, there are two real double roots.
	*		If P > 0 and R = 0, there are two complex conjugate double roots.
	*		If ∆0 = 0, all four roots are equal to −b / 4.0
	* (Wikipedia, 2020)
	*/
	if (discriminant.real() < 0) {
		std::cout << "The equation has two distinct real roots and two complex conjugate non-real roots" << std::endl;
	}

	else if (discriminant.real() > 0) {
		if (P.real() < 0 && D.real() < 0)
			std::cout << "All four roots are real and distinct." << std::endl;
		else if (P.real() > 0 || D.real() > 0)
			std::cout << "The equation has two pairs of non-real complex conjugate roots." << std::endl;
		else
			return;
	}

	else {
		if (P.real() < 0 && D.real() < 0 && delta.real() != 0)
			std::cout << "The equation has a real double root and two real simple roots." << std::endl;
		else if (D.real() > 0 || (P.real() > 0 && (D.real() != 0 || R.real() != 0)))
			std::cout << "The equation has a real double root and two complex conjugate roots." << std::endl;
		else if (delta.real() == 0 && D.real() != 0)
			std::cout << "The equation has a triple root and a simple root, all real." << std::endl;
		else if (D.real() == 0) {
			if (P.real() < 0)
				std::cout << "The equation has two real double roots." << std::endl;
			else if (P.real() > 0 && R.real() == 0)
				std::cout << "The equation has two complex conjugate double roots." << std::endl;
			else if (delta.real() == 0)
				std::cout << "All 4 roots are equal to " << -(b / 4.0 * a) << "." << std::endl;
			else
				return;
		}
		else
			return;
	}
	return;
}

#endif


/*References:
*	http://mathforum.org/dr.math/faq/faq.cubic.equations.html
*	https://keisan.casio.com/exec/system/1181809416
*	http://ky.matyc.org/The%20Quartic%20Formula%20%20(Euler).pdf
*	https://en.wikipedia.org/wiki/Quartic_function (Nature of roots)
*/