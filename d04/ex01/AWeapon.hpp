/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWeapon.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupriia <akupriia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 22:05:45 by akupriia          #+#    #+#             */
/*   Updated: 2018/06/22 22:05:57 by akupriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AWEAPON_HPP
# define AWEAPON_HPP

# include <string>

class AWeapon
{
protected:
	std::string	_name;
	int			_apcost;
	int			_damage;
	AWeapon( void );

public:
	AWeapon( std::string const & name, int apcost, int damage );
	AWeapon( AWeapon const &weapon );
	virtual ~AWeapon( void );
	AWeapon		& operator=(AWeapon const & right);


	std::string	getName( void ) const;
	int			getAPCost( void ) const;
	int			getDamage( void ) const;

	virtual void attack( void ) const = 0;

};

#endif
