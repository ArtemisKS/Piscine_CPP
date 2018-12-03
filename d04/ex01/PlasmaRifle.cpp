/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PlasmaRifle.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupriia <akupriia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 22:08:03 by akupriia          #+#    #+#             */
/*   Updated: 2018/06/22 22:08:12 by akupriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PlasmaRifle.hpp"
#include <iostream>

PlasmaRifle::~PlasmaRifle( void ) {}

PlasmaRifle::PlasmaRifle( void )
{
	this->_name = "Plasma Rifle";
	this->_damage = 21;
	this->_apcost = 5;
}

PlasmaRifle::PlasmaRifle( PlasmaRifle const & weapon )
{
	*this = weapon;
}

PlasmaRifle&	PlasmaRifle::operator=( PlasmaRifle const & weapon )
{
	this->_name = weapon.getName();
	this->_damage = weapon.getDamage();
	this->_apcost = weapon.getAPCost();
	return *this;
}

void		PlasmaRifle::attack( void ) const
{
	std::cout << "* piouuu piouuu piouuu *" << std::endl;
}
