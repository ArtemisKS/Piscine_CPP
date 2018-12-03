/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Peon.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupriia <akupriia@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 21:27:30 by akupriia          #+#    #+#             */
/*   Updated: 2018/10/06 23:16:05 by akupriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PEON_HPP
# define PEON_HPP

#include <string>
#include "Victim.hpp"

class Peon : public Victim
{
private:
	Peon( void );

public:
	Peon( std::string name );
	Peon( Peon const &copy);
	virtual ~Peon( void );

	Peon		& operator=(Peon const & right);

	void		getPolymorphed( void ) const;

};

std::ostream & operator<<(std::ostream & o, Peon const & rhs);

#endif
