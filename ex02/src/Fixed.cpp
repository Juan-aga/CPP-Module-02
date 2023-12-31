#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed( void ) : _raw( 0 << _bits)
{
	if (DEBUG)
		std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( int num) : _raw( num << _bits)
{
	if (DEBUG)
		std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed( const float num ) : _raw( roundf(num * (1 << _bits)) )
{
	if (DEBUG)
		std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed( Fixed const & src )
{
	if (DEBUG)
		std::cout << "Copy constructor called" << std::endl;

	*this = src;

	return ;
}

Fixed::~Fixed( void )
{
	if (DEBUG)
		std::cout << "Destructor called" << std::endl;
}

int		Fixed::getRawBits( void ) const
{
	if (DEBUG)
		std::cout << "getRawBits member function called" << std::endl;

	return this->_raw;
}

void	Fixed::setRawBits( int const raw )
{
	if (DEBUG)
		std::cout << "setRawBits member function called" << std::endl;

	this->_raw = raw;
}

float	Fixed::toFloat( void ) const
{
	float	result;

	if (DEBUG)
		std::cerr << "toFloat member function called" << std::endl;
	result = _raw / (float)(1 << _bits);
	
	return result;
}

int		Fixed::toInt( void ) const
{
	if (DEBUG)
		std::cerr << "toInt member function called" << std::endl;

	return _raw >> _bits;
}

Fixed &	Fixed::min( Fixed & f1, Fixed & f2 )
{
	if (f2 >= f1)
		return f1;
	return f2;
}

const Fixed &	Fixed::min( Fixed const & f1, Fixed const & f2 )
{
	if (f2 >= f1)
		return f1;
	return f2;
}

Fixed &	Fixed::max( Fixed & f1, Fixed & f2 )
{
	if (f1 >= f2)
		return f1;
	return f2;
}

const Fixed &	Fixed::max( Fixed const & f1, Fixed const & f2 )
{
	if (f1 >= f2)
		return f1;
	return f2;
}

Fixed &	Fixed::operator=( Fixed const & rhs)
{
	if (DEBUG)
		std::cout << "Copy assignment operator called" << std::endl;

	if ( this != &rhs )
		this->_raw = rhs.getRawBits();

	return *this;
}

Fixed	Fixed::operator+( Fixed const & rhs) const
{
	return Fixed(this->toFloat() + rhs.toFloat());
}

Fixed	Fixed::operator-( Fixed const & rhs) const
{
	return Fixed(this->toFloat() - rhs.toFloat());
}

Fixed	Fixed::operator*( Fixed const & rhs) const
{
	return Fixed(this->toFloat() * rhs.toFloat());
}

Fixed	Fixed::operator/( Fixed const & rhs) const
{
	if (rhs._raw == 0)
	{
		std::cerr << "Error: Zero division." << std::endl;
		return 0;
	}
	return Fixed(this->toFloat() / rhs.toFloat());
}

Fixed	Fixed::operator++( void )
{
	this->_raw++;
	return *this;
}

Fixed	Fixed::operator++( int )
{
	Fixed	tmp(*this);

	this->_raw++;
	return tmp;
}

Fixed	Fixed::operator--( void )
{
	this->_raw--;
	return *this;
}

Fixed	Fixed::operator--( int )
{
	Fixed	tmp(*this);

	this->_raw--;
	return tmp;
}

bool	Fixed::operator>( Fixed const & rhs ) const
{
	return (this->getRawBits() > rhs.getRawBits());
}

bool	Fixed::operator<( Fixed const & rhs ) const
{
	return (this->getRawBits() < rhs.getRawBits());
}

bool	Fixed::operator>=( Fixed const & rhs ) const
{
	return (this->getRawBits() >= rhs.getRawBits());
}

bool	Fixed::operator<=( Fixed const & rhs ) const
{
	return (this->getRawBits() <= rhs.getRawBits());
}

bool	Fixed::operator==( Fixed const & rhs ) const
{
	return (this->getRawBits() == rhs.getRawBits());
}

bool	Fixed::operator!=( Fixed const & rhs ) const
{
	return (this->getRawBits() != rhs.getRawBits());
}

std::ostream &	operator<<( std::ostream & o, Fixed const & i )
{
	if (DEBUG)
		std::cerr << std::endl << "operator << called" << std::endl;

	o << i.toFloat();

	return o;
}
