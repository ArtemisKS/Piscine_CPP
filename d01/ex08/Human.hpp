/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupriia <akupriia@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 21:34:21 by akupriia          #+#    #+#             */
/*   Updated: 2018/10/02 21:34:22 by akupriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Human_hpp
#define Human_hpp

#include <string>
#include <iostream>

class Human {

public:
	Human( void );
	~Human( void );

	void		action(std::string const & action_name, std::string const & target);

private:
	void		meleeAttack(std::string const & target);
	void		rangedAttack(std::string const & target);
	void		intimidatingShout(std::string const & target);

};

#endif
