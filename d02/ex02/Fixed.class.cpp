// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Fixed.class.cpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: akupriia <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/06/21 20:32:51 by akupriia          #+#    #+#             //
//   Updated: 2018/06/21 20:32:52 by akupriia         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Fixed.class.hpp"
#include <iostream>
#include <cmath>

const int	Fixed::_bits = 8;

Fixed::Fixed( void ): _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( Fixed const &number )
{
	std::cout << "Copy constructor called" << std::endl;
	*this = number;
}

Fixed::Fixed( int const number ): _value(number << Fixed::_bits)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed( float const number ): _value(roundf(number * (1 << Fixed::_bits)))
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed( void )
{
	std::cout << "Destructor called" << std::endl;
}

Fixed	&Fixed::operator=( Fixed const &number )
{
	std::cout << "Assignation operator called" << std::endl;
	this->_value = number.getRawBits();
	return *this;
}

int		Fixed::getRawBits( void ) const
{
	return this->_value;
}

void	Fixed::setRawBits( int const raw )
{
	this->_value = raw;
}

float	Fixed::toFloat( void ) const
{
	return this->_value / (float)(1 << Fixed::_bits);
}

int		Fixed::toInt( void ) const
{
	return this->_value / (1 << Fixed::_bits);
}

std::ostream & operator<<(std::ostream & o, Fixed const & rhs)
{
	o << rhs.toFloat();
	return o;
}

bool	Fixed::operator<( Fixed const &number ) const
{
	return (this->_value < number.getRawBits());
}

bool	Fixed::operator>( Fixed const &number ) const
{
	return (this->_value > number.getRawBits());
}

bool	Fixed::operator>=( Fixed const &number ) const
{
	return (this->_value >= number.getRawBits());
}

bool	Fixed::operator<=( Fixed const &number ) const
{
	return (this->_value <= number.getRawBits());
}

bool	Fixed::operator==( Fixed const &number ) const
{
	return (this->_value == number.getRawBits());
}

bool	Fixed::operator!=( Fixed const &number ) const
{
	return (this->_value != number.getRawBits());
}

Fixed	Fixed::operator+( Fixed const &number ) const
{
	return (Fixed(this->toFloat() + number.toFloat()));
}

Fixed	Fixed::operator-( Fixed const &number ) const
{
	return (Fixed(this->toFloat() - number.toFloat()));
}

Fixed	Fixed::operator*( Fixed const &number ) const
{
	return (Fixed(this->toFloat() * number.toFloat()));
}

Fixed	Fixed::operator/( Fixed const &number ) const
{
	return (Fixed(this->toFloat() / number.toFloat()));
}

Fixed	&Fixed::operator++( void )
{
	this->_value++;
	return (*this);
}

Fixed	Fixed::operator++( int )
{
	Fixed tmp(*this);
	++(*this);
	return tmp;
}

Fixed	&Fixed::operator--( void )
{
	this->_value--;
	return (*this);
}

Fixed	Fixed::operator--( int )
{
	Fixed tmp(*this);
	--(*this);
	return tmp;
}

Fixed &Fixed::min(Fixed & a, Fixed & b)
{
	return (a < b) ? a : b;
}

Fixed const 	&Fixed::min(Fixed const & a, Fixed const & b)
{
	return (a < b) ? a : b;
}

Fixed &Fixed::max(Fixed & a, Fixed & b)
{
	return (a > b) ? a : b;
}

Fixed const 	&Fixed::max(Fixed const & a, Fixed const & b)
{
	return (a > b) ? a : b;
}