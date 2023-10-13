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
		std::pair<Fixed, Fixed> values = p.getValue();
//		const_cast<Fixed&>(this->_x) = Fixed(values.first.toFloat());
		const_cast<Fixed&>(this->_x) = values.first;
		const_cast<Fixed&>(this->_y) = values.second;

//		this->_x = p._x;
//		*this->_x.setRawBits(values.first.getRawBits());
//		this->_y = values.second;
	}
	return *this;
}

std::ostream &	operator<<(std::ostream & o, Point const & p)
{
	std::pair<Fixed, Fixed>	value = p.getValue();

	o << "X: " << value.first.toFloat() << " Y: " << value.second.toFloat();

	return o;
}
