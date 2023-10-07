#ifndef FIXED_HPP
# define FIXED_HPP

#include <ostream>

class	Fixed
{
private:

	int					_raw;
	static const int	_bits = 8;

public:
	Fixed( void );
	Fixed( int num );
	Fixed( const float num );
	Fixed( Fixed const & src );
	~Fixed( void );


	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
	float	toFloat( void ) const;
	int		toInt( void ) const;

	Fixed &	operator=( Fixed const & rhs );

	bool	operator>( Fixed const & rhs );
	bool	operator<( Fixed const & rhs );
	bool	operator>=( Fixed const & rhs );
	bool	operator<=( Fixed const & rhs );
	bool	operator==( Fixed const & rhs );
	bool	operator!=( Fixed const & rhs );
};

std::ostream &	operator<<( std::ostream & o, Fixed const & i );

#endif
