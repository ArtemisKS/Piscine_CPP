/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupriia <akupriia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 22:06:13 by akupriia          #+#    #+#             */
/*   Updated: 2018/06/22 22:06:24 by akupriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include <iostream>

Character::Character( void ) : _name("Human"), _ap(40), _weapon(NULL)
{
	return;
}

Character::Character( std::string const & name ) : _name(name), _ap(40), _weapon(NULL)
{
	return;
}

Character::Character(Character const & character)
{
	*this = character;
}

Character::~Character( void ) {}

Character&		Character::operator=(Character const & character)
{
	this->_name = character.getName();
	this->_ap = character.getAP();
	this->_weapon = character.getWeapon();
	return *this;
}

void		Character::recoverAP()
{
	this->_ap += 10;
	if (this->_ap > 40)
		this->_ap = 40;
}

void		Character::equip(AWeapon *weapon)
{
	this->_weapon = weapon;
}

void		Character::attack(Enemy *enemy)
{
	if (this->_weapon && this->_ap >= this->_weapon->getAPCost())
	{
		this->_ap -= this->_weapon->getAPCost();
		std::cout << this->_name << " attacks " << enemy->getType() <<
					" with a " << this->_weapon->getName() << std::endl;
		this->_weapon->attack();
		enemy->takeDamage(this->_weapon->getDamage());
		if (enemy->getHP() == 0)
			delete enemy;
	}
}

std::string		Character::getName( void ) const { return this->_name; }
int				Character::getAP( void ) const { return this->_ap; }
AWeapon*		Character::getWeapon( void ) const { return this->_weapon; }

std::ostream&	operator<<( std::ostream&o, Character const & character )
{
	if (character.getWeapon())
		o << character.getName() << " has " << character.getAP()
		<< " AP and wields a " << character.getWeapon()->getName() << std::endl;
	else
		o << character.getName() << " has " << character.getAP()
		<< " AP and is unarmed" << std::endl;
	return o;
}
