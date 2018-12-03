/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupriia <akupriia@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 22:17:47 by akupriia          #+#    #+#             */
/*   Updated: 2018/10/06 22:19:24 by akupriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"
#include "AMateria.hpp"
#include <iostream>

class MateriaSource : public IMateriaSource
{
private:
	AMateria**		_tabm;

public:
	
	MateriaSource(void);
	MateriaSource(MateriaSource const & cpy);
	~MateriaSource() {}
	MateriaSource & operator=(MateriaSource const & rhs);

	void 		learnMateria(AMateria*);
	AMateria* 	createMateria(std::string const & type);
};

#endif
