#include <iostream>
#include "Fixed.hpp"

int main( void )
{
	Fixed a, c;
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

	c = ( 0.5f );
	std::cout << b / c << std::endl;
	std::cout << "b es: " << b << std::endl;
	std::cout << "c es: " << c << std::endl;
	Fixed d(b - c);
	std::cout << " b - c es: " << d << std::endl;
	d = (b + c);
	std::cout << " b + c es: " << d << std::endl;
	if (d == c)
		std::cout << "d and c equal." << std::endl;

	std::cout << Fixed::max( a, b ) << std::endl;
	std::cout << Fixed::min( a, b ) << std::endl;

	return 0;
}
