/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupriia <akupriia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 22:07:05 by akupriia          #+#    #+#             */
/*   Updated: 2018/06/22 22:21:54 by akupriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "AWeapon.hpp"
#include "Enemy.hpp"
#include "PlasmaRifle.hpp"
#include "PowerFist.hpp"
#include "Character.hpp"
#include "RadScorpion.hpp"
#include "SuperMutant.hpp"

int main( void )
{
	Character* zaz = new Character("zaz");
	std::cout << *zaz;
	Enemy* b = new RadScorpion();
	AWeapon* pr = new PlasmaRifle();
	AWeapon* pf = new PowerFist();
	zaz->equip(pr);
	std::cout << *zaz;
	zaz->equip(pf);
	zaz->attack(b);
	std::cout << *zaz;
	zaz->equip(pr);
	std::cout << *zaz;
	zaz->attack(b);
	std::cout << *zaz;
	zaz->attack(b);
	std::cout << *zaz;
	Enemy* m = new SuperMutant();
	zaz->attack(m);
	std::cout << *zaz;
	zaz->equip(pf);
	std::cout << *zaz;
	zaz->attack(m);
	std::cout << *zaz;
	zaz->attack(m);
	std::cout << *zaz;
    zaz->recoverAP();
    zaz->recoverAP();
	std::cout << *zaz;
	zaz->attack(m);
	std::cout << *zaz;
    zaz->attack(m);
	std::cout << *zaz;
	return 0;
}
