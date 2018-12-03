/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PowerFist.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupriia <akupriia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 22:08:48 by akupriia          #+#    #+#             */
/*   Updated: 2018/06/22 22:08:51 by akupriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PowerFist.hpp"
#include <iostream>

PowerFist::~PowerFist( void ) {}

PowerFist::PowerFist( void )
{
	this->_name = "Power Fist";
	this->_damage = 50;
	this->_apcost = 8;
}

PowerFist::PowerFist( PowerFist const & weapon )
{
	*this = weapon;
}

PowerFist&	PowerFist::operator=( PowerFist const & weapon )
{
	this->_name = weapon.getName();
	this->_damage = weapon.getDamage();
	this->_apcost = weapon.getAPCost();
	return *this;
}

void		PowerFist::attack( void ) const
{
	std::cout << "* pschhh... SBAM! *" << std::endl;
}
