/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupriia <akupriia@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 18:35:17 by akupriia          #+#    #+#             */
/*   Updated: 2018/10/05 18:35:18 by akupriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SuperTrap.hpp"
#include "FragTrap.hpp"
#include "NinjaTrap.hpp"
#include "ClapTrap.hpp"

SuperTrap::SuperTrap(std::string name) :  NinjaTrap(name), FragTrap(name){
	std::string born[3] = {"ST:Give us open ports for remote access or give us death!" , "ST: Viva La SuperTrap!",  "ST:Got trapped!"};
	std::cout << born[this->getRandomNum() % 3] << std::endl;
    this->_hitPoints = 100;
    this->_maxHitPoints = 100;
    this->_energyPoints = 120;
    this->_maxEnergyPoints =  120;
    this->_level = 1;
    this->setName(name);
	this->_armorDamageReduction = 5;
    this->_meleeAttackDmg = 60;
    this->_rangedAttackDmg = 20;
	return ;
}

SuperTrap::SuperTrap(void) : NinjaTrap(), FragTrap(){
	std::string born[3] = {"ST:Give us open ports for remote access or give us death!" , "ST: Viva La SuperTrap!",  "ST:Got trapped!"};
	std::cout << born[this->getRandomNum() % 3] << std::endl;
	this->_armorDamageReduction = 5;
    this->setName("SuperBot");
    this->_hitPoints = 100;
    this->_maxHitPoints = 100;
    this->_energyPoints = 120;
    this->_maxEnergyPoints =  120;
    this->_level = 1;
    this->_meleeAttackDmg = 60;
    this->_rangedAttackDmg = 20;
	return ;
}

SuperTrap::SuperTrap(const SuperTrap & st) {
	*this = st;
	return ;
}

SuperTrap::~SuperTrap(void) {
	std::string dead[3] = {"NT:I'm afraid. My mind is going. I can feel it. My mind is going! " , "NT:I am afraid i am dead robot ninja." \
	, "NT:See you in the robotic hell!"};
	std::cout << dead[this->getRandomNum() % 3] << std::endl;
	return ;
}

SuperTrap&		SuperTrap::operator=(SuperTrap const & ft) {
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
void			SuperTrap::rangedAttack(std::string const & target) {
	FragTrap::rangedAttack(target);	
}
void			SuperTrap::meleeAttack(std::string const & target) {
	NinjaTrap::meleeAttack(target);
}
