/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupriia <akupriia@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 21:31:39 by akupriia          #+#    #+#             */
/*   Updated: 2018/10/02 21:31:40 by akupriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Human_hpp
#define Human_hpp

#include "Brain.hpp"

class Human {

public:
	Human( void );
	~Human( void );

	std::string			identify( void ) const;
	const Brain&		getBrain( void ) const;

private:
	const Brain			_brain;

};

#endif
