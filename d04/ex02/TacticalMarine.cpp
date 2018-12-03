/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TacticalMarine.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupriia <akupriia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 16:43:00 by akupriia          #+#    #+#             */
/*   Updated: 2018/06/23 16:43:02 by akupriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TacticalMarine.hpp"
#include <iostream>

TacticalMarine::~TacticalMarine( void )
{
	std::cout << "Aaargh ..." << std::endl;
}

TacticalMarine::TacticalMarine( void )
{
	std::cout << "Tactical Marine ready for battle" << std::endl;
}

TacticalMarine::TacticalMarine( TacticalMarine const & marine )
{
	*this = marine;
	std::cout << "Tactical Marine ready for battle" << std::endl;
}

TacticalMarine&TacticalMarine::operator=( TacticalMarine const & marine )
{
	this->_hp = marine.getHP();
	return *this;
}

void	TacticalMarine::battleCry( void ) const
{
	std::cout << "For the holy PLOT !" << std::endl;
}
void	TacticalMarine::rangedAttack( void ) const
{
	std::cout << "* attacks with bolter *" << std::endl;
}

void	TacticalMarine::meleeAttack( void ) const
{
	std::cout << "* attacks with chainsword *" << std::endl;
}

int		TacticalMarine::getHP( void ) const
{
	return this->_hp;
}

ISpaceMarine* TacticalMarine::clone( void ) const
{
	return new TacticalMarine(*this);
}
