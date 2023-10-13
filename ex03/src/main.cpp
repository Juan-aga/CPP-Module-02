#include <iostream>
//#include "Fixed.hpp"
#include "Point.hpp"

int main( void )
{
/*	Fixed a, c;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << --a << std::endl;
	std::cout << a << std::endl;
	std::cout << a-- << std::endl;
	std::cout << a << std::endl;


	std::cout << b << std::endl;
	std::cout << b / c << std::endl;
	Fixed d (b - b);
	if (d == c)
		std::cout << "d and c equal." << std::endl;

	std::cout << Fixed::max( a, b ) << std::endl;
	std::cout << Fixed::min( a, b ) << std::endl;

	return 0;
*/

	Point  a;
	Point b(3.4f, 0.5f);
	Point const c = b;

	std::cout << "a es: " << a << std::endl;
	std::cout << "b es: " << b << std::endl;
	std::cout << "c es: " << c << std::endl;

	a = c;
	std::cout << "a = c es: " << a << std::endl;
	c = b;
}
