/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupriia <akupriia@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 18:35:24 by akupriia          #+#    #+#             */
/*   Updated: 2018/10/05 18:36:01 by akupriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUPERTRAP_HPP
# define SUPERTRAP_HPP

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "NinjaTrap.hpp"

class	SuperTrap : public NinjaTrap, public FragTrap{

public:
	SuperTrap(void);
	SuperTrap(std::string name);
	SuperTrap(const SuperTrap & clap);
	~SuperTrap(void);
	SuperTrap & operator=(SuperTrap const & scav);
	void		rangedAttack(std::string const & target);
	void		meleeAttack(std::string const & target);
	void		ninjaShoeBox(ClapTrap & claptrap);
	void		ninjaShoeBox(FragTrap & fragtrap);
	void		ninjaShoeBox(SuperTrap & fragtrap);
	void		ninjaShoeBox(ScavTrap & fragtrap);
};

#endif
