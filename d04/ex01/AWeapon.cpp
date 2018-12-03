/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWeapon.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupriia <akupriia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 22:05:20 by akupriia          #+#    #+#             */
/*   Updated: 2018/06/22 22:05:29 by akupriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AWeapon.hpp"

AWeapon::AWeapon( void ) {}
AWeapon::~AWeapon( void ) {}

AWeapon::AWeapon( std::string const & name, int apcost, int damage ): _name(name), _apcost(apcost), _damage(damage)
{
	return;
}

AWeapon::AWeapon( AWeapon const & weapon )
{
	*this = weapon;
}

std::string		AWeapon::getName( void ) const { return this->_name; }
int				AWeapon::getAPCost( void ) const { return this->_apcost; }
int				AWeapon::getDamage( void ) const { return this->_damage; }

AWeapon		& AWeapon::operator=( AWeapon const & right )
{
	this->_name = right.getName();
	this->_apcost = right.getAPCost();
	this->_damage = right.getDamage();
	return *this;
}
