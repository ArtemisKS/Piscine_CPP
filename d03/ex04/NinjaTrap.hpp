/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupriia <akupriia@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 18:34:56 by akupriia          #+#    #+#             */
/*   Updated: 2018/10/05 18:34:58 by akupriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NINJATRAP_HPP
# define NINJATRAP_HPP

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class	NinjaTrap : virtual public ClapTrap{

public:
	NinjaTrap(void);
	NinjaTrap(std::string name);
	NinjaTrap(const NinjaTrap & clap);
	~NinjaTrap(void);
	NinjaTrap & operator=(NinjaTrap const & scav);
	void		rangedAttack(std::string const & target);
	void		meleeAttack(std::string const & target);
	void		ninjaShoeBox(ClapTrap & claptrap);
	void		ninjaShoeBox(FragTrap & fragtrap);
	void		ninjaShoeBox(NinjaTrap & fragtrap);
	void		ninjaShoeBox(ScavTrap & fragtrap);
};

#endif
