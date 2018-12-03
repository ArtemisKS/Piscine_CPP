/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Squad.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupriia <akupriia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 16:42:11 by akupriia          #+#    #+#             */
/*   Updated: 2018/06/23 16:42:13 by akupriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SQUAD_HPP
# define SQUAD_HPP

#include "ISpaceMarine.hpp"
#include "ISquad.hpp"

class Squad : public ISquad
{
public:
	virtual ~Squad( void );
	Squad( void );
	Squad( ISquad const & squad );
	ISquad & operator=( ISquad const & squad );
	virtual int getCount( void ) const;
	virtual ISpaceMarine* getUnit( int ) const;
	virtual int push( ISpaceMarine* );
private:
	ISpaceMarine	*_pool[50];
	int				_unitCount;
};

#endif
