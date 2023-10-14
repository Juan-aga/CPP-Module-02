#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point);

int main( void )
{
	Point a(-5.0f, -2.0f);
	Point b(2.0f, 6.0f);
	Point c(3.0f, -3.0f);

	Point point(1.0f, 1.0f);

	std::cout << "Dentro: ";
	std::cout << bsp(a, b, c, point) << std::endl;

	point = Point(-5.0f, -2.0f);
	std::cout << "Vertice: ";
	std::cout << bsp(a, b, c, point) << std::endl;

	point = Point(-6.0f, -2.0f);
	std::cout << "fuera: ";
	std::cout << bsp(a, b, c, point) << std::endl;

	return 0;
}
