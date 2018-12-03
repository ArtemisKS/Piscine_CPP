/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupriia <akupriia@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 18:26:52 by akupriia          #+#    #+#             */
/*   Updated: 2018/10/05 18:26:54 by akupriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include <iostream>

class	FragTrap {

public:
	FragTrap(void);
	FragTrap(std::string name);
	FragTrap(const FragTrap & fixed);
	~FragTrap(void);
	FragTrap & operator=(FragTrap const & rhs);
	void		rangedAttack(std::string const & target);
	void		meleeAttack(std::string const & target);
	void		takeDamage(unsigned int amount);
	void		beRepaired(unsigned int amount);
	std::string	getName(void) const;
	int         getHp(void);
	void		vaulthunter_dot_exe(std::string const & target);
	int			getRandomNum(void);
private:

	int			_hitPoints;
	int			_maxHitPoints;
	int			_energyPoints;
	int			_maxEnergyPoints;
	int			_level;
	std::string	_name;
	const int	_armorDamageReduction;
	int			_meleeAttackDmg;
	int			_rangedAttackDmg;
	
	static int randomizer;
};

#endif
