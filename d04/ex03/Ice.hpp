/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupriia <akupriia@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 22:17:10 by akupriia          #+#    #+#             */
/*   Updated: 2018/10/06 22:17:11 by akupriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>

class Ice: public AMateria
{

public:
	Ice(void);
	Ice(std::string const & type);
	Ice(Ice const &);
	~Ice();
	using AMateria::operator=;

	Ice*		clone(void) const;
	void		use(ICharacter& target);
};

#endif
