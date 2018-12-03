/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupriia <akupriia@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 22:16:30 by akupriia          #+#    #+#             */
/*   Updated: 2018/10/06 22:16:31 by akupriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include "ICharacter.hpp"
#include <iostream>

class AMateria
{
private:

	std::string		type_;
	unsigned int 	xp_;

public:

	AMateria(void);
	AMateria(std::string const & type);
	AMateria(AMateria const & cpy);
	virtual ~AMateria();
	AMateria &	operator=(AMateria const & rhs);

	std::string const &	getType() const;
	unsigned int		getXP() const;
	void				setXP();
	
	virtual AMateria*	clone() const = 0;
	virtual void		use(ICharacter& target);
};

#endif