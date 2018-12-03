/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Victim.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupriia <akupriia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 21:29:00 by akupriia          #+#    #+#             */
/*   Updated: 2018/06/22 21:29:02 by akupriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Victim.hpp"
#include <iostream>

std::ostream & operator<<(std::ostream & o, Victim const & rhs)
{
	o << "I'm " << rhs.getName() << " and I like otters !" << std::endl;
	return o;
}

Victim::Victim( void )
{
	this->_name = "Unknown";
}

Victim::Victim( std::string name ): _name(name)
{
	std::cout << "Some random victim called " << this->_name << " just popped !" << std::endl;
}

Victim::Victim( Victim const &copy)
{
	(*this) = copy;
	std::cout << "Some random victim called " << this->_name << " just popped !" << std::endl;
}

Victim::~Victim( void )
{
	std::cout << "Victim " << this->_name << " just died for no apparent reason !" << std::endl;
}

std::string	Victim::getName( void ) const { return this->_name; }

void		Victim::introduce( void )
{
	std::cout << *this;
}

void		Victim::getPolymorphed( void ) const
{
	std::cout << this->_name << " has been turned into a cute little sheep !" << std::endl;
}

Victim			& Victim::operator=(Victim const & right)
{
	this->_name = right.getName();
	return *this;
}
