/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Squad.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupriia <akupriia@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 22:37:07 by akupriia          #+#    #+#             */
/*   Updated: 2018/10/06 22:37:08 by akupriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Squad.hpp"
#include <iostream>

Squad::Squad( void ): _unitCount(0)
{
	return;
}

Squad::~Squad( void )
{
	for (int i = 0 ; i < this->_unitCount; i++)
		delete _pool[i];
}

Squad::Squad( ISquad const & squad )
{
	this->_unitCount = squad.getCount();
	for (int i = 0 ; i < this->_unitCount; i++)
		_pool[i] = squad.getUnit(i)->clone();
}

ISquad&	Squad::operator=( ISquad const & squad )
{
	for (int i = 0 ; i < this->_unitCount; i++)
		delete _pool[i];
	this->_unitCount = squad.getCount();
	for (int i = 0 ; i < this->_unitCount; i++)
		_pool[i] = squad.getUnit(i)->clone();
	return *this;
}

int		Squad::getCount( void ) const { return this->_unitCount; }

ISpaceMarine*	Squad::getUnit( int i ) const
{
	if (i >= 0 && i < this->_unitCount)
		return this->_pool[i];
	return NULL;
}

int		Squad::push( ISpaceMarine* marine )
{
	if (this->_unitCount < 50)
	{
		this->_pool[_unitCount] = marine;
		this->_unitCount++;
		return 0;
	}
	else
		return 1;
}
