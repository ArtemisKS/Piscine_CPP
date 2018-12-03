/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupriia <akupriia@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 21:32:56 by akupriia          #+#    #+#             */
/*   Updated: 2018/10/02 21:32:57 by akupriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB( std::string name ) : _name(name)
{
	return ;
}

HumanB::~HumanB( void )
{
	return ;
}


void				HumanB::attack( void ) const
{
	std::cout << _name << " attacks with his " << _weapon->getType() << std::endl;
}

void				HumanB::setWeapon( Weapon& someWeapon )
{
	_weapon = &someWeapon;
}
