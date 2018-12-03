/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupriia <akupriia@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 21:31:04 by akupriia          #+#    #+#             */
/*   Updated: 2018/10/03 21:13:03 by akupriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZombieHorde_hpp
#define ZombieHorde_hpp

#include "Zombie.hpp"
#include <cstdlib>

class ZombieHorde {

public:
	ZombieHorde( int N );
	~ZombieHorde( void );

	void			announce( void );

private:
	int			_numberOfZombies;
	Zombie*		_zombies;

	std::string		makeRandomString( bool startFromCapital );

};

#endif
