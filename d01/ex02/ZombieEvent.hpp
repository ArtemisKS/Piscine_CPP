/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupriia <akupriia@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 21:30:28 by akupriia          #+#    #+#             */
/*   Updated: 2018/10/02 21:30:30 by akupriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZombieEvent_hpp
#define ZombieEvent_hpp

#include "Zombie.hpp"
#include <cstdlib>

class ZombieEvent {

public:
	ZombieEvent( void );
	~ZombieEvent( void );

	void			setZombieType( Zombie* theZombie, std::string type );
	Zombie*			newZombie( std::string name, std::string type );
	void			randomChump( void );

private:
	std::string		makeRandomString( bool startFromCapital );

};

#endif
