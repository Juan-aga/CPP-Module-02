#include "Point.hpp"

Point::Point( void ) : _x(Fixed()), _y(Fixed())
{
}

Point::Point( float const x, float const y ) : _x(Fixed(x)), _y(Fixed(y))
{
}

Point::Point( Point const & p)
{
	*this = p;
}

Point::Point( Fixed const x, Fixed const y ) : _x(x), _y(y)
{
}

Point::~Point( void )
{
}

std::pair<Fixed, Fixed>	Point::getValue( void ) const
{
	return std::make_pair(Fixed(this->_x), Fixed(this->_y));
}

Point & 			Point::operator=( Point const & p )
{
	if (this != &p)
	{
		const_cast<Fixed&>(this->_x) = p._x;
		const_cast<Fixed&>(this->_y) = p._y;
	}
	return *this;
}

Point				Point::operator-( Point const & p ) const
{
	return Point( (this->_x - p._x), (this->_y - p._y) );
}

std::ostream &	operator<<(std::ostream & o, Point const & p)
{
	std::pair<Fixed, Fixed>	value = p.getValue();

	o << "X: " << value.first.toFloat() << " Y: " << value.second.toFloat();

	return o;
}
