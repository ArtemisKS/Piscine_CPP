// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Fixed.class.hpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: akupriia <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/06/21 20:30:23 by akupriia          #+#    #+#             //
//   Updated: 2018/06/21 20:30:24 by akupriia         ###   ########.fr       //
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
	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
};

std::ostream & operator<<(std::ostream & o, Fixed const & rhs);

#endif