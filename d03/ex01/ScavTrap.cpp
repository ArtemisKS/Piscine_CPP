/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupriia <akupriia@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 18:29:44 by akupriia          #+#    #+#             */
/*   Updated: 2018/10/05 18:29:44 by akupriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : _name(name), _armorDamageReduction(3){
	std::string born[3] = {"Greetings oh the darkside!" , "I am the bad robot.\
 Yeah, yeah, yeah, I am the bad robot!",  "I'm over here!"};
	std::cout << born[this->getRandomNum() % 3] << std::endl;
	this->_hitPoints = 100;
	this->_maxHitPoints = 100;
	this->_energyPoints = 50;
	this->_maxEnergyPoints = 50;
	this->_level = 1;
	this->_meleeAttackDmg = 20;
	this->_rangedAttackDmg = 15;
	return ;
}

ScavTrap::ScavTrap(void) : _name("Scav"), _armorDamageReduction(3){
	std::string born[3] = {"Greetings oh the darkside!" , "I am the bad robot.\
 Yeah, yeah, yeah, I am the bad robot!",  "I'm over here!"};
	std::cout << born[this->getRandomNum() % 3] << std::endl;

	this->_hitPoints = 100;
	this->_maxHitPoints = 100;
	this->_energyPoints = 50;
	this->_maxEnergyPoints = 50;
	this->_level = 1;
	this->_meleeAttackDmg = 20;
	this->_rangedAttackDmg = 15;
	return ;
}

ScavTrap::ScavTrap(const ScavTrap & fragtrap) : _armorDamageReduction(3){
	*this = fragtrap;
	return ;
}

ScavTrap::~ScavTrap(void) {
	std::string dead[3] = {"Bye Darksider!" , "I am the dead robot. Yeah, yeah, yeah, I am the dead robot"\
	, "I'm dead here!"};
	std::cout << dead[this->getRandomNum() % 3] << std::endl;
	return ;
}

ScavTrap&		ScavTrap::operator=(ScavTrap const & ft) {
	this->_name = ft.getName();
	return *this;
}

void			ScavTrap::takeDamage(unsigned int amount) {
	this->_hitPoints -= (amount - this->_armorDamageReduction);
	if (this->_hitPoints < 0)
		this->_hitPoints = 0;
}

void			ScavTrap::beRepaired(unsigned int amount) {
	std::string health[3] = {"Good as new, I think. Am I leaking?", "Health over here!", "I found health!"};
	std::cout << health[this->getRandomNum() % 3] << std::endl;
	this->_hitPoints += amount;
	if (this->_hitPoints > 100)
		this->_hitPoints = this->_maxHitPoints;
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

std::string		ScavTrap::getName(void) const{
	return this->_name;
}

int				ScavTrap::getHp(void) {
	return this->_hitPoints;
}

int		ScavTrap::getRandomNum(void) {
	std::srand(std::time(0));
	ScavTrap::randomizer += 1;
	return (std::rand() + ScavTrap::randomizer);

}

int ScavTrap::randomizer = 0;
