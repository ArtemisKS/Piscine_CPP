/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupriia <akupriia@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 22:16:05 by akupriia          #+#    #+#             */
/*   Updated: 2018/10/06 22:16:36 by akupriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include <iostream>

Character::Character(void): _name("")
{
	_tab = new AMateria*[4];
}

Character::Character(std::string name): _name(name)
{
	_tab = new AMateria*[4];

	for (int i = 0; i < 4; ++i)
	{
		_tab[i] = NULL;
	}
}

Character::Character(Character const & cpy)
{
	*this = cpy;
}

Character::~Character()
{
	delete [] _tab;
}

Character &	Character::operator=(Character const & rhs)
{
	_name = rhs._name;
	_tab = rhs._tab;
	return (*this);
}


std::string const & Character::getName() const
{
	return (_name);
}

void 				Character::equip(AMateria* m)
{
	int	check;

	check = 0;
	for (int i = 0; i < 4; ++i)
	{
		if (check == 0 && _tab[i] == NULL)
		{
			_tab[i] = m;
			check++;
		}
	}
	if (check == 0)
		std::cout << "inventory full." << std::endl;
}

void 				Character::unequip(int idx)
{
	if (_tab[idx] == NULL)
		std::cout << "inventory empty." << std::endl;
	else
		_tab[idx] = NULL;
}

void 				Character::use(int idx, ICharacter& target)
{
	if (_tab[idx] == NULL || idx > 3 || idx < 0)
		std::cout << "no materia in this slot." << std::endl;
	else
		{
			_tab[idx]->use(target);
			_tab[idx] = NULL;
		}
}
