/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Peon.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupriia <akupriia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 21:26:39 by akupriia          #+#    #+#             */
/*   Updated: 2018/06/22 21:26:51 by akupriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Peon.hpp"
#include <iostream>

std::ostream & operator<<(std::ostream & o, Peon const & rhs)
{
	o << "I'm " << rhs.getName() << " and I like otters !" << std::endl;
	return o;
}

Peon::Peon( void ): Victim()
{
	return;
}

Peon::Peon( std::string name): Victim(name)
{
	std::cout << "Zog zog." << std::endl;
}

Peon::Peon( Peon const &copy)
{
	(*this) = copy;
	std::cout << "Zog zog." << std::endl;
}

Peon::~Peon( void )
{
	std::cout << "Bleuark..." << std::endl;
}

void		Peon::getPolymorphed( void ) const
{
	std::cout << this->_name << " has been turned into a pink pony !" << std::endl;
}

Peon		& Peon::operator=(Peon const & right)
{
	this->_name = right.getName();
	return *this;
}
