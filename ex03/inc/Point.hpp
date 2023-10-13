#ifndef POINT_H
# define POINT_H

# include "Fixed.hpp"

class	Point
{
public:
	Point( void );
	Point( float const x, float const y );
	Point( Point const & p );
	~Point( void );

	std::pair<Fixed, Fixed>	getValue( void ) const;

	Point & 			operator=( Point const & p );

private:
	Fixed const	_x;
	Fixed const	_y;

};

std::ostream &	operator<<(std::ostream & o, Point const & p);

#endif
