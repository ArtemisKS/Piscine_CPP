/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupriia <akupriia@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 21:33:16 by akupriia          #+#    #+#             */
/*   Updated: 2018/10/02 21:33:17 by akupriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Weapon_hpp
#define Weapon_hpp

#include <string>

class Weapon {

public:
	Weapon( std::string type_ );
	~Weapon( void );

	const std::string&	getType( void ) const;
	void				setType( std::string type_ );

private:
	std::string			type;

};

#endif
