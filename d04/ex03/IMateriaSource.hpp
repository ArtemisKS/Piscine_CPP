/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupriia <akupriia@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 22:18:48 by akupriia          #+#    #+#             */
/*   Updated: 2018/10/06 22:18:51 by akupriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIASOURCE_HPP
# define IMATERIASOURCE_HPP

#include "AMateria.hpp"
#include <iostream>

class IMateriaSource
{
	
public:
	virtual ~IMateriaSource() {}
	virtual void 		learnMateria(AMateria*) = 0;
	virtual AMateria* 	createMateria(std::string const & type) = 0;
};

#endif
