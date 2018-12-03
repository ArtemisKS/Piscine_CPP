/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupriia <akupriia@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 22:16:58 by akupriia          #+#    #+#             */
/*   Updated: 2018/10/06 22:16:59 by akupriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include <iostream>

Ice::Ice(void): AMateria("ice") {}

Ice::Ice(std::string const & type): AMateria("ice")
{
	(void)type;
}

Ice::Ice(Ice const & cpy): AMateria(cpy) {}

Ice::~Ice() {}

Ice*	Ice::clone(void) const
{
	Ice *	newice = new Ice("ice");

	return (newice);
}

void		Ice::use(ICharacter& target)
{
	setXP();
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}