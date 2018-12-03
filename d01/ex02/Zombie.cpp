/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupriia <akupriia@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 21:30:02 by akupriia          #+#    #+#             */
/*   Updated: 2018/10/03 21:12:50 by akupriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie( void )
{
	return ;
}

Zombie::Zombie( std::string name, std::string type ) : _name(name), _type(type)
{
	return ;
}

Zombie::~Zombie( void )
{
	return ;
}



void	Zombie::setName( std::string name )
{
	_name = name;
}

void	Zombie::setType( std::string type )
{
	_type = type;
}

void	Zombie::announce( void )
{
	std::cout << "<" << _name << " (" << _type << ")> Braiiiiiiinnnssss..." << std::endl;
}
