/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AssaultTerminator.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupriia <akupriia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 16:39:50 by akupriia          #+#    #+#             */
/*   Updated: 2018/06/23 16:39:52 by akupriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASSAULTTERMINATOR_HPP
# define ASSAULTTERMINATOR_HPP

# include "ISpaceMarine.hpp"

class AssaultTerminator: public ISpaceMarine
{
public:
	virtual ~AssaultTerminator( void );
	AssaultTerminator( void );
	AssaultTerminator( AssaultTerminator const & marine );
	AssaultTerminator & operator=( AssaultTerminator const & marine );
	virtual ISpaceMarine *clone( void ) const;
	virtual void battleCry( void ) const;
	virtual void rangedAttack( void ) const;
	virtual void meleeAttack( void ) const;
	int			getHP( void ) const;
private:
	int			_hp;
};

#endif
