/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupriia <akupriia@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 22:16:50 by akupriia          #+#    #+#             */
/*   Updated: 2018/10/06 22:16:51 by akupriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>

class Cure: public AMateria
{

public:
	Cure(void);
	Cure(std::string const & type);
	Cure(Cure const &);
	~Cure();
	using AMateria::operator=;

	Cure*		clone(void) const;
	void		use(ICharacter& target);
};

#endif
