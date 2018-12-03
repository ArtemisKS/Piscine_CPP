/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TacticalMarine.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupriia <akupriia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 16:43:33 by akupriia          #+#    #+#             */
/*   Updated: 2018/06/23 16:43:35 by akupriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TACTICALMARINE_HPP
# define TACTICALMARINE_HPP

#include "ISpaceMarine.hpp"
#include "ISquad.hpp"
#include "Squad.hpp"

class TacticalMarine  : public ISpaceMarine
{
public:
	virtual ~TacticalMarine( void );
	TacticalMarine( void );
	TacticalMarine( TacticalMarine const & marine );
	TacticalMarine & operator=( TacticalMarine const & marine );
	virtual ISpaceMarine* clone( void ) const;
	virtual void battleCry( void ) const;
	virtual void rangedAttack( void ) const;
	virtual void meleeAttack( void ) const;
	int			getHP( void ) const;
private:
	int			_hp;
};

#endif
