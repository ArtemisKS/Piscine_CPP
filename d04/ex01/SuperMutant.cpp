/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperMutant.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupriia <akupriia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 22:10:06 by akupriia          #+#    #+#             */
/*   Updated: 2018/06/22 22:10:08 by akupriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SuperMutant.hpp"
#include <iostream>

SuperMutant::SuperMutant( void ) : Enemy::Enemy(170, "Super Mutant")
{
	std::cout << "Gaaah. Me want smash heads !" << std::endl;
}

SuperMutant::SuperMutant( SuperMutant const & enemy )
{
	*this = enemy;
	std::cout << "Gaaah. Me want smash heads !" << std::endl;
}

SuperMutant::~SuperMutant( void )
{
	std::cout << "Aaargh ..." << std::endl;
}

SuperMutant&	SuperMutant::operator=( SuperMutant const & enemy )
{
	this->_hp = enemy.getHP();
	this->_type = enemy.getType();
	return *this;
}

void			SuperMutant::takeDamage( int damage )
{
	Enemy::takeDamage(damage - 3);
}
