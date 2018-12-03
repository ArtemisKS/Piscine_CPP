/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupriia <akupriia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 22:04:36 by akupriia          #+#    #+#             */
/*   Updated: 2018/06/22 22:04:46 by akupriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.hpp"

Enemy::Enemy( int hp, std::string const & type ) : _hp(hp), _type(type) {}
Enemy::Enemy( void ) : _hp(0), _type("Enemy") {}
Enemy::~Enemy( void ) {}

Enemy&	Enemy::operator=( Enemy const & enemy )
{
	this->_hp = enemy.getHP();
	this->_type = enemy.getType();
	return *this;
}

Enemy::Enemy( Enemy const & enemy )
{
	*this = enemy;
}

std::string		Enemy::getType( void ) const { return this->_type; }
int				Enemy::getHP( void ) const { return this->_hp; }

void			Enemy::takeDamage( int damage )
{
	if (damage >= 0)
	{
		if (this->_hp <= damage)
			this->_hp = 0;
		else
			this->_hp -= damage;
	}
}