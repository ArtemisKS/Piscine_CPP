/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupriia <akupriia@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 21:29:55 by akupriia          #+#    #+#             */
/*   Updated: 2018/10/05 11:10:21 by akupriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieEvent.hpp"

int		main( void )
{
	ZombieEvent		ZombieEvent;
	Zombie			Foo("Foo", "beer");
	Zombie*			Karl = ZombieEvent.newZombie("Karl", "killer");

	ZombieEvent.setZombieType( &Foo, "bar");
	Foo.announce();
	Karl->announce();
	ZombieEvent.randomChump();
	ZombieEvent.randomChump();
	ZombieEvent.randomChump();

	delete Karl;

	system("leaks -q a.out");
	return 0;
}
