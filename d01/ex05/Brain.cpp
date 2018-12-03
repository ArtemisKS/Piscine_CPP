/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupriia <akupriia@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 21:31:18 by akupriia          #+#    #+#             */
/*   Updated: 2018/10/02 21:31:19 by akupriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain( bool isSmart ) : _isSmart(isSmart)
{
	if (_isSmart || !_isSmart)
		_addres << this;
}

Brain::~Brain( void )
{
	return ;
}



std::string			Brain::identify( void ) const
{
	return _addres.str();
}
