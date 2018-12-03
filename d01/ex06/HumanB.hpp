/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupriia <akupriia@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 21:33:01 by akupriia          #+#    #+#             */
/*   Updated: 2018/10/02 21:33:02 by akupriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HumanB_hpp
#define HumanB_hpp

#include "Weapon.hpp"
#include <iostream>

class HumanB {

public:
	HumanB( std::string name );
	~HumanB( void );

	void				attack( void ) const;
	void				setWeapon( Weapon& someWeapon );

private:
	const std::string	_name;
	Weapon*				_weapon;

};

#endif
