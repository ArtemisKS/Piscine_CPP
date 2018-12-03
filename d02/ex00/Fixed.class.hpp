// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Fixed.class.hpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: akupriia <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/06/21 20:22:03 by akupriia          #+#    #+#             //
//   Updated: 2018/06/21 20:22:04 by akupriia         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef FIXED_CLASS_HPP
# define FIXED_CLASS_HPP

class Fixed
{
	int					_value;
	static const int	_bits;
public:
	Fixed( void );
	Fixed( Fixed const &number );
	~Fixed( void );
	Fixed	&operator=( Fixed const &number );
	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
};

#endif
