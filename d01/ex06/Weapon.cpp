/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupriia <akupriia@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 21:33:11 by akupriia          #+#    #+#             */
/*   Updated: 2018/10/02 21:33:12 by akupriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon( std::string type_ ) : type(type_)
{
	return ;
}

Weapon::~Weapon( void )
{
	return ;
}


const std::string&		Weapon::getType( void ) const
{
	return type;
}

void					Weapon::setType( std::string type_ )
{
	type = type_;
}
