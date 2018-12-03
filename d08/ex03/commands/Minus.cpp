/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Minus.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupriia <akupriia@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 16:19:35 by akupriia          #+#    #+#             */
/*   Updated: 2018/10/12 16:19:37 by akupriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minus.hpp"

Minus::Minus( void ) {}
Minus::Minus( std::list<int>::iterator &it ) : _it(&it) {}
Minus::Minus( const Minus &toCopy ) { *this = toCopy; }
Minus::~Minus( void ) {}
Minus		&Minus::operator=( const Minus &toCopy )
{
	static_cast<void>(toCopy);
	return *this;
}



void			Minus::exec( void )
{
	(**_it)--;
}
