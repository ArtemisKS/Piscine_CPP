/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupriia <akupriia@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 21:32:45 by akupriia          #+#    #+#             */
/*   Updated: 2018/10/02 21:32:46 by akupriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA( std::string name, const Weapon& type ) : _name(name), _weapon(type)
{
	return ;
}

HumanA::~HumanA( void )
{
	return ;
}



void				HumanA::attack( void ) const
{
	std::cout << _name << " attacks with his " << _weapon.getType() << std::endl;
}
