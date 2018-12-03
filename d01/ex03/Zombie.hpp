/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupriia <akupriia@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 21:30:52 by akupriia          #+#    #+#             */
/*   Updated: 2018/10/03 21:12:59 by akupriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Zombie_hpp
#define Zombie_hpp

#include <iostream>

class Zombie {

public:

	Zombie( void );
	Zombie( std::string name, std::string type );
	~Zombie( void );

	void		setName( std::string name );
	void		setType( std::string type );
	void		announce( void );

private:
	std::string	_name;
	std::string _type;

};

#endif
