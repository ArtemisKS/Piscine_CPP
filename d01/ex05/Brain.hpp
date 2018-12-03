/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupriia <akupriia@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 21:31:24 by akupriia          #+#    #+#             */
/*   Updated: 2018/10/02 21:31:25 by akupriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Brain_hpp
#define Brain_hpp

#include <string>
#include <sstream>

class Brain {

public:
	Brain( bool isSmart = false );
	~Brain( void );

	std::string		identify( void ) const;

private:
	bool				_isSmart;
	std::stringstream	_addres;

};

#endif
