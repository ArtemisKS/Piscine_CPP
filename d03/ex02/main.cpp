/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupriia <akupriia@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 18:30:30 by akupriia          #+#    #+#             */
/*   Updated: 2018/10/05 18:30:31 by akupriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>

int		main(void)
{

	ClapTrap ctrap1;
	ClapTrap ctrap2("Jack");

	FragTrap ftrap1;
	FragTrap ftrap2("Bill");

	ScavTrap strap1;
	ScavTrap strap2("Bad guy");

	FragTrap Jack;
	Jack.beRepaired(10);
	std::cout << Jack.getHp() << std::endl;
	Jack.takeDamage(100);
	std::cout << Jack.getHp() << std::endl;
	Jack.beRepaired(10);
	std::cout << Jack.getHp() << std::endl;
	Jack.meleeAttack("sokura");
	Jack.rangedAttack("sokura");
	Jack.vaulthunter_dot_exe("Baddass");
	Jack.vaulthunter_dot_exe("bad guy");
	Jack.vaulthunter_dot_exe("himself");
	Jack.vaulthunter_dot_exe("Someone");
	Jack.vaulthunter_dot_exe("Nobody");
	Jack.vaulthunter_dot_exe("Sub-zero");
	ScavTrap Destroyer;
	Destroyer.beRepaired(10);
	std::cout << Destroyer.getHp() << std::endl;
	Destroyer.takeDamage(100);
	std::cout << Destroyer.getHp() << std::endl;
	Destroyer.beRepaired(10);
	std::cout << Destroyer.getHp() << std::endl;
	Destroyer.meleeAttack("sokura");
	Destroyer.rangedAttack("sokura");
	Destroyer.challengeNewcomer();
	Destroyer.challengeNewcomer();
	Destroyer.challengeNewcomer();
	Destroyer.challengeNewcomer();
	Destroyer.challengeNewcomer();
	Destroyer.challengeNewcomer();
	return (0);
}
