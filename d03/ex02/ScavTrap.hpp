/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupriia <akupriia@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 18:30:44 by akupriia          #+#    #+#             */
/*   Updated: 2018/10/05 18:30:45 by akupriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class	ScavTrap : public ClapTrap{

public:
	ScavTrap(void);
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap & clap);
	~ScavTrap(void);
	ScavTrap & operator=(ScavTrap const & scav);
	void		rangedAttack(std::string const & target);
	void		meleeAttack(std::string const & target);
	void		challengeNewcomer(void);
};

#endif
