/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupriia <akupriia@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 22:16:44 by akupriia          #+#    #+#             */
/*   Updated: 2018/10/06 22:16:44 by akupriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include <iostream>

Cure::Cure(void): AMateria("cure") {}

Cure::Cure(std::string const & type): AMateria("cure")
{
	(void)type;
}

Cure::Cure(Cure const & cpy): AMateria(cpy) {}

Cure::~Cure() {}

Cure*	Cure::clone(void) const
{
	Cure *	newcure = new Cure("cure");

	return (newcure);
}

void		Cure::use(ICharacter& target)
{
	setXP();
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}