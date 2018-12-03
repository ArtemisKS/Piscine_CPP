/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupriia <akupriia@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 18:30:18 by akupriia          #+#    #+#             */
/*   Updated: 2018/10/05 18:30:19 by akupriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) {
	std::string born[3] = {"FT:Let's get this party started!", "FT:Recompiling my combat code!",
   "FT:Hey everybody! Check out my package!"};
	std::cout << born[this->getRandomNum() % 3] << std::endl;
	this->_armorDamageReduction = 5;
	this->setName(name);
	this->_hitPoints = 100;
	this->_maxHitPoints = 100;
	this->_energyPoints = 100;
	this->_maxEnergyPoints = 100;
	this->_level = 1;
	this->_meleeAttackDmg = 30;
	this->_rangedAttackDmg = 20;
	return ;
}

FragTrap::FragTrap(void) {
	std::string born[3] = {"FT:Let's get this party started!", "FT:Recompiling my combat code!",
   "FT:Hey everybody! Check out my package!"};
	std::cout << born[this->getRandomNum() % 3] << std::endl;
	this->_armorDamageReduction = 5;
	this->setName("Good");
	this->_hitPoints = 100;
	this->_maxHitPoints = 100;
	this->_energyPoints = 100;
	this->_maxEnergyPoints = 100;
	this->_level = 1;
	this->_meleeAttackDmg = 30;
	this->_rangedAttackDmg = 20;
	return ;
}

FragTrap::FragTrap(const FragTrap & fragtrap){
	*this = fragtrap;
	return ;
}

FragTrap::~FragTrap(void) {
	std::string born[4] = {"You got me!", "Argh arghargh death gurgle gurglegurgle urgh... death.",
   "No fair! I wasn't ready.", "I'll get you next time!"};
	std::cout << born[this->getRandomNum() % 4] << std::endl;
	return ;
}

FragTrap&		FragTrap::operator=(FragTrap const & ft) {
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

void			FragTrap::rangedAttack(std::string const & target) {

	std::string attack[4] = {"Hyah!", "Heyyah!", "Take that!", "Bop!"};
	std::cout << attack[this->getRandomNum() % 4];
	std::cout << " FR4G-TP " << this->_name << "attacks " << target \
	<< " at range causing " << this->_rangedAttackDmg << " points of damage !" << std::endl;
}

void        FragTrap::vaulthunter_dot_exe(std::string const & target) {
	if (this->_energyPoints - 25 < 0)
	{
		std::cout << "Who needs ammo anyway, am I right?" << std::endl;
		return ;
	}
	this->_energyPoints -= 25;	
	std::string attack[5] = {"Eat bomb, baddie!", "Freezy peezy!", "Pull pin, throw!", \
	"Frozen and doh-zen.", "Bad guy go boom!"};
	std::cout << attack[this->getRandomNum() % 5];
	std::cout << " FR4G-TP " << this->_name << "attacks " << target << std::endl;
}

void			FragTrap::meleeAttack(std::string const & target) {
	std::cout << "FR4G-TP " << this->_name << "attacks " << target \
	<< " at melee causing " << this->_meleeAttackDmg << " points of damage !" << std::endl;
}
