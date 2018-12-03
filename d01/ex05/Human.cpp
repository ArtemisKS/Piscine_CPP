/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupriia <akupriia@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 21:31:30 by akupriia          #+#    #+#             */
/*   Updated: 2018/10/02 21:31:32 by akupriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"

Human::Human( void )
{
	return ;
}

Human::~Human( void )
{
	return ;
}



std::string			Human::identify( void ) const
{
	return _brain.identify();
}

const Brain&		Human::getBrain( void ) const
{
	return _brain;
}
