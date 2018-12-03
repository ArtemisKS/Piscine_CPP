/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupriia <akupriia@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 18:30:38 by akupriia          #+#    #+#             */
/*   Updated: 2018/10/05 18:30:39 by akupriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) {
	std::string born[3] = {"ST:Greetings Traveller!" , "ST:I am the best robot. Yeah, yeah, yeah, I am the best robot. Ooh, ooh, here we go!",  "ST:I'm over here!"};
	std::cout << born[this->getRandomNum() % 3] << std::endl;
	this->_armorDamageReduction = 3;
    this->setName(name);
	this->_hitPoints = 100;
	this->_maxHitPoints = 100;
	this->_energyPoints = 50;
	this->_maxEnergyPoints = 50;
	this->_level = 1;
	this->_meleeAttackDmg = 20;
	this->_rangedAttackDmg = 15;
	return ;
}

ScavTrap::ScavTrap(void) {
	std::string born[3] = {"Greetings Traveller!" , "I am the best robot. Yeah, yeah, yeah, I am the best robot. Ooh, ooh, here we go!",  "I'm over here!"};
	std::cout << born[this->getRandomNum() % 3] << std::endl;
	this->_armorDamageReduction = 5;
    this->setName("Scav");
	this->_hitPoints = 100;
	this->_maxHitPoints = 100;
	this->_energyPoints = 50;
	this->_maxEnergyPoints = 50;
	this->_level = 1;
	this->_meleeAttackDmg = 20;
	this->_rangedAttackDmg = 15;
	return ;
}

ScavTrap::ScavTrap(const ScavTrap & st) {
	*this = st;
	return ;
}

ScavTrap::~ScavTrap(void) {
	std::string dead[3] = {"ST:Bye Traveller!" , "ST:I am the dead robot. Yeah, yeah, yeah, I am the dead robot"\
	, "ST:I'm dead here!"};
	std::cout << dead[this->getRandomNum() % 3] << std::endl;
	return ;
}

ScavTrap&		ScavTrap::operator=(ScavTrap const & ft) {
	this->_name = ft.getName();
    this->_armorDamageReduction = ft._armorDamageReduction;
    this->_name = ft.getName();
    this->_hitPoints = ft.getHp();
    this->_maxHitPoints = ft.getMaxHp();
    this->_energyPoints = ft._energyPoints;
    this->_maxEnergyPoints = ft._maxEnergyPoints;
    this->_level = 1;
    this->_meleeAttackDmg = ft._meleeAttackDmg;
    this->_rangedAttackDmg = ft._rangedAttackDmg;
    return *this;
}
void			ScavTrap::rangedAttack(std::string const & target) {

	std::string attack[4] = {"Tu!", "Piu-piu!", "Fatality!", "ha-ha!"};
	std::cout << attack[this->getRandomNum() % 4];
	std::cout << " SCV-TP " << this->_name << "attacks " << target \
			  << " at range causing " << this->_rangedAttackDmg << " points of damage !" \
			  << " And then danced!" << std::endl;
}

void        ScavTrap::challengeNewcomer(void) {
	if (this->_energyPoints - 25 < 0)
	{
		std::cout << "Need more energy!" << std::endl;
		return ;
	}
	this->_energyPoints -= 25;	
	std::string challenges[5] = {"First: collect a few brown rocks for me. Then, defeat a badass skag"\
	, "bring me the head of the Destroyer of Worlds, and THEN YOU SHALL DANCE FOR MY ENJOYMENT!"\
	, "pilfer the lost staff of Mount Schuler!"\
	, "Go and sleep for the glory of Mighty God!"\
	, "Stand in the corrosive ooze for thirty seconds without falling into Fight for Your Life"};
	std::cout << "SCV-TP " << this->_name << " challenge: " << challenges[this->getRandomNum() % 5]\
			  << std::endl;
}

void			ScavTrap::meleeAttack(std::string const & target) {
	std::string attack[4] = {"You got it!", "Yeeeee!", "Jeronimo!", "Plu!"};
	std::cout << attack[this->getRandomNum() % 4];
	std::cout << " SCV-TP " << this->_name << "attacks " << target \
	<< " at melee causing " << this->_meleeAttackDmg << " points of damage !" \
	<< " And then danced!" << std::endl;
}
