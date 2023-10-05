#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed( void ) : _raw(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( Fixed const & src )
{
	std::cout << "Copy constructor called" << std::endl;

	*this = src;

	return ;
}

Fixed::~Fixed( void )
{
	std::cout << "Destructor called" << std::endl;
}

Fixed &	Fixed::operator=( Fixed const & rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;

	if ( this != &rhs )
		this->_raw = rhs.getRawBits();

	return *this;
}

int		Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;

	return this->_raw;
}

void	Fixed::setRawBits( int const raw )
{
	std::cout << "setRawBits member function called" << std::endl;

	this->_raw = raw;
}
