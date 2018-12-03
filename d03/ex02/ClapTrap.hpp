/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupriia <akupriia@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 18:30:12 by akupriia          #+#    #+#             */
/*   Updated: 2018/10/05 18:30:13 by akupriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class	ClapTrap {

public:
	ClapTrap(void);
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap & fixed);
	~ClapTrap(void);
	ClapTrap & operator=(ClapTrap const & rhs);
	void		takeDamage(unsigned int amount);
	void		beRepaired(unsigned int amount);
	std::string	getName(void) const;
	int         getHp(void)const;
	int			getMaxHp(void)const;
	void		setName(std::string name);
	void        setHp(unsigned int hp);
	int			getRandomNum(void);
protected:

	int			_hitPoints;
	int			_maxHitPoints;
	int			_energyPoints;
	int			_maxEnergyPoints;
	int			_level;
	std::string	_name;
	int			_armorDamageReduction;
	int			_meleeAttackDmg;
	int			_rangedAttackDmg;
};

#endif
