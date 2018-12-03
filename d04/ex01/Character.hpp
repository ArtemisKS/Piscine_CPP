/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupriia <akupriia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 22:06:46 by akupriia          #+#    #+#             */
/*   Updated: 2018/06/22 22:06:48 by akupriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "AWeapon.hpp"
# include "Enemy.hpp"
# include <string>

class Character
{
public:
	Character( void );
	Character( Character const & character );
	Character( std::string const & name );
	~Character( void );

	Character&operator=( Character const & character );

	void			recoverAP( void );
	void			equip( AWeapon* weapon );
	void			attack( Enemy* enemy );
	std::string		getName( void ) const;
	int				getAP( void ) const;
	AWeapon*		getWeapon( void ) const;

private:
	std::string		_name;
	int				_ap;
	AWeapon			*_weapon;
};

std::ostream &	operator<<( std::ostream&o, Character const & character );

#endif
