/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupriia <akupriia@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 18:34:38 by akupriia          #+#    #+#             */
/*   Updated: 2018/10/05 18:34:40 by akupriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class	FragTrap : virtual public ClapTrap{

public:
	FragTrap(void);
	FragTrap(std::string name);
	FragTrap(const FragTrap & fixed);
	~FragTrap(void);
	FragTrap & operator=(FragTrap const & rhs);
	void		rangedAttack(std::string const & target);
	void		meleeAttack(std::string const & target);
	void		vaulthunter_dot_exe(std::string const & target);
//	virtual 	int         getHp(void)const;
};

#endif
