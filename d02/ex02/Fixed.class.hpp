// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Fixed.class.hpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: akupriia <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/06/21 20:32:58 by akupriia          #+#    #+#             //
//   Updated: 2018/06/21 20:32:58 by akupriia         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef FIXED_CLASS_HPP
# define FIXED_CLASS_HPP

# include <iostream>

class Fixed
{
	int					_value;
	static const int	_bits;
public:
	Fixed( void );
	Fixed( Fixed const &number );
	Fixed( int const number );
	Fixed( float const number );
	float	toFloat( void ) const;
	int		toInt( void ) const;
	~Fixed( void );

	Fixed	&operator=( Fixed const &number );
	bool	operator<( Fixed const &number ) const;
	bool	operator>( Fixed const &number ) const;
	bool	operator>=( Fixed const &number ) const;
	bool	operator<=( Fixed const &number ) const;
	bool	operator==( Fixed const &number ) const;
	bool	operator!=( Fixed const &number ) const;
	Fixed	operator+( Fixed const &number ) const;
	Fixed	operator-( Fixed const &number ) const;
	Fixed	operator*( Fixed const &number ) const;
	Fixed	operator/( Fixed const &number ) const;
	Fixed	&operator++( void );
	Fixed	operator++( int );
	Fixed	&operator--( void );
	Fixed	operator--( int );

	static Fixed &min(Fixed & a, Fixed & b);
	static Fixed const 	& min(Fixed const & a, Fixed const & b);
	static Fixed &max(Fixed & a, Fixed & b);
	static Fixed const 	& max(Fixed const & a, Fixed const & b);


	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
};

std::ostream & operator<<(std::ostream & o, Fixed const & rhs);

#endif