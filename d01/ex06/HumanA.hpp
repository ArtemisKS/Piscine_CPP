/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupriia <akupriia@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 21:32:50 by akupriia          #+#    #+#             */
/*   Updated: 2018/10/02 21:32:52 by akupriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HumanA_hpp
#define HumanA_hpp

#include "Weapon.hpp"
#include <iostream>

class HumanA {

public:
	HumanA( std::string name, const Weapon& type );
	~HumanA( void );

	void				attack( void ) const;

private:
	const std::string	_name;
	const Weapon&		_weapon;

};

#endif
