#ifndef FIXED_HPP
# define FIXED_HPP

#include <ostream>

class	Fixed
{
private:

	int						_raw;
	static const int		_bits = 8;

public:
	Fixed( void );
	Fixed( int num );
	Fixed( const float num );
	Fixed( Fixed const & src );
	~Fixed( void );


	int						getRawBits( void ) const;
	void					setRawBits( int const raw );
	float					toFloat( void ) const;
	int						toInt( void ) const;

	static Fixed &			min( Fixed & f1, Fixed & f2);
	static const Fixed &	min( Fixed const & f1, Fixed const & f2);
	static Fixed &			max( Fixed & f1, Fixed & f2);
	static const Fixed &	max( Fixed const & f1, Fixed const & f2);


	Fixed &					operator=( Fixed const & rhs );

	Fixed					operator+( Fixed const & rhs ) const;
	Fixed					operator-( Fixed const & rhs ) const;
	Fixed					operator*( Fixed const & rhs ) const;
	Fixed					operator/( Fixed const & rhs ) const;

	Fixed					operator++( void );
	Fixed					operator++( int );
	Fixed					operator--( void );
	Fixed					operator--( int );

	bool					operator>( Fixed const & rhs ) const;
	bool					operator<( Fixed const & rhs ) const;
	bool					operator>=( Fixed const & rhs ) const;
	bool					operator<=( Fixed const & rhs ) const;
	bool					operator==( Fixed const & rhs ) const;
	bool					operator!=( Fixed const & rhs ) const;
};

std::ostream &				operator<<( std::ostream & o, Fixed const & i );

#endif
