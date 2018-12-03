/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupriia <akupriia@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 18:34:51 by akupriia          #+#    #+#             */
/*   Updated: 2018/10/05 18:34:52 by akupriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NinjaTrap.hpp"

NinjaTrap::NinjaTrap(std::string name) {
	std::string born[3] = {"NT:Give us open ports for remote access or give us death!" , "NT: Viva La Robolution!",  "NT:Shoryuken!"};
	std::cout << born[this->getRandomNum() % 3] << std::endl;
	this->_armorDamageReduction = 0;
    this->setName(name);
	this->_hitPoints = 60;
	this->_maxHitPoints = 60;
	this->_energyPoints = 120;
	this->_maxEnergyPoints = 120;
	this->_level = 1;
	this->_meleeAttackDmg = 60;
	this->_rangedAttackDmg = 5;
	return ;
}

NinjaTrap::NinjaTrap(void) {
	std::string born[3] = {"NT:Give us open ports for remote access or give us death!" , "NT: Viva La Robolution!",  "NT:Shoryuken!"};
	std::cout << born[this->getRandomNum() % 3] << std::endl;
	this->_armorDamageReduction = 0;
    this->setName("NinjaBot");
	this->_hitPoints = 600;
	this->_maxHitPoints = 60;
	this->_energyPoints = 120;
	this->_maxEnergyPoints = 120;
	this->_level = 1;
	this->_meleeAttackDmg = 60;
	this->_rangedAttackDmg = 5;
	return ;
}

NinjaTrap::NinjaTrap(const NinjaTrap & st) {
	*this = st;
	return ;
}

NinjaTrap::~NinjaTrap(void) {
	std::string dead[3] = {"NT:I'm afraid. My mind is going. I can feel it. My mind is going! " , "NT:I am afraid i am dead robot ninja." \
	, "NT:See you in the robotic hell!"};
	std::cout << dead[this->getRandomNum() % 3] << std::endl;
	return ;
}

NinjaTrap&		NinjaTrap::operator=(NinjaTrap const & ft) {
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
void			NinjaTrap::rangedAttack(std::string const & target) {

	std::string attack[4] = {"Shouriken!", "Target disassembled", "Brutality!", "..hidden.!"};
	std::cout << attack[this->getRandomNum() % 4];
	std::cout << " NT " << this->_name << "attacks " << target \
			  << " at range causing " << this->_rangedAttackDmg << " points of damage !" \
			  << " And then disappeared!" << std::endl;
}

void        NinjaTrap::ninjaShoeBox(ClapTrap & claptrap) {
	if (this->_energyPoints < 10)
	{
		std::cout << "Ninja needs more energy!" << std::endl;
		return ;
	}
	claptrap.takeDamage(this->_meleeAttackDmg);
	this->subEnergy(10);	
	std::string clapattack[3] = {"Slap Clap", "Trump trap", "Dance"};
	std::cout << "Ninja " << this->_name << " attacks: |" \
			  << claptrap.getName() << "| using "						\
			  << clapattack[this->getRandomNum() % 3]\
			  << " attack and dealing " \
			  << this->_meleeAttackDmg - claptrap.getArmorRed() \
			  << " damage." << std::endl;
	if (claptrap.getHp() == 0)
	{
		std::cout << "\033[0;31mTarget exterminated! Bhhhaha! \033[1;34m+40\033[1;31m energy\033[0m" << std::endl;
		this->addEnergy(40);
	}
}

void        NinjaTrap::ninjaShoeBox(FragTrap & fragtrap) {
	if (this->_energyPoints < 10)
	{
		std::cout << "Ninja needs more energy!" << std::endl;
		return ;
	}
	if (fragtrap.getHp() == 0) {
			std::cout << "He is already dead, but i punch him once more!" << std::endl;
			return;
	}
	fragtrap.takeDamage(this->_meleeAttackDmg);
	this->subEnergy(10);	
	std::string clapattack[3] = {"Grenade!!", "Toothstick", "Starving"};
	std::cout << "Ninja " << this->_name << " attacks: |" \
			  << fragtrap.getName() << "| using "						\
			  << clapattack[this->getRandomNum() % 3]\
			  << " attack and dealing " \
			  << this->_meleeAttackDmg - fragtrap.getArmorRed() \
			  << " damage." << std::endl;
	if (fragtrap.getHp() == 0)
	{
		std::cout << "\033[1;31mFragTrap disassembled. \033[1;34m+50\033[1;31m energy\033[0m" << std::endl;
		this->addEnergy(50);
	}
}


void        NinjaTrap::ninjaShoeBox(NinjaTrap & fragtrap) {
	if (this->_energyPoints < 10)
	{
		std::cout << "Ninja needs more energy!" << std::endl;
		return ;
	}
	if (this == &fragtrap)
	{
		std::cout << "\033[4;31mHARAKIRI.Self disassembling.\033[0m" << std::endl;
		return ;
	}
	if (fragtrap.getHp() == 0) {
			std::cout << "He is already dead, but i punch him once more!" << std::endl;
			return;
	}
	fragtrap.takeDamage(this->_meleeAttackDmg);
	this->subEnergy(10);
	std::string clapattack[3] = {"Friendly kick!", "Not friendly kick", "Punch"};
	std::cout << "Ninja " << this->_name << " attacks neighboor: |" \
			  << fragtrap.getName() << "| using "						\
			  << clapattack[this->getRandomNum() % 3]\
			  << " attack and dealing " \
			  << this->_meleeAttackDmg - fragtrap.getArmorRed() \
			  << " damage." << std::endl;
	if (fragtrap.getHp() == 0)
	{
		std::cout << "Friend disassembled. \033[1;34m-10\033[1;31m energy" << std::endl;
		this->subEnergy(10);
	}
}


void        NinjaTrap::ninjaShoeBox(ScavTrap & fragtrap) {
	if (this->_energyPoints < 5)
	{
		std::cout << "Ninja needs more energy!" << std::endl;
		return ;
	}
	if (fragtrap.getHp() == 0) {
			std::cout << "He is already dead, but i punch him once more!" << std::endl;
			return;
	}
	fragtrap.takeDamage(this->_meleeAttackDmg);
	this->subEnergy(5);	
	std::string clapattack[3] = {"Rembo!", "Rombo!", "Rimbo"};
	std::cout << "Ninja " << this->_name << " attacks: |" \
			  << fragtrap.getName() << "| using "						\
			  << clapattack[this->getRandomNum() % 3]\
			  << " attack and dealing " \
			  << this->_meleeAttackDmg - fragtrap.getArmorRed() \
			  << " damage." << std::endl;
	if (fragtrap.getHp() == 0)
	{
		std::cout << "No more ScavTrap . \033[1;34m+50\033[1;31m energy" << std::endl;
		this->addEnergy(50);
	}
}

void			NinjaTrap::meleeAttack(std::string const & target) {
	std::string attack[4] = {"Heavy one in a face!", "Y!", "Punch punch!", "big *f*kng*attack*!"};
	std::cout << attack[this->getRandomNum() % 4];
	std::cout << " NT " << this->_name << "attacks with " << target \
	<< " at melee causing " << this->_meleeAttackDmg << " points of damage !" \
	<< " And then disappeared!" << std::endl;
}
