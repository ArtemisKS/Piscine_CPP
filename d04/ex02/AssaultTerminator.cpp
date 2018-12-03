/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AssaultTerminator.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupriia <akupriia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 16:39:21 by akupriia          #+#    #+#             */
/*   Updated: 2018/06/23 16:39:31 by akupriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AssaultTerminator.hpp"
#include <iostream>

AssaultTerminator::~AssaultTerminator( void )
{
	std::cout << "I'll be back ..." << std::endl;
}

AssaultTerminator::AssaultTerminator( void )
{
	std::cout << "* teleports from space *" << std::endl;
}

AssaultTerminator::AssaultTerminator( AssaultTerminator const & marine )
{
	*this = marine;
	std::cout << "* teleports from space *" << std::endl;
}

AssaultTerminator & AssaultTerminator::operator=( AssaultTerminator const & marine )
{
	this->_hp = marine.getHP();
	return *this;
}

void	AssaultTerminator::battleCry( void ) const
{
	std::cout << "This code is unclean. PURIFY IT !" << std::endl;
}
void	AssaultTerminator::rangedAttack( void ) const
{
	std::cout <<"* does nothing *" << std::endl;
}

void	AssaultTerminator::meleeAttack( void ) const
{
	std::cout << "* attacks with chainfists *" << std::endl;
}

int		AssaultTerminator::getHP( void ) const
{
	return this->_hp;
}

ISpaceMarine* AssaultTerminator::clone( void ) const
{
	return new AssaultTerminator(*this);
}
