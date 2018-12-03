/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupriia <akupriia@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 21:34:16 by akupriia          #+#    #+#             */
/*   Updated: 2018/10/02 21:34:16 by akupriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"

Human::Human( void )
{
	return ;
}

Human::~Human( void )
{
	return ;
}



void			Human::meleeAttack(std::string const & target)
{
	std::cout << "Human hits " << target << " by melee attack" << std::endl;
}

void			Human::rangedAttack(std::string const & target)
{
	std::cout << "Human hits " << target << " by ranged attack" << std::endl;
}

void			Human::intimidatingShout(std::string const & target)
{
	std::cout << "Human hits " << target << " by intimidating shout" << std::endl;
}



void			Human::action(std::string const & action_name, std::string const & target)
{
	void			(Human::*p[3])(std::string const &) = {
		&Human::meleeAttack,
		&Human::rangedAttack,
		&Human::intimidatingShout
	};
	std::string		s[3] = {
		"meleeAttack",
		"rangedAttack",
		"intimidatingShout"
	};

	for ( int i = 0; i < 3; i++ ) {
		if ( s[i] == action_name ) {
			(this->*p[i])(target);
			break ;
		}
	}
}
