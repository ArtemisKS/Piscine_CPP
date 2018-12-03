/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Classes.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupriia <akupriia@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 19:25:58 by akupriia          #+#    #+#             */
/*   Updated: 2018/10/09 19:26:00 by akupriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Classes.hpp>

Base::Base( void )
{
	return ;
}

Base::Base( const Base &toCopy )
{
	*this = toCopy;
}

Base::~Base( void )
{
	return ;
}

Base				&Base::operator=( const Base &toCopy )
{
	static_cast<void>(toCopy);

	return *this;
}



A::A( void )
{
	std::cout << "A was generated" << std::endl;
	return ;
}

A::A( const A &toCopy )
{
	*this = toCopy;
}

A::~A( void )
{
	return ;
}

A				&A::operator=( const A &toCopy )
{
	static_cast<void>(toCopy);

	return *this;
}



B::B( void )
{
	std::cout << "B was generated" << std::endl;
	return ;
}

B::B( const B &toCopy )
{
	*this = toCopy;
}

B::~B( void )
{
	return ;
}

B				&B::operator=( const B &toCopy )
{
	static_cast<void>(toCopy);

	return *this;
}



C::C( void )
{
	std::cout << "C was generated" << std::endl;
	return ;
}

C::C( const C &toCopy )
{
	*this = toCopy;
}

C::~C( void )
{
	return ;
}

C				&C::operator=( const C &toCopy )
{
	static_cast<void>(toCopy);

	return *this;
}
