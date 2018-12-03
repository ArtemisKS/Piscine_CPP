/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupriia <akupriia@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 18:34:13 by akupriia          #+#    #+#             */
/*   Updated: 2018/10/05 18:40:05 by akupriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : 
_hitPoints(100),
_maxHitPoints(100),
_energyPoints(100),
_maxEnergyPoints(100),
_level(1),
_name(name),
_armorDamageReduction(0),
_meleeAttackDmg(30),
_rangedAttackDmg(20)
{
	std::string born[3] = {"Claptrap -- start bootup sequence!" , "New ClapTrap",\
	"Check new CrapTrap! Oops."};
	std::cout << "\033[0;32m" << born[this->getRandomNum() % 3] << "\033[0;0m" << std::endl;
	return ;
}

ClapTrap::ClapTrap(void) :
_hitPoints(100),
_maxHitPoints(100),
_energyPoints(100),
_maxEnergyPoints(100),
_level(1),
_name("clap"),
_armorDamageReduction(0),
_meleeAttackDmg(30),
_rangedAttackDmg(20)

{
	std::string born[3] = {"Claptrap -- start bootup sequence!" , "New ClapTrap",\
	"Check new CrapTrap! Oops."};
	std::cout << "\033[0;32m" << born[this->getRandomNum() % 3] << "\033[0;0m" << std::endl;
	return ;
}

ClapTrap::ClapTrap(const ClapTrap & fragtrap) {
	*this = fragtrap;
	return ;
}

ClapTrap::~ClapTrap(void) {
	std::string dead[3] = {"CP:Bye Traveller!" , "I am the dead Clap. Yeah, I am the dead Clap"\
	, "Dead Clap is here! No more sunshine and machine oil"};
	std::cout << "\033[0;31m" << dead[this->getRandomNum() % 3] << "\033[0m" << std::endl;
	return ;
}

ClapTrap&		ClapTrap::operator=(ClapTrap const & ft) {
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

void			ClapTrap::takeDamage(unsigned int amount) {
	this->_hitPoints -= (amount - this->_armorDamageReduction);
	if (this->_hitPoints < 0)
		this->_hitPoints = 0;
}

void			ClapTrap::beRepaired(unsigned int amount) {
	std::string health[3] = {"Good as new, I think. Am I leaking?", "Health over here!", "I found health!"};
	std::cout << health[this->getRandomNum() % 3] << std::endl;
	this->_hitPoints += amount;
	if (this->_hitPoints > 100)
		this->_hitPoints = this->_maxHitPoints;
}

std::string		ClapTrap::getName(void) const{
	return this->_name;
}

int				ClapTrap::getMaxHp(void) const{
	return this->_maxHitPoints;
}


int				ClapTrap::getHp(void) const{
	return this->_hitPoints;
}

int				ClapTrap::getEnergy(void) const{
	return this->_energyPoints;
}

int				ClapTrap::getMaxEnergy(void) const{
	return this->_maxEnergyPoints;
}

int				ClapTrap::getRangedAttack(void) const{
	return this->_rangedAttackDmg;
}

int				ClapTrap::getMeleeAttack(void) const{
	return this->_meleeAttackDmg;
}


int				ClapTrap::getArmorRed(void) const{
	return this->_armorDamageReduction;
}

void			ClapTrap::setName(std::string name) {
	this->_name = name;
}

void			ClapTrap::setHp(unsigned int hp) {
	this->_hitPoints = (hp <= 100) ? hp : 100;
}

void			ClapTrap::addEnergy(unsigned int en) {
	if ((this->_energyPoints + en) > (unsigned int)this->_maxEnergyPoints)
		this->_energyPoints = this->_maxEnergyPoints;
	else
		this->_energyPoints += en;
}

void			ClapTrap::subEnergy(unsigned int en) {
	if ((this->_energyPoints - (int)en) < 0)
		this->_energyPoints = 0;
	else
		this->_energyPoints -= en;
}


int		ClapTrap::getRandomNum(void) {
	static int randomizer = 0;
	std::srand(std::time(0));
	randomizer += 1;
	return (std::rand() + randomizer);
}
