/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupriia <akupriia@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 22:16:25 by akupriia          #+#    #+#             */
/*   Updated: 2018/10/06 22:16:26 by akupriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include <iostream>

AMateria::AMateria(void): type_(""), xp_(0) {
}

AMateria::AMateria(std::string const & type): type_(type), xp_(0) {	
}

AMateria::AMateria(AMateria const & cpy)
{
	*this = cpy;
}

AMateria::~AMateria() {}

AMateria &	AMateria::operator=(AMateria const & rhs)
{
	xp_ = rhs.getXP();
	return (*this);
}

std::string const &	AMateria::getType() const
{
	return (type_);
}

unsigned int		AMateria::getXP() const
{
	return (xp_);
}

void				AMateria::setXP()
{
	xp_ += 10;
}

void		AMateria::use(ICharacter& target)
{
	(void)target;
}